
def longest_str(str1):
    return max(str.split(str1), key=len)

def checkPalindrome(str1):
    return (str1 == str1[::-1])

def getOcc(str1):
    counts = dict()
    words = str.split(str1)
    for i in words:
        if i in counts:
            counts[i] += 1
        else:
            counts[i] = 1
    return counts

str1=input("Enter the string = ")
while 1:
    print("1. To display the word with longest length")
    print("2. To determine the frequency of particular word")
    print("3. To check whether given string is palindron or not")
    print("4. To display the index of first appearance of the string")
    print("5. To count the occurance of each word in a given string")
    print("6. Exit")
    choice = int(input("Enter the choice :"))
    if choice == 1:
        print("Word with longest length :", longest_str(str1))
    elif choice == 2:
        a=input("Enter the character :")
        print("Frequency of particular character", a, " : ", str1.count(a))
    elif choice == 3:
        if(checkPalindrome(str1)):
            print("str1 is palindrome")
        else:
            print("str1 is not palindrome")
    elif choice == 4:
        print("Index of first appearance of substring")
        b = input("Enter the substring : ")
        print(str1.find(b))
    elif choice == 5:
        print("Occurance of each word in string")
        occ = getOcc(str1)
        for i in occ:
            print(i, ":", occ[i])
    elif choice == 6:
        break
    else:
        print("Invalid choice")