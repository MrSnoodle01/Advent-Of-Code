# part1
# map = []
# with open('input.txt', 'r') as file:
#     for line in file:
#         map.append(list(line.strip()))

# notDone = True
# newI = 0
# newJ = 0
# while(notDone):
#     for i in range(newI, len(map)):
#         for j in range(newJ, len(line)):
#             if(map[i][j] == '^'):
#                 if(i-1 >= 0 and map[i-1][j] == '#'):
#                     map[i][j] = '>'
#                 elif(i-1 >= 0):
#                     map[i-1][j] = '^'
#                     newI = i-1
#                     newJ = j
#                     map[i][j] = 'X'
#                 else:
#                     notDone = False
#             elif(map[i][j] == '>'):
#                 if(j+1 < len(line) and map[i][j+1] == '#'):
#                     map[i][j] = 'V'
#                 elif(j+1 < len(line)):
#                     map[i][j+1] = '>'
#                     newI = i
#                     newJ = j+1
#                     map[i][j] = 'X'
#                 else:
#                     notDone = False
#             elif(map[i][j] == 'V'):
#                 if(i+1 < len(line) and map[i+1][j] == '#'):
#                     map[i][j] = '<'
#                 elif(i+1 < len(line)):
#                     map[i+1][j] = 'V'
#                     newI = i+1
#                     newJ = j
#                     map[i][j] = 'X'
#                 else:
#                     notDone = False
#             elif(map[i][j] == "<"):
#                 if(j-1 >= 0 and map[i][j-1] == '#'):
#                     map[i][j] = '^'
#                 elif(j-1 >= 0):
#                     map[i][j-1] = '<'
#                     newI = i
#                     newJ = j-1
#                     map[i][j] = 'X'
#                 else:
#                     notDone = False,

# final = 0
# for line in map:
#     final += len([index for index, value in enumerate(line) if value == 'X'])
# final += 1
# print("part 1 final:", final)

# part 2
map = []
with open('testinput.txt', 'r') as file:
    for line in file:
        map.append(list(line.strip()))

obstructionI = []
obstructionJ = []
numObstructions = 0
newI = 0
newJ = 0
notDone = True
while(notDone):
    for i in range(newI, len(map)):
        for j in range(newJ, len(line)):
            if(map[i][j] == '^'):
                if(i-1 >= 0 and map[i-1][j] == '#'):
                    map[i][j] = '>'
                    obstructionI.append(i-1)
                    obstructionJ.append(j)
                elif(i-1 >= 0):
                    map[i-1][j] = '^'
                    newI = i-1
                    newJ = j
                    map[i][j] = '|'
                    if len(obstructionJ) >= 3:
                        if i == obstructionI[len(obstructionI)-3] or j == obstructionJ[len(obstructionJ)-3]:
                            numObstructions += 1
                            print("hit", i-1, j)
                else:
                    notDone = False
            elif(map[i][j] == '>'):
                if(j+1 < len(line) and map[i][j+1] == '#'):
                    map[i][j] = 'V'
                    obstructionI.append(i)
                    obstructionJ.append(j+1)
                elif(j+1 < len(line)):
                    map[i][j+1] = '>'
                    newI = i
                    newJ = j+1
                    map[i][j] = '-'
                    if len(obstructionJ) >= 3:
                        if i == obstructionI[len(obstructionI)-3] or j == obstructionJ[len(obstructionJ)-3]:
                            numObstructions += 1
                            print("hit", i, j+1)
                else:
                    notDone = False
            elif(map[i][j] == 'V'):
                if(i+1 < len(line) and map[i+1][j] == '#'):
                    map[i][j] = '<'
                    obstructionI.append(i+1)
                    obstructionJ.append(j)
                elif(i+1 < len(line)):
                    map[i+1][j] = 'V'
                    newI = i+1
                    newJ = j
                    map[i][j] = '|'
                    if len(obstructionJ) >= 3:
                        if i == obstructionI[len(obstructionI)-3] or j == obstructionJ[len(obstructionJ)-3]:
                            numObstructions += 1
                            print("hit", i+1, j)
                else:
                    notDone = False
            elif(map[i][j] == "<"):
                if(j-1 >= 0 and map[i][j-1] == '#'):
                    map[i][j] = '^'
                    obstructionI.append(i)
                    obstructionJ.append(j-1)
                elif(j-1 >= 0):
                    map[i][j-1] = '<'
                    newI = i
                    newJ = j-1
                    map[i][j] = '-'
                    if len(obstructionJ) >= 3:
                        if i == obstructionI[len(obstructionI)-3] or j == obstructionJ[len(obstructionJ)-3]:
                            numObstructions += 1
                            print("hit", i, j-1)
                else:
                    notDone = False,

final = 0
for line in map:
    print(line)
    final += len([index for index, value in enumerate(line) if value == 'X'])
final += 1
print("part 2 final:", numObstructions)

print(obstructionI)
print(obstructionJ)