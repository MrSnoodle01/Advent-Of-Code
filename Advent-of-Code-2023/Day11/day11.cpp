#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <unordered_map>

std::vector<bool> rowCheck;
std::vector<bool> colCheck;

class coords{
    public:
        int i;
        int j;

};

class pairs{
    public:
        int first;
        int second;
};

std::vector<std::string> expand1(std::vector<std::string> input){
    // vectors to keep track if row/col needs to be expanded
    rowCheck.clear();
    colCheck.clear();

    for(int i = 0; i < input.size(); i++){
        rowCheck.push_back(true);
    }

    for(int i = 0; i < input[0].size() - 1; i++){ // - 1 to deal with blank space at end
        colCheck.push_back(true);
    }
    
    for(int i = 0; i < input.size(); i++){
        for(int j = 0; j < input[i].size() - 1; j++){ // - 1 to deal with blank space at end
            if(input[i][j] == '#'){
                rowCheck[i] = false;
                colCheck[j] = false;
            }
        }
    }

    std::string tempRow;
    for(int i = 0; i < input[0].size(); i++){
        tempRow += '-';
    }

    // var so that the insertions dont get behind
    int insertionNum = 0;
    for(int i = 0; i < rowCheck.size(); i++){
        if(rowCheck[i]){
            input.insert(input.begin() + i + insertionNum, tempRow);
            insertionNum++;
        }
    }

    insertionNum = 0;
    for(int i = 0; i < colCheck.size(); i++){
        if(colCheck[i]){
            for(int j = 0; j < input.size(); j++){
                input[j].insert(i + insertionNum, "-");
            }
            insertionNum++;
        }
    }

    return input;
}

std::vector<std::string> expand2(std::vector<std::string> input){
    // vectors to keep track if row/col needs to be expanded
    rowCheck.clear();
    colCheck.clear();

    for(int i = 0; i < input.size(); i++){
        rowCheck.push_back(true);
    }

    for(int i = 0; i < input[0].size() - 1; i++){ // - 1 to deal with blank space at end
        colCheck.push_back(true);
    }
    
    for(int i = 0; i < input.size(); i++){
        for(int j = 0; j < input[i].size() - 1; j++){ // - 1 to deal with blank space at end
            if(input[i][j] == '#'){
                rowCheck[i] = false;
                colCheck[j] = false;
            }
        }
    }

    return input;
}

void part1(){
    std::ifstream myfile("input.txt");
    std::string line;
    std::vector<std::string> input;
    while(std::getline(myfile, line)){
        input.push_back(line);
    }

    // expand the spaces
    input = expand1(input);

    // hashmap to keep track of the coordinates for each galaxy and its unique number
    std::unordered_map<int, coords> galaxies;

    int galaxyNum = 1;
    for(int i = 0; i < input.size(); i++){
        for(int j = 0; j < input[i].size(); j++){
            if(input[i][j] == '#'){
                coords temp;
                temp.i = i;
                temp.j = j;
                galaxies[galaxyNum] = temp;
                galaxyNum++;
            }
        }
    }

    // vector to hold all pairs
    std::vector<pairs> pairVector;
    for(int i = 1; i < galaxyNum; i++){
        for(int j = i; j < galaxyNum; j++){
            pairs temp;
            temp.first = i;
            temp.second = j;
            if(!(temp.first == temp.second)){
                pairVector.push_back(temp);
            }
        }
    }

    int totalSteps = 0;
    for(int i = 0; i < pairVector.size(); i++){
        coords firstCoord = galaxies[pairVector[i].first];
        coords secondCoord = galaxies[pairVector[i].second];
        if(firstCoord.i > secondCoord.i){
            totalSteps += firstCoord.i - secondCoord.i;
        }else if(firstCoord.i < secondCoord.i){
            totalSteps += secondCoord.i - firstCoord.i;
        }

        if(firstCoord.j > secondCoord.j){
            totalSteps += firstCoord.j - secondCoord.j;
        }else if(firstCoord.j < secondCoord.j){
            totalSteps += secondCoord.j - firstCoord.j;
        }
    }

    std::cout << "part 1 final: " << totalSteps << std::endl;
}

void part2(){
    std::ifstream myfile("input.txt");
    std::string line;
    std::vector<std::string> input;
    while(std::getline(myfile, line)){
        input.push_back(line);
    }

    // expand the spaces
    input = expand2(input);

    // hashmap to keep track of the coordinates for each galaxy and its unique number
    std::unordered_map<int, coords> galaxies;

    int galaxyNum = 1;
    for(int i = 0; i < input.size(); i++){
        for(int j = 0; j < input[i].size(); j++){
            if(input[i][j] == '#'){
                coords temp;
                temp.i = i;
                temp.j = j;
                galaxies[galaxyNum] = temp;
                galaxyNum++;
            }
        }
    }

    // vector to hold all pairs
    std::vector<pairs> pairVector;
    for(int i = 1; i < galaxyNum; i++){
        for(int j = i; j < galaxyNum; j++){
            pairs temp;
            temp.first = i;
            temp.second = j;
            if(!(temp.first == temp.second)){
                pairVector.push_back(temp);
            }
        }
    }

    long int totalSteps = 0;
    for(int i = 0; i < pairVector.size(); i++){
        coords firstCoord = galaxies[pairVector[i].first];
        coords secondCoord = galaxies[pairVector[i].second];

        //check if dot crosses a blank row/col and then multiply it accordingly

        if(firstCoord.i > secondCoord.i){
            for(int j = secondCoord.i; j < firstCoord.i; j++){
                if(rowCheck[j])
                    totalSteps += 1000000;
                else
                    totalSteps++;
            }
        }else if(firstCoord.i < secondCoord.i){
            for(int j = firstCoord.i; j < secondCoord.i; j++){
                if(rowCheck[j])
                    totalSteps += 1000000;
                else
                    totalSteps++;
            }
        }

        if(firstCoord.j > secondCoord.j){
            for(int j = secondCoord.j; j < firstCoord.j; j++){
                if(colCheck[j])
                    totalSteps += 1000000;
                else
                    totalSteps++;
            }
        }else if(firstCoord.j < secondCoord.j){
            for(int j = firstCoord.j; j < secondCoord.j; j++){
                if(colCheck[j])
                    totalSteps += 1000000;
                else
                    totalSteps++;
            }
        }
    }

    std::cout << "part 2 final: " << totalSteps << std::endl;
}

int main(){
    part1();
    part2();
}