clc;
n = input('Enter the number of data points: ');


printf('Enter the values for xi: ');
for i = 1:n
    x(i) = input('');
end


printf('Enter the values for yi: ');
for i = 1:n
    y(i) = input('');
end

sumx = 0;
sumy = 0;
sumxy = 0;
sumx2 = 0;

// Calculate sums
for i = 1:n
    sumx = sumx + x(i);
    sumx2 = sumx2 + x(i)^2;
    sumy = sumy + y(i);
    sumxy = sumxy + x(i)*y(i);
end

// Calculate coefficients
a = ((sumx2*sumy - sumx*sumxy) / (n*sumx2 - sumx^2));
b = ((n*sumxy - sumx*sumy) / (n*sumx2 - sumx^2));

// Display equation
printf('The line is Y = %3.3f + %.3fX\n', a, b);

// Plot
x = 0:2:20;
plot(x, a + b*x);
