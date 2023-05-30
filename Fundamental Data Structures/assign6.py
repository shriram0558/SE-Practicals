
def partition(arr, s, e):
    
    pivot = arr[s]

    cnt = 0
    for i in range(s+1, e+1):
        if(arr[i] <= pivot):
            cnt += 1
    
    pivotIndex = s + cnt
    arr[s], arr[pivotIndex] = arr[pivotIndex], arr[s]

    i = s
    j = e

    while(i < pivotIndex and j > pivotIndex):

        while(arr[i] <= pivot):
            i += 1
        
        while(arr[j] > pivot):
            j -= 1
        
        if(i < pivotIndex and j > pivotIndex):
            arr[i], arr[j] = arr[j], arr[i]
            i += 1
            j -= 1
    
    return pivotIndex


def quickSort(arr, s, e):

    if(s >= e):
        return

    # find pivot index
    pivot = partition(arr, s, e)

    # sort left part of pivot
    quickSort(arr, s, pivot-1)
    
    # sort right part of pivot
    quickSort(arr, pivot+1, e)

def displayTop(arr, n):
    cnt = 1
    print("Top 5 Percentages: ")
    for i in range(n-1, min(n-6, 0), -1):
        print(cnt, ":", arr[i])
        cnt += 1

if __name__ == '__main__':
    n = int(input("Enter the no. of Students: "))

    percentage = []
    for i in range(n):
        print("Enter percentage of Student", i+1, ": ", end='')
        x = float(input())
        percentage.append(x)

    print("Unsorted:", percentage)
    quickSort(percentage, 0, n-1)
    print("Sorted:", percentage)
    displayTop(percentage, n)

