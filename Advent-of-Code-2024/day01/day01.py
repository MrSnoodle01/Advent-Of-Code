# part one
leftArr = []
rightArr = []

with open("testinput.txt", "r") as file:
    for line in file:
        leftArr.append(int(line.split()[0]))
        rightArr.append(int(line.split()[1]))

leftArr.sort()
rightArr.sort()

final = 0
for i in range(len(leftArr)):
    if(leftArr[i] > rightArr[i]):
        final = final + leftArr[i] - rightArr[i]
    elif(rightArr[i] > leftArr[i]):
        final = final + rightArr[i] - leftArr[i]

print("part one final: ", final)

# part 2
final = 0
for i in range(len(leftArr)):
    final = final + leftArr[i]*rightArr.count(leftArr[i])

print("part 2 final: ", final)