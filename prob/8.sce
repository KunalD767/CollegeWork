clc;
clear;

p = input("Enter number of variables in the objective function: ");
q = input("Enter number of constraint equations: ");

disp('Enter coefficients of the objective function:');
for i = 1:p
    A(i) = input(''); 
end

m = input("Enter 1 to minimize or 2 to maximize: ");

disp('Enter constraint equations:');
for i = 1:q
    disp(['Enter equation ' + string(i) + ':']);
    for j = 1:p
        B(i, j) = input(['Enter coefficient ' + string(j) + ': ']);
    end
    if p > 1 then
        printf("Enter whether you want to maximize or minimize this equation:\nEnter 1 for <=, 2 for >=: ");
        C(i) = input('');
    else
        C(i) = 1;
    end
    printf("Enter constant: ");
    D(i) = input('');
end

printf("\n\nThe LPP is:\n");
if m == 1 then
    printf("MIN\n");
else
    printf("MAX\n");
end

for i = 1:p
    if i ~= p then
        printf("%dx%d + ", A(i), i);
    else
        printf("%dx%d\n", A(i), i);
    end
end

printf("Subject to:\n");
for i = 1:q
    for j = 1:p
        if j ~= p then
            printf("%dx%d + ", B(i, j), j);
        else
            if C(i) == 1 then
                printf("%dx%d <= %d\n", B(i, j), j, D(i));
            else
                printf("%dx%d >= %d\n", B(i, j), j, D(i));
            end
        end
    end
end

printf("\n\nSIMPLEX TABLE:\n\n");

printf("Cj |");
for i = 1:p-1
    printf(" %d ", A(i));
end
for i = 1:q-1
    printf(" 0 ");
end
printf("\n");

printf("BV | Cb Xb |");
for i = 1:p
    printf(" x%d ", i);
end
for i = 1:q
    printf(" s%d ", i);
end
printf(" Min Xb/x\n");

printf("-----------------------------------------\n");

for i = 1:p
    printf(" %d  0 ", D(i));
    for j = 1:q
        printf("%d ", B(i, j));
    end
    for j = 1:q
        if j == i then
            printf("1 ");
        else
            printf("0 ");
        end
    end
    printf("\n");
end

printf("-----------------------------------------\n");

printf(" Zj-Cj |");
for i = 1:p
    printf(" -%d ", A(i));
end
for i = 1:q
    printf(" 0 ");
end
printf("\n");
