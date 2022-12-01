#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

int main(){

    vector<int> inputs;

    ifstream myFile ("input.txt");

    string line;
    if(myFile.is_open()){
        while(getline(myFile, line)){
            inputs.push_back(stoi(line));
        }
        myFile.close();
    }

    int increasedCount = 0;

    for(int i = 0; i < inputs.size() - 1; i++){
        int sum1 = 0;
        int sum2 = 0;
        sum1 += inputs[i];
        sum1 += inputs[i + 1];
        sum1 += inputs[i + 2];

        sum2 += inputs[i + 1];
        sum2 += inputs[i + 2];
        sum2 += inputs[i + 3];

        if(sum2 > sum1){
            increasedCount++;
        }
    }

    cout << increasedCount << endl;

    return 0;
}