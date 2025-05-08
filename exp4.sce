A = [1, 2; 3, 4];
B = [5, 6; 7, 8];
C = [2, 0; 1, 2];

AB = zeros(2,2);
BA = zeros(2,2);
for i = 1:2
    for j = 1:2
        for k = 1:2
            AB(i,j) = AB(i,j) + A(i,k)*B(k,j);
            BA(i,j) = BA(i,j) + B(i,k)*A(k,j);
        end
    end
end
disp("A*B:");
disp(AB);
disp("B*A:");
disp(BA);

BC = zeros(2,2);
for i = 1:2
    for j = 1:2
        for k = 1:2
            BC(i,j) = BC(i,j) + B(i,k)*C(k,j);
        end
    end
end

ABC1 = zeros(2,2);
ABC2 = zeros(2,2);
for i = 1:2
    for j = 1:2
        for k = 1:2
            ABC1(i,j) = ABC1(i,j) + AB(i,k)*C(k,j);
            ABC2(i,j) = ABC2(i,j) + A(i,k)*BC(k,j);
        end
    end
end

disp("(A*B)*C:");
disp(ABC1);
disp("A*(B*C):");
disp(ABC2);

B_plus_C = B + C;
A_BplusC = zeros(2,2);
for i = 1:2
    for j = 1:2
        for k = 1:2
            A_BplusC(i,j) = A_BplusC(i,j) + A(i,k)*B_plus_C(k,j);
        end
    end
end
disp("A*(B+C):");
disp(A_BplusC);
