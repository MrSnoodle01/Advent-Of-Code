#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int checkWin(vector<int> boards, int drawNum, vector<int> drawNumVector, vector<int> &boardsThatWon){

    int counter = 0;
    int counterTemp = 0;
    bool hasWon = false;

        for(int k = 1; k < boards.size() / 25 + 1; k++){
            counter *= 25;
            counterTemp = counter;
            hasWon = false;

            //CHECKS ROWS
            for(int i = 0; i < 5; i++){
                for(int j = 0; j < drawNum; j++){
                    if(boards[counter] == drawNumVector[j]){
                        for(int a = 0; a < drawNum; a++){
                            if(boards[counter + 1] == drawNumVector[a]){
                                for(int b = 0; b < drawNum; b++){
                                    if(boards[counter + 2] == drawNumVector[b]){
                                        for(int c = 0; c < drawNum; c++){
                                            if(boards[counter + 3] == drawNumVector[c]){
                                                for(int d = 0; d < drawNum; d++){
                                                    if(boards[counter + 4] == drawNumVector[d]){
                                                        for(int e = 0; e < boardsThatWon.size(); e++){
                                                            if(boardsThatWon[e] == counterTemp){
                                                                hasWon = true;
                                                            }
                                                        }

                                                        if(hasWon == false){
                                                            boardsThatWon.push_back(counterTemp);
                                                        }
                                                        //return counterTemp;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                counter += 5;
            }

            counter = counterTemp;
            //CHECK COLUMNS
            for(int i = 0; i < 5; i++){
                for(int a = 0; a < drawNum; a++){
                    if(boards[counter] == drawNumVector[a]){
                        for(int b = 0; b < drawNum; b++){
                            if(boards[counter + 5] == drawNumVector[b]){
                                for(int c = 0; c < drawNum; c++){
                                    if(boards[counter + 10] == drawNumVector[c]){
                                        for(int d = 0; d < drawNum; d++){
                                            if(boards[counter + 15] == drawNumVector[d]){
                                                for(int e = 0; e < drawNum; e++){
                                                    if(boards[counter + 20] == drawNumVector[e]){
                                                        for(int f = 0; f < boardsThatWon.size(); f++){
                                                            if(boardsThatWon[f] == counterTemp){
                                                                hasWon = true;
                                                            }
                                                        }
                                                        if(hasWon == false){
                                                            boardsThatWon.push_back(counterTemp);
                                                        }
                                                        //return counterTemp;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                counter += 1;
            }
                
            counter = k;
        }

    return -1;
}

int main(){

    vector<string> initial;
    vector<int> drawNumsInt;
    vector<int> bingoBoards;

    ifstream myFile("input.txt");

    string drawNums;
    getline(myFile, drawNums);

    char temp;
    string temp2;
    for(int i = 0; i < drawNums.size(); i++){
        temp = drawNums[i];
        if(temp == ','){
            initial.push_back(temp2);
            temp2 = "";
            i++;
            temp = drawNums[i];
        }
        temp2 += temp;
    }
    initial.push_back(temp2);

    for(int i = 0; i < initial.size(); i++){
        drawNumsInt.push_back(stoi(initial[i]));
    }

    string line;
    int num1, num2, num3, num4, num5;
    while(getline(myFile, line)){
        istringstream ss(line);
        if(ss >> num1 >> num2 >> num3 >> num4 >> num5){
            bingoBoards.push_back(num1);
            bingoBoards.push_back(num2);
            bingoBoards.push_back(num3);
            bingoBoards.push_back(num4);
            bingoBoards.push_back(num5);
        }
    }

    int checkWins = 0;
    int numOfChecks = 0;

    vector<int> winningBoards;

    for(int i = 0; i < drawNumsInt.size(); i++){
        checkWins = checkWin(bingoBoards, i, drawNumsInt, winningBoards);
        
        // if(checkWins != -1){
        //     i = drawNumsInt.size() - 1;
        // }
        if(winningBoards.size() == 100){
            i = drawNumsInt.size() - 1;
        }

        numOfChecks++;
    }

    checkWins = winningBoards[winningBoards.size() - 1];

    int total = 0;
    for(int i = 0; i < 25; i++){
        total += bingoBoards[checkWins + i];
    }

    for(int j = 0; j < numOfChecks - 1; j++){
        for(int i = 0; i < 25; i++){
            if(bingoBoards[checkWins + i] == drawNumsInt[j]){
                total -= bingoBoards[checkWins + i];
            }
        }
    }

    total *= drawNumsInt[numOfChecks - 2];
    
    cout << total << endl;

    return 0;
}

