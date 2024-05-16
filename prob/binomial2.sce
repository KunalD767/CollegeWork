clear all
disp("Enter the number of observations:")
n = input("");
disp("Enter the values of X:");
for i = 1:n
    X(1, i) = input("");
end
disp("Enter the number of frequencies:");
for j = 1:n
    F(1, j) = input("");
end
disp("Mean of the distribution is:");
MEA = sum(F.*X) / sum(F);
disp(MEA);
P = MEA / n;
EF = sum(F) * binomial(P,n-1);
disp("Given frequencies:");
disp(F);
disp("Expected frequencies:");
disp(EF);
plot2d3(0:n-1, F);
plot2d(0:n-1, EF);
disp("Gehna Gautam")
disp("35414802722")
