# part 1
stones = []
tempStones = []
with open('input.txt', 'r') as file:
    for line in file:
        stones = line.strip().split()

blinks = 25
for k in range(blinks):
    if k > 0:
        stones = []
        for temp in tempStones:
            stones.append(temp)
        tempStones = []
    for i in range(len(stones)):
        if stones[i] == '0':
            tempStones.append('1')
        elif len(stones[i]) % 2 == 0:
            stoneMid = len(stones[i])//2
            # funny type casting to remove leading zeros
            tempStones.append(str(int(stones[i][0:stoneMid])))
            tempStones.append(str(int(stones[i][stoneMid:])))
        else:
            tempStones.append(str(int(stones[i]) * 2024))
    
print("part 1 final: ", len(tempStones))

# part 2
stones = []
with open('input.txt', 'r') as file:
    for line in file:
        stones = line.strip().split()

blinks = 75
myDict2 = {}  
for stone in stones:
    myDict2[stone] = 1
for k in range(blinks):
    myDict = {}
    
    for key, value in myDict2.items():
        myDict[key] = myDict2[key]

    myDict2 = {}     
    for key, value in myDict.items():
        if key == '0':
                if '1' in myDict2:
                    myDict2['1'] = myDict2['1'] + value
                else:
                    myDict2['1'] = value
        elif len(key) % 2 == 0:
            # funny type casting to remove leading zeros
            first = str(int(key[0:len(key)//2]))
            second = str(int(key[len(key)//2:]))

            if first in myDict2: 
                myDict2[first] = myDict2[first] + value
            else:
                myDict2[first] = value

            if second in myDict2:
                myDict2[second] = myDict2[second] + value
            else:
                myDict2[second] = value
        else:
            newKey = str(int(key)*2024)
            if newKey in myDict2:
                myDict2[newKey] = myDict2[newKey] + value
            else:
                myDict2[newKey] = value

final = 0
for value in myDict2.values():
    final += value
print("part 2 final: ", final)