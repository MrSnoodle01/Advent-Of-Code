def isLineGood(line):
    previous = int(line[0])
    isGood = True
    increaseOrDecrease = '';
    
    for i in range(len(line) - 1):
        i = i + 1
        
        # increase = curr-prev
        # decrease = prev-curr
        
        if(i == 1 and previous - int(line[i]) > int(line[i]) - previous):
            increaseOrDecrease = 'd'

        if(i == 1 and previous - int(line[i]) < int(line[i]) - previous):
            increaseOrDecrease = 'i'

        if(increaseOrDecrease == 'i' and (int(line[i]) - previous > 3 or int(line[i]) - previous < 1) or previous - int(line[i]) == 0):
            isGood = False

        if(increaseOrDecrease == 'd' and (previous - int(line[i]) > 3 or previous - int(line[i]) < 1) or previous - int(line[i]) == 0):
            isGood = False

        previous = int(line[i])

    if(isGood):
        return 1;
    else:
        return 0;

# part 1
final = 0

with open("input.txt", "r") as file:
    for line in file:
        final = final + isLineGood(line.split());

print("part 1 final: " , final)

# part 2
final = 0
count = 0
myArr = []

with open("input.txt", "r") as file:
    for line in file:
        isGood = False
        for i in range(len(line.split())):
            tempArr = line.split()
            tempArr = tempArr[:i] + tempArr[i+1:]
            if(isLineGood(tempArr)):
                isGood = True
        if(isGood):
            final = final + 1
            
print("part 2 final: " , final)