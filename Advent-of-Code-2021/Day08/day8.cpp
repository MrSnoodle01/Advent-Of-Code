#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main(){

    ifstream myFile("testInput.txt");

    vector<string> lines;

    string line;
    while(getline(myFile, line)){
        lines.push_back(line);
    }

    vector<string> tempFirstPart;
    vector<string> tempSecondPart;
    string temp;
    for(int i = 0; i < lines.size(); i++){
        istringstream ss(lines[i]);

        for(int j = 0; j < 10; j++){
            ss >> temp;
            tempFirstPart.push_back(temp);
        }

        ss.ignore();
        ss.ignore();

        for(int j = 0; j < 4; j++){
            ss >> temp;
            tempSecondPart.push_back(temp);
        }
    }

    string oneSegment;
    for(int j = 0; j < 10; j++){
        if(tempFirstPart[j].size() == 2){
            oneSegment = tempFirstPart[j];
        }
    }
    // cout << "first part: " << oneSegment << endl;

    string fourSegment;
    for(int j = 0; j < 10; j++){
        if(tempFirstPart[j].size() == 4){
            fourSegment = tempFirstPart[j];
        }
    }
    // cout << "four part: " << fourSegment << endl;

    vector<string> outputValues;
    int totalSegments = 0;
    string tempString;
    int multiplyCounter = 1;
    for(int i = 0; i < tempSecondPart.size(); i++){
        if(i > 3 && i % 4 == 0){
            for(int j = 0; j < 10 * multiplyCounter; j++){
                if(tempFirstPart[j].size() == 2){
                    oneSegment = tempFirstPart[j];
                }else if(tempFirstPart[j].size() == 4){
                    fourSegment = tempFirstPart[j];
                }
            }
            // cout << "onseg: " << oneSegment << endl;
            // cout << "fourseg: " << fourSegment << endl;
        }

        if(tempSecondPart[i].size() == 2){
            totalSegments++;
            tempString += '1';
        }else if(tempSecondPart[i].size() == 4){
            totalSegments++;
            tempString += '4';
        }else if(tempSecondPart[i].size() == 3){
            totalSegments++;
            tempString += '7';
        }else if(tempSecondPart[i].size() == 7){
            totalSegments++;
            tempString += '8';
        }else if(tempSecondPart[i].size() == 5){
            // find if it is a 3
            char temp1 = oneSegment[0];
            char temp2 = oneSegment[1];
            int tempCounter = 0;
            for(int j = 0; j < tempSecondPart[i].size(); j++){
                if(tempSecondPart[i][j] == temp1){
                    tempCounter++;
                }
                if(tempSecondPart[i][j] == temp2){
                    tempCounter++;
                }
            }
            if(tempCounter == 2){
                tempString += '3';
            }else{
                // find if it is a 2 or 5
                char temp1 = fourSegment[0];
                char temp2 = fourSegment[1];
                char temp3 = fourSegment[2];
                char temp4 = fourSegment[3];
                int tempCounter = 0;
                for(int j = 0; j < tempSecondPart[i].size(); j++){
                    if(tempSecondPart[i][j] == temp1){
                        tempCounter++;
                    }
                    if(tempSecondPart[i][j] == temp2){
                        tempCounter++;
                    }
                    if(tempSecondPart[i][j] == temp3){
                        tempCounter++;
                    }
                    if(tempSecondPart[i][j] == temp4){
                        tempCounter++;
                    }
                }
                if(tempCounter == 3){
                    tempString += '5';
                }else{
                    tempString += '2';
                }
            }
        }else if(tempSecondPart[i].size() == 6){
            // find if it is a 9
            char temp1 = fourSegment[0];
            char temp2 = fourSegment[1];
            char temp3 = fourSegment[2];
            char temp4 = fourSegment[3];
            int tempCounter = 0;
            for(int j = 0; j < tempSecondPart[i].size(); j++){
                if(tempSecondPart[i][j] == temp1){
                    tempCounter++;
                }
                if(tempSecondPart[i][j] == temp2){
                    tempCounter++;
                }
                if(tempSecondPart[i][j] == temp3){
                    tempCounter++;
                }
                if(tempSecondPart[i][j] == temp4){
                    tempCounter++;
                }
            }
            if(tempCounter == 4){
                tempString += '9';
            }else{
                // find if it is a 6
                temp1 = oneSegment[0];
                temp2 = oneSegment[1];
                tempCounter = 0;
                for(int j = 0; j < tempSecondPart[i].size(); j++){
                    if(tempSecondPart[i][j] == temp1){
                        tempCounter++;
                    }
                    if(tempSecondPart[i][j] == temp2){
                        tempCounter++;
                    }
                }
                if(tempCounter == 1){
                    tempString += '6';
                }else{
                    tempString += '0';
                }
            }
        }

        if(tempString.size() % 4 == 0){
            outputValues.push_back(tempString);
            tempString = "";
            multiplyCounter++;
        }
    }

    int total = 0;
    for(int i = 0; i < outputValues.size(); i++){
        // cout << "outputValues" << i << ": " << outputValues[i] << endl;
        total += stoi(outputValues[i]);

    }

    cout << "Total: " << total << endl;
    //cout << "Total Segments: " << totalSegments << endl;

    return 0;
}