data = [4 5 6 5 100 6 5 4 6 5 5 4 6 5 100];
n = length(data);

sum_val = 0;
for i = 1:n
    sum_val = sum_val + data(i);
end
mean_val = sum_val / n;

sum_sq = 0;
for i = 1:n
    sum_sq = sum_sq + (data(i) - mean_val)^2;
end
std_dev = sqrt(sum_sq / (n - 1));

disp("Value  Z-Score   Outlier");
for i = 1:n
    z = (data(i) - mean_val) / std_dev;
    is_outlier = abs(z) > 2;
    disp([string(data(i)) + "      " + string(z) + "     " + string(is_outlier)]);
end
