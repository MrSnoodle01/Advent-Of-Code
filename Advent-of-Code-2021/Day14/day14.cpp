#include <iostream>
#include <sstream>
#include <fstream>
#include <unordered_map>

using namespace std;

int main(){

    fstream myFile("input.txt");

    unordered_map<char, long long int> count;
    unordered_map<string, char> pairInsertionRules;
    unordered_map<string, long long int> polymerMap;
    unordered_map<string, long long int> tempMap;

    string line, Template;
    getline(myFile, Template);

    // fills up polymerMap with all pairs before step 1
    // ex. for testInput.txt
    // line.substr(0, 2) = NN
    // line.substr(1, 2) = NC
    for(int i = 0; i < Template.size() - 2; i++){
        polymerMap[Template.substr(i, 2)]++;
    }

    string stringTemp;
    char charTemp;
    // fills pairInsertionRules with the rules
    while(getline(myFile, line)){
        //make sure line isnt empty
        if(line.size() > 5){
            istringstream ss(line);

            ss >> stringTemp;
            ss.ignore(4);
            ss >> charTemp;

            pairInsertionRules[stringTemp] = charTemp;
        }
    }

    // traverse through a unorderd_map
    // for(auto i : pairInsertionRules){
    //     cout << i.first << " -> " << i.second << endl;
    // }

    for(int i = 0; i < 40; i++){
        tempMap = polymerMap;
        for(const auto & [key, value] : tempMap){
            // get the pairs that a pair will break up into and increment them
            // ex. [key = NN, value = 2]
            //     polymerMap[NC] += 2
            //     polymerMap[CN] += 2
            polymerMap[string() + key[0] + pairInsertionRules[key]] += value;
            polymerMap[string() + pairInsertionRules[key] + key[1]] += value;
            if((polymerMap[key] -= value) == 0){
                polymerMap.erase(key);
            }
        }
    }
    
    // put the totals for each char in count map
    long long int min = 0, max = 0;
    for(const auto & [key, value] : polymerMap){
        count[key[0]] += value;
        max = count[key[0]];
        min = count[key[0]];
    }
    
    // find min and max
    for(const auto & [key, value] : count){
        if(value > max){
            max = value;
        }
        if(value < min){
            min = value;
        }
    }

    cout << "max - min = " << max - min + 1<< endl;

    return 0;
}