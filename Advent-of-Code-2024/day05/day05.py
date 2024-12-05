# part 1
rightRules = {}
pages = []
with open('input.txt', 'r') as file:
    for line in file:
        if(line != "\n"):
            if(line[2] == '|'):
                left = line.split('|')[0]
                right = line.split('|')[1]
                right = right.replace('\n', '')

                if right in rightRules:
                    rightRules[right].append(left)
                else:
                    rightRules[right] = [left]
            else:
                line = line.replace('\n', '')
                pages.append(line.split(','))
                
correctlyOrdered = []
for page in pages:
    isGood = True
    for i in range(len(page)):
        # left leftRules
        if page[i] in rightRules:
            for j in range(i, len(page)):
                if page[j] in rightRules[page[i]]:
                    isGood = False
                    break
    if(isGood):
        correctlyOrdered.append(page)

final = 0
n = len(correctlyOrdered)
for array in correctlyOrdered:
    final += int(array[int((len(array)-1)/2)])
print("part 1 final: ", final)

# part 2
notCorrectlyOrdered = []
for page in pages:
    isGood = True
    for i in range(len(page)):
        # left leftRules
        if page[i] in rightRules:
            for j in range(i, len(page)):
                if page[j] in rightRules[page[i]]:
                    isGood = False
                    break

    # if bad, reorder so that it is Good
    while not isGood:
        check = 0
        for i in range(len(page)):
            isIn = True # so that when swapping indexes, you dont check for key that doesnt exist
            if page[i] in rightRules:
                for j in range(i, len(page)):
                    if isIn and page[j] in rightRules[page[i]]:
                        temp = page[i]
                        page[i] = page[j]
                        page[j] = temp
                        check += 1
                        isIn = False

        if check == 0:
            isGood = True
            notCorrectlyOrdered.append(page) 
        
final = 0
n = len(notCorrectlyOrdered)
for array in notCorrectlyOrdered:
    final += int(array[int((len(array)-1)/2)])
print("part 2 final: ", final)
