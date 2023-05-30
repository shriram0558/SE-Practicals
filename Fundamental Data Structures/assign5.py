
def selectionSort(arr, n):
    for i in range(n-1):
        minIndex = i
        for j in range(i+1, n):
            if(arr[j] < arr[minIndex]):
                minIndex = j
        arr[i], arr[minIndex] = arr[minIndex], arr[i]

def bubbleSort(arr, n):
    for i in range(1, n):
        for j in range(n-i):
            if(arr[j] > arr[j+1]):
                arr[j], arr[j+1] = arr[j+1], arr[j]

def displayTop(arr, n):
    cnt = 1
    print("Top 5 Percentages: ")
    for i in range(n-1, min(n-6, 0), -1):
        print(cnt, ":", arr[i])
        cnt += 1

if __name__ == '__main__':

    n = int(input("Enter the no. of Students in First Year: "))

    percentage = []
    for i in range(n):
        print("Enter percentage of Student", i+1, ": ", end='')
        x = float(input())
        percentage.append(x)
    
    choice = -1
    while(choice != 3):
        print("\n\n********* Menu *********")
        print("1. Sort Using Selection Sort\n2. Sort using Bubble Sort\n3. Exit")
        choice = int(input("Enter your Choice: "))

        if(choice == 1):
            selectionSort(percentage, n)
            displayTop(percentage, n)
        elif(choice == 2):
            bubbleSort(percentage, n)
            displayTop(percentage, n)
        else:
            break