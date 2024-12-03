import re

# part 1
final = 0
goodInstructions = []
with open('input.txt', 'r') as file:
    for line in file:
        goodInstructions = re.findall("mul\(\d{1,3},\d{1,3}\)", line)
        for instruction in goodInstructions:
            # get num,num
            numCommaNum = re.split(r'(\d\d?\d?,\d\d?\d?)', instruction)
            nums = numCommaNum[1].split(',');
            final += int(nums[0]) * int(nums[1])

print("part1 final: ", final)
    
# part 2
final = 0
canRun = True
goodInstructions = []
with open('input.txt', 'r') as file:
    for line in file:
        goodInstructions = re.findall("mul\(\d{1,3},\d{1,3}\)|don't\(\)|do\(\)", line)
        for instruction in goodInstructions:
            if(instruction == "don't()"):
                canRun = False
            elif(instruction == "do()"):
                canRun = True
            elif(canRun):
                # get num,num
                numCommaNum = re.split(r'(\d\d?\d?,\d\d?\d?)', instruction)
                nums = numCommaNum[1].split(',');
                final += int(nums[0]) * int(nums[1])

print("part1 final: ", final)