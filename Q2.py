#2. Write a python program to compute following computation on matrix
#a. Addition of two matrices
#b. Subtraction of two matrices
#c. Multiplication of two matrices
#d. Transpose of two matrices 

def add(matrix1,matrix2):
    result = []
    for i in range(len(matrix1)):
        row = []
        for j in range(len(matrix1[0])):
            row.append(matrix1[i][j] + matrix2[i][j])
        result.append(row)
    print("Addition of two matrices is:")
    for i in range(len(result)):
        for j in range(len(result[0])):
            print(result[i][j], end=" ")
        print()

def sub(matrix1,matrix2):
    result = []
    for i in range(len(matrix1)):
        row = []
        for j in range(len(matrix1[0])):
            row.append(matrix1[i][j] - matrix2[i][j])
        result.append(row)
    print("Subtraction of two matrices is:")
    for i in range(len(result)):
        for j in range(len(result[0])):
            print(result[i][j], end=" ")
        print()

def multiply(matrix1,matrix2):
    result = []
    for i in range(len(matrix1)):
        row = []
        for j in range(len(matrix2[0])):
            sum = 0
            for k in range(len(matrix2)):
                sum += matrix1[i][k] * matrix2[k][j]
            row.append(sum)
        result.append(row)
    print("Multiplication of two matrices is:")
    for i in range(len(result)):
        for j in range(len(result[0])):
            print(result[i][j], end=" ")
        print()

def transpose(matrix):
    result = []
    for i in range(len(matrix[0])):
        row = []
        for j in range(len(matrix)):
            row.append(matrix[j][i])
        result.append(row)
    print("Transpose of matrix is:")
    for i in range(len(result)):
        for j in range(len(result[0])):
            print(result[i][j], end=" ")
        print()


row = int(input("Enter number of rows  of matrix:"))
col = int(input("Enter number of columns of matrix:"))

print("Enter the elements of first matrix:")
matrix1 = []
for i in range(row):
    a = []
    for j in range(col):
        a.append(int(input()))
    matrix1.append(a)
print("First matrix is:")
for i in range(row):   
    for j in range(col):
        print(matrix1[i][j], end = " ")
    print()

print("Enter the elements of second matrix:")
matrix2 = []
for i in range(row):
    b = []
    for j in range(col):
        b.append(int(input()))
    matrix2.append(b)
print("second matrix is:")
for i in range(row):   
    for j in range(col):
        print(matrix2[i][j], end = " ")
    print()

add(matrix1,matrix2)
sub(matrix1,matrix2)
multiply(matrix1,matrix2)
transpose(matrix1)
transpose(matrix2)
