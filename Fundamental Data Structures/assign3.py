
def add(matrix1, matrix2):
    if(len(matrix1) != len(matrix2) or len(matrix1[0]) != len(matrix2[0])):
        print("Addition not possible.")
        return
    
    ans = []
    for i in range(len(matrix1)):
        r = []
        for j in range(len(matrix1[0])):
            r.append(matrix1[i][j] + matrix2[i][j])
        ans.append(r)
    display(ans, "Addition: ")

def subtract(matrix1, matrix2):
    if(len(matrix1) != len(matrix2) or len(matrix1[0]) != len(matrix2[0])):
        print("Subtraction not possible.")
        return
    
    ans = []
    for i in range(len(matrix1)):
        r = []
        for j in range(len(matrix1[0])):
            r.append(matrix1[i][j] - matrix2[i][j])
        ans.append(r)
    display(ans, "Subtraction: ")

def multiply(matrix1, matrix2):

    if(len(matrix1[0]) != len(matrix2)):
        print("Multiplication not possible.")
        return
    
    ans = []
    for i in range(len(matrix1)):
        l = []
        for j in range(len(matrix2[0])):
            l.append(0)
        ans.append(l)

    for i in range(len(matrix1)):
        for j in range(len(matrix2[0])):
            for k in range(len(matrix2)):
                ans[i][j] += matrix1[i][k] * matrix2[k][j]
    display(ans, "Multiplication: ")

def transpose(matrix):
    ans = []
    for i in range(len(matrix[0])):
        l = []
        for j in range(len(matrix)):
            l.append(matrix[j][i])
        ans.append(l)
    display(ans, "Transpose: ")

def display(matrix, s):
    print("-----------------------------")
    print(s)
    for i in matrix:
        for j in i:
            print(j, end=' ')
        print()
    print("-----------------------------")

def takeInput(rows, columns):
    mat = []
    for i in range(rows):
        r = []
        for j in range(columns):
            x = int(input("matrix1[%d][%d]: "%(i, j)))
            r.append(x)
        mat.append(r)
    return mat

if __name__ == '__main__':

    print("Enter Matrix 1")
    n = int(input("Enter no. of rows: "))
    m = int(input("Enter no. of columns: "))
    matrix1 = takeInput(n, m)

    print("Enter Matrix 2")
    x = int(input("Enter no. of rows: "))
    y = int(input("Enter no. of columns: "))
    matrix2 = takeInput(x, y)
    print("\n")

    choice = -1
    while(choice != 8):
        print("********* Menu *********")
        print("1. Display Matrix 1\n2. Display Matrix 2\n3. Addition\n4. Subtraction")
        print("5. Multiplication\n6. Find Matrix1 Transpose\n7. Find Matrix2 Transpose\n8. Exit")
        choice = int(input("Enter your Choice: "))

        if choice == 1:
            display(matrix1, "Matrix 1: ")
        elif choice == 2:
            display(matrix2, "Matrix 2: ")
        elif choice == 3:
            add(matrix1, matrix2)
        elif choice == 4:
            subtract(matrix1, matrix2)
        elif choice == 5:
            multiply(matrix1, matrix2)
        elif choice == 6:
            transpose(matrix1)
        elif choice == 7:
            transpose(matrix2)
        elif choice == 8:
            break
        else:
            print("Invalid Choice.")

        print("\n")

        
