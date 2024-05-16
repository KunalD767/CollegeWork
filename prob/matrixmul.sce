m=input("Enter the no of rows of first matrix");
n=input("ENter the no of columns of first matrix");
p=input("Enter the no of rows of second matrix");
q=input("ENter the no of columns of second matrix");
if n==p 
    disp('Matrices are conformable for multiplication')
else
   disp('Matrices are not conformable for multiplication')
end

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
for i=1:p
    for j=1:q
        B(i,j)=input('');
    end
end
for i=1:m
    for j=1:q
        for k=1:n
            C(i,j)=C(i,j)+A(i,k)*B(k,j);
        end
    end
end

disp('The first matrix is')
disp(A)
disp('The Second matrix is')
disp(B)
disp('the Multiplied matrix  is')
disp(C)
disp("Gehna Gautam")
disp("35414802722")
