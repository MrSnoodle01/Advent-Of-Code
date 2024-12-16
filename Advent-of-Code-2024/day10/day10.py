# part 1
from collections import deque

# only checks to see if index is out of bounds
def isValid(grid, row, col):
    if row >= len(grid) or row < 0 or col >= len(grid[0]) or col < 0:
        return False
    return True

def bfs(grid, start, end):
    directions = [(0,1), (1,0), (0,-1), (-1,0)]

    queue = deque([start])
    visited = set()

    while queue:
        (x,y) = queue.popleft()
        if (x,y) == end:
            return True
        if (x,y) in visited or not isValid(grid, x, y):
            continue
        visited.add((x,y))
        for dx, dy in directions:
            if isValid(grid, x+dx, y+dy) and grid[x+dx][y+dy] != '.':
                if int(grid[x+dx][y+dy]) - int(grid[x][y]) == 1:
                    queue.append((x + dx, y + dy))
        
    return False

grid =[]
with open('input.txt', 'r') as file:
    for line in file:
        grid.append(list(line.strip()))

starts = []
ends = []

for i in range(len(grid)):
    for j in range(len(grid[i])):
        if grid[i][j] == '0':
            starts.append((i, j))
        elif grid[i][j] == '9':
            ends.append((i,j))

final = 0
for start in starts:
    for end in ends:
        if bfs(grid, start, end):
            final += 1

print("part 1 final:", final)

# part 2
from collections import deque

def bfs2(grid, start, end, score):
    directions = [(0,1), (1,0), (0,-1), (-1,0)]
    queue = deque([start])

    while queue:
        (x,y) = queue.popleft()
        if (x,y) == end:
            score += 1
        if not isValid(grid, x, y):
            continue
        for dx, dy in directions:
            if isValid(grid, x+dx, y+dy) and grid[x+dx][y+dy] != '.':
                if int(grid[x+dx][y+dy]) - int(grid[x][y]) == 1:
                    queue.append((x + dx, y + dy))
        
    return score

final = 0
for start in starts:
    for end in ends:
        final += bfs2(grid, start, end, 0)

print("part 1 final:", final)