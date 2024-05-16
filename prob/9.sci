clc;

prices = [1, 2, 3; 8, 5, 4; 3, 1, 6];
demand = [100, 30, 70];
supply = [110, 40, 50];

// Set prices, demand, and supply using evstrx_matrix function
prices = evstr(x_matrix('setprices', prices));
demand = evstr(x_matrix('setdemand', demand));
supply = evstr(x_matrix('submit offer', supply));

LEFT = 1;
RIGHT = 2;
UP = 3;
DOWN = 4;

cntCols = length(prices(1,:));
cntRows = length(prices(:,1));

// Cost function to calculate the total cost
function res = cost(prices, plan)
    res = 0;
    for i = 1:cntRows
        for j = 1:cntCols
            res = res + prices(i,j) * plan(i,j);
        end
    end
endfunction

// Function to find available corners
function [corners, success] = getAvailableCorner(basis, direction, initialpoint, i, j)
    success = 0;
    corners = [];
    currentCorner = 1;
    cntCols = length(basis(1,:));
    cntRows = length(basis(:,1));
    colModificator = 0;
    rowModificator = 0;
    if direction == LEFT then
        colModificator = -1;
    elseif direction == RIGHT then
        colModificator = 1;
    elseif direction == UP then
        rowModificator = -1;
    elseif direction == DOWN then
        rowModificator = 1;
    end

    i = i + rowModificator;
    j = j + colModificator;

    while i ~= 0 & j ~= 0 & i <= cntRows & j <= cntCols
        if basis(i,j) ~= 0 | [i, j] == initialPoint then
            corners(currentCorner,:) = [i, j];
            currentCorner = currentCorner + 1;
            success = 1;
        end
        i = i + rowModificator;
        j = j + colModificator;
    end

    if success == 1 then
        cornersReverse = zeros(size(corners));
        for iter = 1:length(corners(:,1))
            cornersReverse(iter,:) = corners(length(corners(:,1)) - iter + 1, :);
        end
        corners = cornersReverse;
    end
endfunction

// Function to build a cycle
function [nodes, success] = buildCycle(basis, initialpoint, currentpoint, direction)
    success = 0;
    nodes = [];
    possibleDirections = [];

    if initialpoint == currentpoint then
        possibleDirections = [LEFT, RIGHT, UP, DOWN];
    elseif direction == LEFT || direction == RIGHT then
        possibleDirections = [UP, DOWN];
    elseif direction == UP || direction == DOWN then
        possibleDirections = [LEFT, RIGHT];
    end

    for directionIdx = 1:length(possibleDirections)
        [corners, suc] = getAvailableCorner(basis, possibleDirections(directionIdx), initialpoint, currentpoint(1), currentpoint(2));

        if suc == 1 then
            possibleToCloseCycle = 0;
            successWithCorners = 0;

            for cornidx = 1:length(corners(:,1))
                if corners(cornidx,:) == initialpoint then
                    possibleToCloseCycle = 1;
                    continue;
                end

                [subNodes, suc] = buildCycle(basis, initialpoint, corners(cornidx,:), possibleDirections(directionIdx));

                if suc == 1 then
                    successWithCorners = 1;
                    nodeIdx = size(nodes, 1) + 1;
                    nodes(nodeIdx,:) = currentpoint;

                    for subNodeIdx = 1:length(subNodes(:,1))
                        nodeIdx = nodeIdx + 1;
                        nodes(nodeIdx,:) = subNodes(subNodeIdx,:);
                    end

                    if successWithCorners == 1 then
                        success = 1;
                        break;
                    end
                end
            end

            if success == 1 then
                break;
            end
        end
    end
endfunction

// Initialize the plan
plan = zeros(cntRows, cntCols);

// Calculation of the original reference plan using the northwest corner method
tempDemand = demand;
tempSupply = supply;
for i = 1:cntRows
    for j = 1:cntCols
        currentSupply = min(tempDemand(j), tempSupply(i));
        plan(i,j) = currentSupply;
        tempDemand(j) = tempDemand(j) - currentSupply;
        tempSupply(i) = tempSupply(i) - currentSupply;
        if tempDemand(j) == 0 then
            break;
        end
    end
    if tempSupply(i) == 0 then
        break;
    end
end

disp("Initial plan:");
disp(plan);

// Plan optimization
optimal = 0;
UNKNOWN_POTENTIAL = 9999999;
iteration = 0;

while optimal ~= 1
    iteration = iteration + 1;

    // Initialize potentials
    potentialU = zeros(1, cntRows);
    potentialV = UNKNOWN_POTENTIAL * ones(1, cntCols);
    potentialU(1) = 0;
    continuePotentialing = 1;

    // Calculate potentials
    while continuePotentialing == 1
        continuePotentialing = 0;

        // Iterate over columns (customers)
        for j = 1:cntCols
            // Iterate over rows (suppliers)
            for i = 1:cntRows
                if plan(i,j) == 0 then
                    continue;
                end

                if potentialU(i) == UNKNOWN_POTENTIAL && potentialV(j) == UNKNOWN_POTENTIAL then
                    continuePotentialing = 1;
                    continue;
                end

                if potentialU(i) == UNKNOWN_POTENTIAL then
                    potentialU(i) = prices(i,j) - potentialV(j);
                end

                if potentialV(j) == UNKNOWN_POTENTIAL then
                    potentialV(j) = prices(i,j) - potentialU(i);
                end
            end
        end
    end

    // Find the maximum not basis
    maxNB = -1;
    maxI = 0;
    maxJ = 0;

    for j = 1:cntCols
        for i = 1:cntRows
            if plan(i,j) ~= 0 then
                basisValue = potentialU(i) + potentialV(j) - prices(i,j);
                if basisValue > maxNB then
                    maxNB = basisValue;
                    maxI = i;
                    maxJ = j;
                end
            end
        end
    end

    if maxNB <= 0 then
        printf("Iteration %d. The current plan is optimal!\n", iteration);
        optimal = 1;
    else
        [nodes, success] = buildCycle(plan, [maxI, maxJ], [maxI, maxJ], 0);
        if success == 0 then
            disp("Loop building error. Shutdown");
            break;
        end

        // Among the even nodes of the cycle, find the minimum value
        minNode = 99999999;
        for node = 2:2:length(nodes(:,1))
            if minNode > plan(nodes(node, 1), nodes(node, 2)) then
                minNode = plan(nodes(node, 1), nodes(node, 2));
            end
        end

        // Update the plan
        for node = 2:length(nodes(:,1))
            nodeI = nodes(node, 1);
            nodeJ = nodes(node, 2);
            if mod(node, 2) == 0 then
                plan(nodeI, nodeJ) = plan(nodeI, nodeJ) - minNode;
            else
                plan(nodeI, nodeJ) = plan(nodeI, nodeJ) + minNode;
            end
        end

        printf("Iteration %d. Current plan is not optimal. Plan optimization.\n", iteration);
    end
end

disp("Final plan:");
disp(plan);
printf("The cost is %d\n", cost(prices, plan));

// Display the plan as a table
disp("Quantity");
table = cell(cntRows * cntCols, 6);
tableStr = 1;
for i = 1:cntRows
    for j = 1:cntCols
        if plan(i,j) ~= 0 then
            table{tableStr, 1} = "From supplier";
            table{tableStr, 2} = i;
            table{tableStr, 3} = "To the customer";
            table{tableStr, 4} = j;
            table{tableStr, 5} = "Quantity";
            table{tableStr, 6} = plan(i,j);
            tableStr = tableStr + 1;
        end
    end
end

disp(table);
