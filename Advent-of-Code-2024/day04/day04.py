# part 1
wordSearchDirs = [
  [0, 1],
  [1, 0],
  [1, 1],
  [-1, 0],
  [0, -1],
  [-1, -1],
  [1, -1],
  [-1, 1],
]

inputArr = []
with open('input.txt', 'r') as file:
    for line in file:
        inputArr.append(line.replace("\n", ""))

final = 0
for i in range(len(inputArr)):
    iLen = len(inputArr)
    for j in range(len(inputArr[i])):
        jLen = len(inputArr[i])
        for di, dj in wordSearchDirs:
            word = ""
            ci = i
            cj = j
            while ci >= 0 and ci < iLen and cj >= 0 and cj < jLen and len(word) < 4:
                word += inputArr[ci][cj]
                if(word == "XMAS"):
                    final += 1
                ci += di
                cj += dj
        
print("part 1 final: ", final)

# part 2
topLeftDiag = [
  [-1, -1],
  [0, 0],
  [1, 1],
]
topRightDiag = [
  [1, -1],
  [0, 0],
  [-1, 1],
]

inputArr = []
with open('input.txt', 'r') as file:
    for line in file:
        inputArr.append(line.replace("\n", ""))

final = 0
for i in range(len(inputArr)):
    iLen = len(inputArr)
    for j in range(len(inputArr[i])):
        jLen = len(inputArr[i])
        if(inputArr[i][j] == 'A'):
            topLeftWord = ""
            toprightWord = ""
            for di, dj in topLeftDiag:
                ci = i + di
                cj = j + dj
                topLeftWord += inputArr[ci][cj] if ci >= 0 and ci < iLen and cj >= 0 and cj < jLen else ""
            for di, dj in topRightDiag:
                ci = i + di
                cj = j + dj
                toprightWord += inputArr[ci][cj] if ci >= 0 and ci < iLen and cj >= 0 and cj < jLen else ""
            if((topLeftWord == "MAS" or topLeftWord == "SAM") and (toprightWord == "MAS" or toprightWord == "SAM")):
                final += 1
                
print("part 2 final: ", final)