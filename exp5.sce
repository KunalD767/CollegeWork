A = [1, 2, -1, -4; 2, 3, -1, -11; -2, 0, -3, 22];
[m, n] = size(A);
lead = 1;

for r = 1:m
    if n < lead then break; end
    i = r;
    while A(i, lead) == 0
        i = i + 1;
        if i > m then
            i = r;
            lead = lead + 1;
            if n < lead then break; end
        end
    end
    temp = A(r,:);
    A(r,:) = A(i,:);
    A(i,:) = temp;
    lv = A(r, lead);
    A(r,:) = A(r,:) / lv;
    for i = 1:m
        if i <> r then
            lv = A(i, lead);
            A(i,:) = A(i,:) - lv*A(r,:);
        end
    end
    lead = lead + 1;
end

disp("Reduced Row Echelon Form:");
disp(A);
