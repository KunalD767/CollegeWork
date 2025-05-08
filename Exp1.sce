// Matrix A and B
A = [1, 2; 3, 4];
B = [5, 6; 7, 8];
[m, n] = size(A);

// Matrix Addition
C_add = zeros(m, n);
for i = 1:m
    for j = 1:n
        C_add(i, j) = A(i, j) + B(i, j);
    end
end
disp(C_add, "Matrix Addition");

// Matrix Subtraction
C_sub = zeros(m, n);
for i = 1:m
    for j = 1:n
        C_sub(i, j) = A(i, j) - B(i, j);
    end
end
disp(C_sub, "Matrix Subtraction");

// Matrix Multiplication
C_mul = zeros(m, n);
for i = 1:m
    for j = 1:n
        sum = 0;
        for k = 1:n
            sum = sum + A(i, k) * B(k, j);
        end
        C_mul(i, j) = sum;
    end
end
disp(C_mul, "Matrix Multiplication");
