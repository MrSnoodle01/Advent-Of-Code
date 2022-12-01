#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>


using namespace std;

int main(){

    ifstream myFile("input.txt");

    vector<int> fishTimer;
    unsigned long long int nums[9] = {};
    
    for(int i = 0; i < 9; i++){
        nums[i] = 0;
    }

    string line;
    getline(myFile, line);

    for(int i = 0; i < line.size(); i++){
        fishTimer.push_back(line[i] - '0');
        i++;
    }

    unsigned long long int num0 = 0, num1 = 0, num2 = 0, num3 = 0, num4 = 0, 
    num5 = 0, num6 = 0, num7 = 0, num8 = 0;
    for(int i = 0; i < fishTimer.size(); i++){
        switch (fishTimer[i])
        {
        case 0:
            num0++;
            nums[0]++;
            break;
        case 1:
            num1++;
            nums[1]++;
            break;
        case 2:
            num2++;
            nums[2]++;
            break;
        case 3:
            num3++;
            nums[3]++;
            break;
        case 4:
            num4++;
            nums[4]++;
            break;
        case 5:
            num5++;
            nums[5]++;
            break;
        case 6:
            num6++;
            nums[6]++;
            break;
        case 7:
            num7++;
            nums[7]++;
            break;
        case 8:
            num8++;
            nums[8]++;
            break;
        default:
            break;
        }
    }

    unsigned long long int temp, temp2;
    for(int i = 0; i < 256; i++){
        for(int j = 0; j < 9; j++){
            temp += nums[i];
        }

        temp2 = nums[0];

        nums[0] = nums[1];

        nums[1] = nums[2];

        nums[2] = nums[3];

        nums[3] = nums[4];

        nums[4] = nums[5];

        nums[5] = nums[6];

        nums[6] = nums[7];
        nums[6] += temp2;

        nums[7] = nums[8];

        nums[8] = temp2;

    }

    temp = 0;
    for(int i = 0; i < 9; i++){
        temp += nums[i];
    }
    cout << temp << endl;

    return 0;
}
