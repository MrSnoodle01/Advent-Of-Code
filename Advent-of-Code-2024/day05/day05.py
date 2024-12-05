# part 1
leftRules = {}
rightRules = {}
pages = []
with open('input.txt', 'r') as file:
    for line in file:
        if(line != "\n"):
            if(line[2] == '|'):
                left = line.split('|')[0]
                right = line.split('|')[1]
                right = right.replace('\n', '')

                if left in leftRules:
                    leftRules[left].append(right)
                else:
                    leftRules[left] = [right]

                if right in rightRules:
                    rightRules[right].append(left)
                else:
                    rightRules[right] = [left]
            else:
                line = line.replace('\n', '')
                pages.append(line.split(','))

isGood = True
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
        # left leftRules
        if page[i] in leftRules:
            for j in range(len(pages)-1, -1):
                if page[j] in leftRules[page[i]]:
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
leftRules = {}
rightRules = {}
pages = []
with open('input.txt', 'r') as file:
    for line in file:
        if(line != "\n"):
            if(line[2] == '|'):
                left = line.split('|')[0]
                right = line.split('|')[1]
                right = right.replace('\n', '')

                if left in leftRules:
                    leftRules[left].append(right)
                else:
                    leftRules[left] = [right]

                if right in rightRules:
                    rightRules[right].append(left)
                else:
                    rightRules[right] = [left]
            else:
                line = line.replace('\n', '')
                pages.append(line.split(','))

isGood = True
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
        # left leftRules
        if page[i] in leftRules:
            for j in range(len(pages)-1, -1):
                if page[j] in leftRules[page[i]]:
                    isGood = False
                    break
    if(isGood):
        correctlyOrdered.append(page)

final = 0
n = len(correctlyOrdered)
for array in correctlyOrdered:
    final += int(array[int((len(array)-1)/2)])
print("part 1 final: ", final)
