#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

int main(){

    fstream myFile("input.txt");

    vector<string> lines;

    string line;
    while(getline(myFile, line)){
        lines.push_back(line);
    }

    vector<string> incompleteLinesStack;
    vector<char> check;
    string tempString;

    // PART ONE
    int totalScore = 0;
    for(int i = 0; i < lines.size(); i++){
        int tempScore = totalScore;
        for(int j = 0; j < lines[i].size(); j++){
            switch(lines[i][j]){
                // if the character is an open bracket then add it to the check vector, which will act as a sort of stack
                case '(':
                    check.push_back(lines[i][j]);
                    break;
                case '[':
                    check.push_back(lines[i][j]);
                    break;
                case '{':
                    check.push_back(lines[i][j]);
                    break;
                case '<':
                    check.push_back(lines[i][j]);
                    break;
                // if the character is a close bracket 
                // if the character is not a matching close bracket to the last element in check vector:
                //      then the line is corrupted
                case ')':
                    if(check.back() != '('){
                        totalScore += 3;
                        goto corruptedFound;
                    }
                    check.pop_back();
                    break;
                case ']':
                    if(check.back() != '['){
                        totalScore += 57;
                        goto corruptedFound;
                    }
                    check.pop_back();
                    break;
                case '}':
                    if(check.back() != '{'){
                        totalScore += 1197;
                        goto corruptedFound;
                    }
                    check.pop_back();
                    break;
                case '>':
                    if(check.back() != '<'){
                        totalScore += 25137;
                        goto corruptedFound;
                    }
                    check.pop_back();
                    break;
            }
        }
        // for part two
        for(int k = 0; k < check.size(); k++){
            tempString += check[k];
        }
        incompleteLinesStack.push_back(tempString);
        tempString = "";
        // for part two


        corruptedFound:
            check.clear();
    }

    cout << "total Score: " << totalScore << endl;

    // PART TWO
    vector<unsigned long long int> scores;
    unsigned long long int tempScore = 0;
    for(int i = 0; i < incompleteLinesStack.size(); i++){
        tempScore = 0;
        for(int j = incompleteLinesStack[i].size() - 1; j >= 0; j--){
            tempScore *= 5;
            switch(incompleteLinesStack[i][j]){
                case '[':
                    tempScore += 2;
                    break;
                case '(':
                    tempScore += 1;
                    break;
                case '{':
                    tempScore += 3;
                    break;
                case '<':
                    tempScore += 4;
                    break;
            }
        }
        scores.push_back(tempScore);
    }

    // bubble sort
    unsigned long long int temp = 0;
    for(int i = 0; i < scores.size(); i++){
        for(int j = 0; j < scores.size() - i - 1; j++){
            if(scores[j] > scores[j + 1]){
                temp = scores[j];
                scores[j] = scores[j + 1];
                scores[j + 1] = temp;
            }
        }
    }

    unsigned long long int medianNum = scores.size() / 2;
    cout << "Middle score: " << scores[medianNum] << endl;
    

    return 0;
}