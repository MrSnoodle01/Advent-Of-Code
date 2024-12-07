# part 1
# total = 0
# with open('input.txt', 'r') as file:
#     for line in file:
#         line = line.split(':')
#         sum = int(line[0])
#         nums = (line[1].strip()).split(' ')

#         isGood = False
#         # basically do binary with addtion being 0 or multiplication being 1
#         for i in range(pow(2, len(nums)-1)):
#             binaryNum = format(i, f'0{len(nums)-1}b')

#             final = int(nums[0])
#             for j in range(len(nums)-1):
#                 if binaryNum[j] == '0':
#                     final += int(nums[j+1])
#                 elif binaryNum[j] == '1':
#                     final *= int(nums[j+1])
#             if final == sum:
#                 isGood = True
#         if isGood:
#             total += sum

# print("part 1 final: ", total)
            
import copy
# part 2
total = 0
with open('testinput.txt', 'r') as file:
    for line in file:
        line = line.split(':')
        sum = int(line[0])
        nums = (line[1].strip()).split(' ')
        print("sum", sum)

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

        concatenateArr = []
        for i in range(len(nums)-1):
            tempNums = copy.deepcopy(nums)
            tempNums[i] = nums[i] + nums[i+1]
            tempNums.pop(i+1)
            concatenateArr.append(tempNums)
        print("concat", concatenateArr)

        # using concatenation
        for arr in concatenateArr:
            for i in range(pow(2, len(arr)-1)):
                binaryNum = format(i, f'0{len(arr)-1}b')

                final = int(arr[0])
                for j in range(len(arr)-1):
                    if binaryNum[j] == '0':
                        final += int(arr[j+1])
                    elif binaryNum[j] == '1':
                        final *= int(arr[j+1])
                if final == sum:
                    isGood = True

        # concatenate after operations
        for i in range(pow(2, len(arr)-1)):
            binaryNum = format(i, f'0{len(arr)-1}b')

            final = int(arr[0])
            for j in range(len(arr)-1):
                if binaryNum[j] == '0':
                    final += int(arr[j+1])
                elif binaryNum[j] == '1':
                    final *= int(arr[j+1])
            if final == sum:
                isGood = True

        # # tempNums = nums
        # # if pow(2, len(nums)-2)-1 == 0:
        # #     limit = pow(2, len(nums)-2)
        # #     limit2 = len(nums)-1
        # # else:
        # #     limit = pow(2, len(nums)-2)-1
        # #     limit2 = len(nums)-2
        # for i in range(pow(2, len(nums)-1)):
        #     binaryNum = format(i, f'0{len(nums)-2}b')

        #     # tempNums = copy.deepcopy(nums)
        #     # print("before", tempNums)
        #     # print("i", i)
        #     # tempNums[i] = tempNums[i] + tempNums[i+1]
        #     # tempNums.pop(i+1)
        #     # print("after", tempNums)
        #     final = int(nums[0])
        #     counter = 0
        #     for j in range(len(nums)-1):
        #         # tempNums = copy.deepcopy(nums)
        #         # print("before", tempNums)
        #         # # if i == counter:
        #         # tempNums[i] = str(final) + tempNums[i+1]
        #         # tempNums.pop(i+1)
        #         # counter += 1
        #         # print("after", tempNums)
        #         # # print("counter", counter)
        #         # # print("i", i)
        #         # # print("j", j)
        #         if binaryNum[j] == '0':
        #             final += int(nums[j+1])
        #         elif binaryNum[j] == '1':
        #             final *= int(nums[j+1])
        #     if final == sum:
        #         isGood = True
        #     # if length of nums is 2 and it don't go into concatenation loop
        #     # elif int(nums[0] + nums[1]) == sum:
        #     #     isGood = True

        if isGood:
            total += sum
            print("good sum", sum)

print("part 2 final: ", total)
            