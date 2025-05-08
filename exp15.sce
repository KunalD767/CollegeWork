// Sample dataset
data = [5, 8, 3, 10, 6, 7, 9];
n = length(data);

// ===== Mean =====
sum_val = 0;
for i = 1:n
    sum_val = sum_val + data(i);
end
mean_val = sum_val / n;
disp("Mean:");
disp(mean_val);

// ===== Median =====
// Sort the array (bubble sort for demonstration)
for i = 1:n-1
    for j = 1:n-i
        if data(j) > data(j+1) then
            temp = data(j);
            data(j) = data(j+1);
            data(j+1) = temp;
        end
    end
end

if modulo(n, 2) == 1 then
    median_val = data((n+1)/2);
else
    median_val = (data(n/2) + data(n/2 + 1)) / 2;
end
disp("Median:");
disp(median_val);

// ===== Variance =====
var_sum = 0;
for i = 1:n
    var_sum = var_sum + (data(i) - mean_val)^2;
end
variance = var_sum / n;
disp("Variance:");
disp(variance);

// ===== Standard Deviation =====
std_dev = sqrt(variance);
disp("Standard Deviation:");
disp(std_dev);
