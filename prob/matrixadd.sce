m=input("Enter the no of rows of matrix");
n=input("ENter the no of columns of matrix");
A=zeros(m,n);
B=zeros(m,n);
C=zeros(m,n);
disp("ENter the elements of first matrix row wise")
for i=1:m
    for j=1:n
        A(i,j)=input('');
    end
end
disp("ENter the elements of second matrix row wise")
for i=1:m
    for j=1:n
        B(i,j)=input('');
    end
end
for i=1:m
    for j=1:n
        C(i,j)=A(i,j)+B(i,j);
    end
end

disp('The first matrix is')
disp(A)
disp('The Second matrix is')
disp(B)
disp('the sum is')
disp(C)
disp("Gehna Gautam")
disp("35414802722")
