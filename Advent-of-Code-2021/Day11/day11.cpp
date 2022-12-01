#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int flashes(int myArray[10][10], int I, int J, int &totalFlashes){
    int navR[9] = {0, -1, 0, 1, -1, 1, -1, 0, 1};
    int navC[9] = {0, 1, 1, 1, 0, 0, -1, -1, -1};

    if(myArray[I][J] < 10){
        return 0;
    }

    if(myArray[I][J] >= 10){
        myArray[I][J] = 0;
    }

    totalFlashes++;
    for(int i = 0; i < 9; i++){
        if(I + navR[i] >= 0 && I + navR[i] < 10 && J + navC[i] >= 0 && J + navC[i] < 10 && myArray[I + navR[i]][J + navC[i]] > 0){
            myArray[I + navR[i]][J + navC[i]]++;
            if(myArray[I + navR[i]][J + navC[i]] >= 10){
                flashes(myArray, I + navR[i], J + navC[i], totalFlashes);
            }
        }
    }
    return 0;
}

int main(){

    fstream myFile("input.txt");

    vector<string> octopi;
    int octopiArray[10][10];

    string line;
    while(getline(myFile, line)){   
        octopi.push_back(line);
    }

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            octopiArray[i][j] = octopi[i][j] - '0';
        }
    }

    int totalFlashes = 0;
    for(int i = 0; i < 300; i++){
        // increase each energy level by 1
        for(int j = 0; j < 10; j++){
            for(int k = 0; k < 10; k++){
                octopiArray[j][k]++;
            }
        }

        for(int j = 0; j < 10; j++){
            for(int k = 0; k < 10; k++){
                if(octopiArray[j][k] >= 10){
                    flashes(octopiArray, j, k, totalFlashes);
                }
            }
        }

        int simulFlash = 0;
        for(int j = 0; j < 10; j++){
            for(int k = 0; k < 10; k++){
                if(octopiArray[j][k] == 0){
                    simulFlash++;
                }
            }
        }
        if(simulFlash == 100){
            cout << i + 1 << endl;
        }
    }

    cout << "Total Flashes: " << totalFlashes << endl;


    return 0;
}