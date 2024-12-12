# part 1
grid = []
with open('input.txt', 'r') as file:
    for line in file:
        grid.append(line.strip())

# get all antennas
antennaDict = {}
for i in range(len(grid)):
    for j in range(len(grid[i])):
        if grid[i][j] != '.':
            if grid[i][j] in antennaDict:
                antennaDict[grid[i][j]].append((i, j))
            else:
                antennaDict[grid[i][j]] = [(i, j)]
                
final = 0
antinodes = []
tempGrid = []
for i in grid:
    tempGrid.append(list(i))

for key, value in antennaDict.items():
    for antenna in value:
        for antenna2 in value:
            if antenna is not antenna2:
                x = abs(antenna[0] - antenna2[0])
                y = abs(antenna[1] - antenna2[1])
                if antenna[0] > antenna2[0]:
                    x1 = abs(x + antenna[0])
                else:
                    x1 = antenna[0] - x
                    
                if antenna[1] > antenna2[1]:
                    y1 = abs(y + antenna[1])
                else:
                    y1 = antenna[1] - y

                if x1 >= 0 and x1 < len(grid) and y1 >= 0 and y1 < len(grid[0]):
                    if (x1,y1) not in antinodes:
                        tempGrid[x1][y1] = '#'
                        antinodes.append((x1,y1))
                        final = final + 1

print("part 1 final:", final)

# part 2
grid = []
with open('input.txt', 'r') as file:
    for line in file:
        grid.append(line.strip())

# get all antennas
antennaDict = {}
for i in range(len(grid)):
    for j in range(len(grid[i])):
        if grid[i][j] != '.':
            if grid[i][j] in antennaDict:
                antennaDict[grid[i][j]].append((i, j))
            else:
                antennaDict[grid[i][j]] = [(i, j)]
                
final = 0
antinodes = []
tempGrid = []
for i in grid:
    tempGrid.append(list(i))

for key, value in antennaDict.items():
    for antenna in value:
        for antenna2 in value:
            if antenna is not antenna2:
                x = abs(antenna[0] - antenna2[0])
                y = abs(antenna[1] - antenna2[1])
                if antenna[0] > antenna2[0]:
                    x1 = abs(x + antenna[0])
                else:
                    x1 = antenna[0] - x
                    
                if antenna[1] > antenna2[1]:
                    y1 = abs(y + antenna[1])
                else:
                    y1 = antenna[1] - y

                while x1 >= 0 and x1 < len(grid) and y1 >= 0 and y1 <len(grid[0]):
                    if (x1,y1) not in antinodes:
                        tempGrid[x1][y1] = '#'
                        antinodes.append((x1,y1))
                        final = final + 1

                    if antenna[0] > antenna2[0]:
                        x1 = x1 + x
                    else:
                        x1 = x1 - x
                        
                    if antenna[1] > antenna2[1]:
                        y1 = y1 + y
                    else:
                        y1 = y1 - y
for i in tempGrid:
    for j in i:
        if j != '.' and j != '#':
            final += 1
print("part 1 final:", final)

