
# function to calculate list of students who play both cricket and badminton
def func1(grpA, grpB):
    ans = []
    for i in grpA:
        for j in grpB:
            if(i == j):
                ans.append(i)
    return ans;

# function to calculate list of students who play either cricket or badminton but not both
def func2(grpA, grpB):
    ans = []
    for i in grpA:
        present = False
        for j in grpB:
            if(i == j):
                present = True
        if(not present):
            ans.append(i)

    for i in grpB:
        present = False
        for j in grpA:
            if(i == j):
                present = True
        if(not present):
            ans.append(i)
    return ans

# function to calculate number of students who play neither cricket nor badminton
def func3(grpA, grpB, grpC):
    ans = []
    ab = grpA + grpB
    for i in grpC:
        present = False
        for j in ab:
            if(i == j):
                present = True
        if(not present):
            ans.append(i)
    return ans

# function to calculate number of students who play cricket & football but not badminton
def func4(grpA, grpB, grpC):
    ans = []
    ac = []
    for i in grpA:
        for j in grpC:
            if(i == j):
                ac.append(i)
    for i in ac:
        present = False
        for j in grpB:
            if(i == j):
                present = True
        if(not present):
            ans.append(i)
    return ans

if __name__ == '__main__':
    
    grpA = ['A', 'B', 'C', 'D', 'E']
    grpB = ['F', 'A', 'R', 'V', 'B']
    grpC = ['A', 'D', 'V', 'M', 'N']

    print("List of students who play both cricket and badminton")
    print(func1(grpA, grpB))
    print("List of students who play either cricket or badminton but not both")
    print(func2(grpA, grpB))
    print("List of students who play neither cricket nor badminton")
    print(func3(grpA, grpB, grpC))
    print("Number of students who play neither cricket nor badminton : ", end = '')
    print(len(func3(grpA, grpB, grpC)))
    print("List of students who play cricket & football but not badminton")
    print(func4(grpA, grpB, grpC))
    print("Number of students who play cricket & football but not badminton : ", end = '')
    print(len(func3(grpA, grpB, grpC)))