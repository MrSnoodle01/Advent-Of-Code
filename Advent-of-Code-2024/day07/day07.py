import time
# part 1
part1Start = time.time()
total = 0
with open('input.txt', 'r') as file:
    for line in file:
        line = line.split(':')
        sum = int(line[0])
        nums = (line[1].strip()).split(' ')

        isGood = False
        # basically do binary with addtion being 0 or multiplication being 1
        for i in range(pow(2, len(nums)-1)):
            binaryNum = format(i, f'0{len(nums)-1}b')

            final = int(nums[0])
            for j in range(len(nums)-1):
                if binaryNum[j] == '0':
                    final += int(nums[j+1])
                elif binaryNum[j] == '1':
                    final *= int(nums[j+1])
            if final == sum:
                isGood = True
                break
        if isGood:
            total += sum

part1End = time.time()

print("part 1 final: ", total)
print("part 1 time:", part1End-part1Start)
            
# part 2
def convertToTernary(N):
    # Base case
    if N == 0:
        return ""
    
    # Finding the remainder when N is divided by 3
    x = N % 3
    N //= 3
    if x < 0:
        N += 1

    # Recursive call to compute the rest of the ternary representation
    result = convertToTernary(N)

    # Return the ternary digit as a string
    return result + str(x)

def convert(Decimal, length):
    
    # Handle the special case for 0
    if Decimal == 0:
        ternary = "0"
    else:
        # Compute the ternary representation
        ternary = convertToTernary(Decimal)

    # Add leading zeros to make the ternary number the specified length
    if length > 0:
        ternary = ternary.zfill(length)
    
    return ternary

part2Start = time.time()
total = 0
with open('input.txt', 'r') as file:
    for line in file:
        line = line.split(':')
        sum = int(line[0])
        nums = (line[1].strip()).split(' ')

        isGood = False
        # basically do binary with addtion being 0 or multiplication being 1
        for i in range(pow(2, len(nums)-1)):
            binaryNum = format(i, f'0{len(nums)-1}b')

            final = int(nums[0])
            for j in range(len(nums)-1):
                if binaryNum[j] == '0':
                    final += int(nums[j+1])
                elif binaryNum[j] == '1':
                    final *= int(nums[j+1])
            if final == sum:
                isGood = True
                break

        # use ternary instead of binary to account for concatenation
        for i in range(pow(3, len(nums)-1)):
            ternaryNum = convert(i, len(nums)-1)
            final = int(nums[0])
            for j in range(len(nums)-1):
                if ternaryNum[j] == '0':
                    final += int(nums[j+1])
                elif ternaryNum[j] == '1':
                    final *= int(nums[j+1])
                elif ternaryNum[j] == '2':
                    final = int(str(final) + nums[j+1])
            if final == sum:
                isGood = True
                break

        if isGood:
            total += sum

part2End = time.time()

print("part 2 final: ", total)
print("part 2 time:", part2End-part2Start)
            