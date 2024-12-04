# part 1
inputArr = []
with open('input.txt', 'r') as file:
    for line in file:
        inputArr.append(line.replace("\n", ""))

final = 0
for i in range(len(inputArr)):
    iLen = len(inputArr)
    for j in range(len(inputArr[i])):
        jLen = len(inputArr[i])
        if(inputArr[i][j] == 'X'):
            if(i+1 < iLen and inputArr[i+1][j] == 'M'):
                if(i+2 < iLen and inputArr[i+2][j] == 'A'):
                    if(i+3 < iLen and inputArr[i+3][j] == 'S'):
                        final = final + 1
            if(i-1 >= 0 and inputArr[i-1][j] == 'M'):
                if(i-2 >= 0 and inputArr[i-2][j] == 'A'):
                    if(i-3 >= 0 and inputArr[i-3][j] == 'S'):
                        final = final + 1
            if(j+1 < jLen and inputArr[i][j+1] == 'M'):
                if(j+2 < jLen and inputArr[i][j+2] == 'A'):
                    if(j+3 < jLen and inputArr[i][j+3] == 'S'):
                        final = final + 1
            if(j-1 >= 0 and inputArr[i][j-1] == 'M'):
                if(j-2 >= 0 and inputArr[i][j-2] == 'A'):
                    if(j-3 >= 0 and inputArr[i][j-3] == 'S'):
                        final = final + 1
            if(j-1 >= 0 and i-1 >= 0 and inputArr[i-1][j-1] == 'M'):
                if(j-2 >= 0 and i-2 >= 0 and inputArr[i-2][j-2] == 'A'):
                    if(j-3 >= 0 and i-3 >= 0 and inputArr[i-3][j-3] == 'S'):
                        final = final + 1
            if(j+1 < jLen and i-1 >= 0 and inputArr[i-1][j+1] == 'M'):
                if(j+2 < jLen and i-2 >= 0 and inputArr[i-2][j+2] == 'A'):
                    if(j+3 < jLen and i-3 >= 0 and inputArr[i-3][j+3] == 'S'):
                        final = final + 1
            if(j+1 < jLen and i+1 < iLen and inputArr[i+1][j+1] == 'M'):
                if(j+2 < jLen and i+2 < iLen and inputArr[i+2][j+2] == 'A'):
                    if(j+3 < jLen and i+3 < iLen and inputArr[i+3][j+3] == 'S'):
                        final = final + 1
            if(j-1 >= 0 and i+1 < iLen and inputArr[i+1][j-1] == 'M'):
                if(j-2 >= 0 and i+2 < iLen and inputArr[i+2][j-2] == 'A'):
                    if(j-3 >= 0 and i+3 < iLen and inputArr[i+3][j-3] == 'S'):
                        final = final + 1
        
print("part 1 final: ", final)
# part 2
inputArr = []
with open('input.txt', 'r') as file:
    for line in file:
        inputArr.append(line.replace("\n", ""))

final = 0
for i in range(len(inputArr)):
    iLen = len(inputArr)
    for j in range(len(inputArr[i])):
        jLen = len(inputArr[i])
        if(inputArr[i][j] == 'A'):
            # s on bottoom, m on top
            if(i+1 < iLen and j+1 < jLen and inputArr[i+1][j+1] == 'S'):
                if(i-1 >= 0 and j-1 >= 0 and inputArr[i-1][j-1] == 'M'):
                    if(i+1 < iLen and j-1 >= 0 and inputArr[i+1][j-1] == 'M'):
                        if(i-1 >= 0 and j+1 < jLen and inputArr[i-1][j+1] == 'S'):
                            final = final + 1
            # m on bottom, s on top
            if(i+1 < iLen and j+1 < jLen and inputArr[i+1][j+1] == 'M'):
                if(i-1 >= 0 and j-1 >= 0 and inputArr[i-1][j-1] == 'S'):
                    if(i+1 < iLen and j-1 >= 0 and inputArr[i+1][j-1] == 'S'):
                        if(i-1 >= 0 and j+1 < jLen and inputArr[i-1][j+1] == 'M'):
                            final = final + 1
            # m on left, s on right
            if(i+1 < iLen and j+1 < jLen and inputArr[i+1][j+1] == 'S'):
                if(i-1 >= 0 and j-1 >= 0 and inputArr[i-1][j-1] == 'M'):
                    if(i+1 < iLen and j-1 >= 0 and inputArr[i+1][j-1] == 'S'):
                        if(i-1 >= 0 and j+1 < jLen and inputArr[i-1][j+1] == 'M'):
                            final = final + 1
            # m on right, s on left
            if(i+1 < iLen and j+1 < jLen and inputArr[i+1][j+1] == 'M'):
                if(i-1 >= 0 and j-1 >= 0 and inputArr[i-1][j-1] == 'S'):
                    if(i+1 < iLen and j-1 >= 0 and inputArr[i+1][j-1] == 'M'):
                        if(i-1 >= 0 and j+1 < jLen and inputArr[i-1][j+1] == 'S'):
                            final = final + 1

print("part 2 final: ", final)