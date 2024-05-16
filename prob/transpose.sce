m=input("Enter the no of rows of matrix");
n=input("ENter the no of columns of matrix");
A=zeros(m,n);
B=zeros(n,m);
disp("ENter the elements of first matrix row wise")
for i=1:m
    for j=1:n
        A(i,j)=input('');
    end
end
for i=1:m
    for j=1:n
        B(j,i)=A(i,j)
    end
end


disp('The first matrix is')
disp(A)
disp('The Transpose matrix is')
disp(B)
disp("Gehna Gautam")
disp("35414802722")
