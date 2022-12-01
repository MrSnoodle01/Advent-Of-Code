#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

int testGlobal = 0;

void getBasin(int myArray[100][100], int row, int col){
    
	int navR[5]={0,0,0,1,-1};
	int navC[5]={0,1,-1,0,0};

    if(myArray[row][col] == 9){
        cout << "returned " << endl;
        return;
    }
    myArray[row][col] = 9;

    for(int k = 1; k < 5; k++){
        if(row + navR[k] >= 0 && row + navR[k] < 100 && col + navC[k] >= 0 && col + navC[k] < 100){
            if(myArray[row + navR[k]][col + navC[k]] != 9){
                testGlobal++;
                getBasin(myArray, row + navR[k], col + navC[k]);
            }
        }
    }
    return;
}

int main(){

    ifstream myFile("input.txt");

    vector<string> tubes;

    string line;
    while(getline(myFile, line)){
        tubes.push_back(line);
    }

    int tubesArray[100][100];

    for(int i = 0; i < tubes.size(); i++){
        for(int j = 0; j < tubes[0].size(); j++){
            tubesArray[i][j] = tubes[i][j] - '0';
        }
    }

    // for(int i = 0; i < tubes.size(); i++){
    //     for(int j = 0; j < tubes[0].size() - 1; j++){
    //         cout << tubesArray[i][j];
    //     }
    //     cout << endl;
    // }

    // PART ONE
    vector<int> lowestVector;
    vector<int> lowestI;
    vector<int> lowestJ;
    for(int i = 0; i < tubes.size(); i++){
        for(int j = 0; j < tubes[0].size() - 1; j++){
            if(tubesArray[i][j - 1] > tubesArray[i][j] || j - 1 < 0){
                if(tubesArray[i + 1][j] > tubesArray[i][j] || i + 1 >= tubes.size()){
                    if(tubesArray[i][j + 1] > tubesArray[i][j] || j + 1 >= tubes[0].size() - 1){
                        if(tubesArray[i - 1][j] > tubesArray[i][j] || i - 1 < 0){
                            lowestVector.push_back(tubesArray[i][j]);
                            lowestI.push_back(i);
                            lowestJ.push_back(j);
                        }
                    }
                }
            }
        }
    }
    int total = 0;
    for(int i = 0; i < lowestVector.size(); i++){
        total += lowestVector[i] + 1; 
    }
    cout << "Total: " << total << endl;

    // PART TWO
    vector<int> basins;
    for(int i = 0; i < lowestI.size(); i++){
        getBasin(tubesArray, lowestI[i], lowestJ[i]);
        basins.push_back(testGlobal);
        testGlobal = 0;
    }

    vector<int> top3Basin;
    int highest = 0;
    int tempJ = 0;
    cout << "basin sisze: " << basins.size() << endl;
    for(int i = 0; i < basins.size(); i++){
        cout << "basin: " << basins[i] << endl;
    }
    for(int i = 0; i < 3; i++){
        highest = 0;
        tempJ = 0;
        for(int j = 0; j < basins.size(); j++){
            if(basins[j] > highest){
                highest = basins[j];
                tempJ = j;
            }
        }
        top3Basin.push_back(highest);
        basins[tempJ] = 0;
    }

    int sum = 1;
    for(int i = 0; i < top3Basin.size(); i++){
        sum *= top3Basin[i] + 1;
        cout << i << ": " << top3Basin[i] << endl;
    }
    cout << "Final Sum: " << sum << endl;

    return 0;
}