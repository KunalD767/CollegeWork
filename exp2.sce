A = [2, 1; 1, 3];
x = [1; 1];
tol = 0.0001;
max_iter = 1000;
lambda_old = 0;
n = size(A, 1);
iter = 0;

while iter < max_iter
    iter = iter + 1;
    y = zeros(n, 1);
    for i = 1:n
        for j = 1:n
            y(i) = y(i) + A(i, j) * x(j);
        end
    end
    lambda_new = 0;
    num = 0;
    denom = 0;
    for i = 1:n
        num = num + y(i) * x(i);
        denom = denom + x(i) * x(i);
    end
    lambda_new = num / denom;
    norm_y = 0;
    for i = 1:n
        norm_y = norm_y + y(i)^2;
    end
    norm_y = sqrt(norm_y);
    for i = 1:n
        x(i) = y(i) / norm_y;
    end
    if abs(lambda_new - lambda_old) < tol then
        break;
    end
    lambda_old = lambda_new;
end

disp("Eigenvalues:");
disp(lambda_new);
disp("Eigenvectors:");
disp(x);
