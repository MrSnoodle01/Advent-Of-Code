#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int main(){

    ifstream myFile("input.txt");

    vector<int> crabs;

    string line;

    while(getline(myFile, line, ',')){
        crabs.push_back(stoi(line));
    }

    vector<int> fuelVector;
    int fuelTemp = 1, fuelTotal = 0;
    for(int i = 1; i < 1500; i++){
        fuelTotal = 0;
        fuelTemp = 1;
        for(int j = 0; j < crabs.size(); j++){
            if(crabs[j] > i){
                fuelTemp += crabs[j];
                fuelTemp -= i;
                for(int n = fuelTemp - 1; n > 0; n--){
                    fuelTotal += n;
                }
            }else{
                fuelTemp += i;
                fuelTemp -= crabs[j];
                for(int n = fuelTemp - 1; n > 0; n--){
                    fuelTotal += n;
                }
            }
            fuelTemp = 1;
        }
        fuelVector.push_back(fuelTotal);
    }

    int lowestFuel = fuelVector[0];
    for(int i = 0; i < fuelVector.size(); i++){
        if(fuelVector[i] < lowestFuel && fuelVector[i] >= 0){
            lowestFuel = fuelVector[i];
        }
    }

    cout << "lowest fuel: " << lowestFuel << endl;

    return 0;
}

