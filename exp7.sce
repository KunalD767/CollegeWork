data = [1 2 2 3 3 3 4 4 4 4 5 5 5 5 5];
n = length(data);
max_val = max(data);
min_val = min(data);
range = max_val - min_val + 1;

freq = zeros(1, range);

for i = 1:n
    index = data(i) - min_val + 1;
    freq(index) = freq(index) + 1;
end

disp("Value  Frequency");
for i = 1:range
    disp([string(min_val + i - 1) + "        " + string(freq(i))]);
end
