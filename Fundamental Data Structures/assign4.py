
def linearSearch(arr, key):
    for i in arr:
        if(i == key):
            return True
    return False

def sentinelSearch(arr, key):
    last = arr[len(arr)-1]

    arr[len(arr)-1] = key

    i = 0;
    while(arr[i] != key):
        i += 1
    
    arr[len(arr)-1] = last

    if(i < len(arr)-1 or last == key):
        return True
    return False

def binarySearch(arr, key):
    l = 0
    h = len(arr) - 1
    while(l <= h):
        mid = l + ((h-l) // 2)
        if(arr[mid] == key):
            return True
        elif(arr[mid] < key):
            l = mid + 1
        else:
            h = mid - 1
    return False

def fibonacciSearch(arr, key):

    n = len(arr)

    fib = [0, 1]
    for i in range(2, 1000):
        fib.append(fib[i-1] + fib[i-2])

    k = 2
    while(fib[k] < n):
        k += 1
    
    offset = -1
    while(k > 2):
        i = min(offset + fib[k-2], n-1)

        if(key == arr[i]):
            return True
        elif(key > arr[i]):
            k -= 1
            offset = i
        elif(key < arr[i]):
            k -= 2
    
    if(fib[k-1] and arr[offset+1] == key):
        return True
    
    return False

if __name__ == '__main__':

    n = int(input("Enter numbers of students who attended training program: "))

    a = []
    print("Enter roll numbers of students: ")
    for i in range(n):
        x = int(input())
        a.append(x)
    print()

    choice = -1
    key = -1
    while(choice != 5):
        print("********* Menu *********")
        print("1. Search using Linear Search\n2. Search using sentinel search\n3. Search using Binary Search")
        print("4. Search using Fibonacci Search\n5. Exit")
        choice = int(input("Enter your Choice: "))

        if choice == 1:
            key = int(input("Enter roll number to search: "))
            if(linearSearch(a, key)):
                print("Roll no.", key, "attended training program.")
            else:
                print("Roll no.", key, "not attended training program.")
        elif choice == 2:
            key = int(input("Enter roll number to search: "))
            if(sentinelSearch(a, key)):
                print("Roll no.", key, "attended training program.")
            else:
                print("Roll no.", key, "not attended training program.")
        elif choice == 3:
            a.sort()
            key = int(input("Enter roll number to search: "))
            if(binarySearch(a, key)):
                print("Roll no.", key, "attended training program.")
            else:
                print("Roll no.", key, "not attended training program.")
        elif choice == 4:
            a.sort()
            key = int(input("Enter roll number to search: "))
            if(fibonacciSearch(a, key)):
                print("Roll no.", key, "attended training program.")
            else:
                print("Roll no.", key, "not attended training program.")
        elif choice == 5:
            exit(0)
        else:
            print("Invalid Choice.")

        print("\n")