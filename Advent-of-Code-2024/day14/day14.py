# part 1
bathroom = []
robots = []
velocities = []
with open('input.txt', 'r') as file:
    for line in file:
        parts = line.split()
        robots.append(list(map(int, parts[0].split('=')[1].split(','))))
        velocities.append(list(map(int, parts[1].split('=')[1].split(','))))

# create bathroom
wide = 101
tall = 103
for i in range(tall):
    temp = []
    for j in range(wide):
        temp.append(0)
    bathroom.append(temp)

# calculate robot moves
seconds = 100
for i in range(seconds):
    for j in range(len(robots)):
        robots[j][0] += velocities[j][0]
        robots[j][1] += velocities[j][1]

        if robots[j][0] < 0:
            robots[j][0] = wide + robots[j][0]
        
        if robots[j][1] < 0:
            robots[j][1] = tall + robots[j][1]
        
        if robots[j][0] >= wide:
            robots[j][0] -= wide
        
        if robots[j][1] >= tall:
            robots[j][1] -= tall


for i in robots:
    bathroom[i[1]][i[0]] += 1

# get quadrants
h = len(bathroom)
w = len(bathroom[1])
w2 = int(w // 2)
w3 = int(w // 2)
if w % 2 != 0:
    w3 += 1
h2 = int(h // 2)
h3 = int(h // 2)
if h % 2 != 0:
    h3 += 1
top_left =  [bathroom[i][:w2] for i in range(h2)]
top_right = [bathroom[i][w3:] for i in range(h2)]
bot_left =  [bathroom[i][:w2] for i in range(h3, h)]
bot_right = [bathroom[i][w3:] for i in range(h3, h)]

final = 0
for i in top_left:
    for j in i:
        final += j

tr = 0
for i in top_right:
    for j in i:
        tr += j
final *= tr

bl = 0
for i in bot_left:
    for j in i:
        bl += j
final *= bl

br = 0
for i in bot_right:
    for j in i:
        br += j
final *= br

print("part 1 final:", final)

# part 2
robots = []
velocities = []
with open('input.txt', 'r') as file:
    for line in file:
        parts = line.split()
        robots.append(list(map(int, parts[0].split('=')[1].split(','))))
        velocities.append(list(map(int, parts[1].split('=')[1].split(','))))

wide = 101
tall = 103

# calculate robot moves
notTree = True
count = 0
while notTree:
    notTree = False
    bathroom = []
    for a in range(tall):
        temp = []
        for b in range(wide):
            temp.append(0)
        bathroom.append(temp)

    for j in range(len(robots)):
        robots[j][0] += velocities[j][0]
        robots[j][1] += velocities[j][1]

        if robots[j][0] < 0:
            robots[j][0] = wide + robots[j][0]
        
        if robots[j][1] < 0:
            robots[j][1] = tall + robots[j][1]
        
        if robots[j][0] >= wide:
            robots[j][0] -= wide
        
        if robots[j][1] >= tall:
            robots[j][1] -= tall

    for i in robots:
        bathroom[i[1]][i[0]] += 1

    count += 1

    for i in bathroom:
        for j in i:
            if j > 1:
                notTree = True

print("part 2 final:", count)