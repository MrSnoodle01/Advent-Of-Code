# part 1
# tuples are stored as (x,y)
buttonA = []
buttonB = []
prizes = []
with open('input.txt', 'r') as file:
    for line in file:
        if line != "\n":
            if line[7] == 'A':
                buttonA.append((int(line.strip()[12:14]), int(line.strip()[18:])))
            elif line[7] == 'B':
                buttonB.append((int(line.strip()[12:14]), int(line.strip()[18:])))
            else:
                comIndex = line.find(',')
                prizes.append((int(line.strip()[9:comIndex]), int(line.strip()[comIndex+4:])))

final = 0
for k in range(len(buttonA)):
    for i in range(100):
        for j in range(100): 
            if buttonA[k][0] * i + buttonB[k][0] * j == prizes[k][0] and buttonA[k][1] * i + buttonB[k][1] * j == prizes[k][1]:
                final += i * 3 + j
    
print("part 1 final", final)
        
# part 2
import numpy as np
# tuples are stored as (x,y)
buttonA = []
buttonB = []
prizes = []
with open('input.txt', 'r') as file:
    for line in file:
        if line != "\n":
            if line[7] == 'A':
                buttonA.append((int(line.strip()[12:14]), int(line.strip()[18:])))
            elif line[7] == 'B':
                buttonB.append((int(line.strip()[12:14]), int(line.strip()[18:])))
            else:
                comIndex = line.find(',')
                prizes.append((int(line.strip()[9:comIndex])+10000000000000, int(line.strip()[comIndex+4:])+10000000000000))

final = 0
for k in range(len(buttonA)):
    # coefficient matrix
    A = np.array([
        [buttonA[k][0], buttonB[k][0]],
        [buttonA[k][1], buttonB[k][1]]
    ])

    # result matrix
    B = np.array([prizes[k][0], prizes[k][1]])

    # actually solve equations
    X = np.linalg.solve(A, B)

    a, b = X
    a = round(a, 2)
    b = round(b, 2)

    if a.is_integer() and b.is_integer():
        final += a * 3
        final += b
    
print("part 2 final", int(final))
        