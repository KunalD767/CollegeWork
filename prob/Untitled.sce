clear all
disp("Enter the number of observations:")
n = input("");
disp("Enter the value of p:")
p = input("");
disp("Enter the values of X:")
for i = 1:n
    X(1, i) = input("");
end
disp("Enter the number of frequencies:")
for j = 1:n
    F(1, j) = input("");
end
EF = sum(F) * binomial(p, n-1);
disp("Given frequencies:");
disp(F);
disp("Expected frequencies:");
disp(EF);
plot2d(0:n-1, F);
plot2d(0:n-1, EF);

