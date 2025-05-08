A = [2, 1, -1; -3, -1, 2; -2, 1, 2];
b = [8; -11; -3];
n = 3;

for i = 1:n
    for k = i+1:n
        factor = A(k,i)/A(i,i);
        for j = i:n
            A(k,j) = A(k,j) - factor*A(i,j);
        end
        b(k) = b(k) - factor*b(i);
    end
end

x = zeros(n,1);
for i = n:-1:1
    sum = 0;
    for j = i+1:n
        sum = sum + A(i,j)*x(j);
    end
    x(i) = (b(i) - sum)/A(i,i);
end

disp("Solution using Gauss Elimination:");
disp(x);
A = [2, 1, -1, 8; -3, -1, 2, -11; -2, 1, 2, -3];
rows = 3;
cols = 4;

for i = 1:rows
    pivot = A(i,i);
    for j = 1:cols
        A(i,j) = A(i,j) / pivot;
    end
    for k = 1:rows
        if k <> i then
            factor = A(k,i);
            for j = 1:cols
                A(k,j) = A(k,j) - factor * A(i,j);
            end
        end
    end
end

disp("Solution using Gauss-Jordan:");
disp(A(:, cols));
A = [4, 1, 2; 3, 5, 1; 1, 1, 3];
b = [4; 7; 3];
x = [0; 0; 0];
n = 3;
tol = 0.0001;

while %t
    x_old = x;
    for i = 1:n
        sum = 0;
        for j = 1:n
            if j <> i then
                sum = sum + A(i,j)*x(j);
            end
        end
        x(i) = (b(i) - sum)/A(i,i);
    end
    err = max(abs(x - x_old));
    if err < tol then
        break;
    end
end

disp("Solution using Gauss-Seidel:");
disp(x);
