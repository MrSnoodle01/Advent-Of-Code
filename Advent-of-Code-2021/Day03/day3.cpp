#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main(){
    vector<string> myVector;
    vector<string> partTwo;

    string gamma, epsilon, oxygen, co2;

    ifstream myFile("input.txt");

    string line;
    while(getline(myFile, line)){
        myVector.push_back(line);
        partTwo.push_back(line);
    }

    //PART ONE

    int oneBit = 0, zeroBit = 0;
    string temp;
    int n = 0;
    for(int i = 0; i < myVector[i].size() - 1; i++){
        oneBit = 0;
        zeroBit = 0;

        for(int j = 0; j < myVector.size(); j++){
            temp = myVector[j];
            if(temp[n] == '1'){
                oneBit++;
            }else if(temp[n] == '0'){
                zeroBit++;
            }
        }

        if(oneBit > zeroBit){
            gamma += '1';
            epsilon += '0';
        }else if(zeroBit > oneBit){
            gamma += '0';
            epsilon += '1';
        }
        n++;
    }


    // PART TWO

    oneBit = 0;
    zeroBit = 0;
    for(int i = 0; i < myVector.size(); i++){
        temp = myVector[i];
        if(temp[0] == '1'){
            oneBit++;
        }else if(temp[0] == '0'){
            zeroBit++;
        }
    }  

    n = 0;
    for(int j = 0; j < 12; j++){
        for(int i = 0; i < myVector.size(); i++){
            temp = myVector[i];

            if(oneBit > zeroBit){   
                if(temp[n] == '0'){
                    myVector.erase(myVector.begin() + i);
                    i--;
                }
            }else if(zeroBit > oneBit){
                if(temp[n] == '1'){
                    myVector.erase(myVector.begin() + i);
                    i--;
                }
            }else if(zeroBit == oneBit){
                if(temp[n] == '0'){
                    myVector.erase(myVector.begin() + i);
                    i--;
                }
            }
        }
        n++;

        oneBit = 0;
        zeroBit = 0;
        for(int i = 0; i < myVector.size(); i++){
            temp = myVector[i];
            if(temp[n] == '1'){
                oneBit++;
            }else if(temp[n] == '0'){
                zeroBit++;
            }
        }
    }

    oxygen = myVector[0];

    oneBit = 0;
    zeroBit = 0;
    for(int i = 0; i < partTwo.size(); i++){
        temp = partTwo[i];
        if(temp[0] == '1'){
            oneBit++;
        }else if(temp[0] == '0'){
            zeroBit++;
        }
    }

    n = 0;
    for(int j = 0; j < 12; j++){
        for(int i = 0; i < partTwo.size(); i++){
            temp = partTwo[i];

            if(oneBit > zeroBit){   
                if(temp[n] == '1'){
                    partTwo.erase(partTwo.begin() + i);
                    i--;
                }
            }else if(zeroBit > oneBit){
                if(temp[n] == '0'){
                    partTwo.erase(partTwo.begin() + i);
                    i--;
                }
            }else if(oneBit == zeroBit){
                if(temp[n] == '1'){
                    partTwo.erase(partTwo.begin() + i);
                    i--;
                }
            }
        }
        n++;

        oneBit = 0;
        zeroBit = 0;
        for(int i = 0; i < partTwo.size(); i++){
            temp = partTwo[i];
            if(temp[n] == '1'){
                oneBit++;
            }else if(temp[n] == '0'){
                zeroBit++;
            }
        }
    }

    co2 = partTwo[0];

    cout << "Gamma: " << gamma << endl << "Epsilion: " << epsilon << endl;
    cout << "Oxygen: " << oxygen << endl;
    cout << "co2: " << co2 << endl;

    return 0;
}
