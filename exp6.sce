x = 0:0.1:10;
y = zeros(1, length(x));
dy = zeros(1, length(x));
d2y = zeros(1, length(x));

for i = 1:length(x)
    y(i) = x(i)^2 + 3*x(i) + 2;
end

for i = 2:length(x)-1
    dy(i) = (y(i+1) - y(i-1)) / (x(i+1) - x(i-1));
    d2y(i) = (y(i+1) - 2*y(i) + y(i-1)) / ((x(i+1) - x(i))^2);
end

disp("Function values:");
disp(y);
disp("First Derivative:");
disp(dy);
disp("Second Derivative:");
disp(d2y);

// Plot original function
scf(0);
plot(x, y);
xtitle("Function f(x) = x^2 + 3x + 2");

scf(1);
plot(x, dy);
xtitle("First Derivative of f(x)");

scf(2);
plot(x, d2y);
xtitle("Second Derivative of f(x)");

