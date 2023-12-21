#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <unordered_map>

void part1(){
    std::vector<std::string> input;
    std::string line;
    std::fstream myfile("input.txt");
    while(std::getline(myfile, line, ',')){
        input.push_back(line);
    }

    int currValue = 0;
    int final = 0;
    for(int i = 0; i < input.size(); i++){
        for(int j = 0; j < input[i].size(); j++){
            currValue += int(input[i][j]);
            currValue *= 17;
            currValue = currValue % 256;
        }
        final += currValue;
        currValue = 0;
    }

    std::cout << "part 1 final: " << final << std::endl;
}

void part2(){
    std::vector<std::string> input;
    std::string line;
    std::fstream myfile("input.txt");
    while(std::getline(myfile, line, ',')){
        input.push_back(line);
    }

    // vector to keep track of where in each box the id's go
    std::vector<std::vector<std::string>> indexes; 
    // vector to hold all 256 boxes holding multiple lenses
    std::vector<std::unordered_map<std::string, int>> boxes;
    for(int i = 0; i < 256; i++){
        std::unordered_map<std::string, int> temp;
        boxes.push_back(temp);
        std::vector<std::string> temp2;
        indexes.push_back(temp2);
    }

    int currValue = 0;      // hold which box to go into
    std::string id = "";    // hold the string of letters
    int focalLength = 0;    // hold the focal length if op is =
    bool isEq = false;      // check if the op is =
    for(int i = 0; i < input.size(); i++){
        for(int j = 0; j < input[i].size(); j++){
            // if there is an operator break
            if(input[i][j] == '=' || input[i][j] == '-'){
                // if op is =, set isEq and update focalLength
                if(input[i][j] == '='){
                    isEq = true;
                    focalLength = input[i][j + 1] - '0';
                }
                break;
            }
            // add char to id
            id += input[i][j];
            // calculate correct box
            currValue += int(input[i][j]);
            currValue *= 17;
            currValue = currValue % 256;
        }

        // if op is =:
        //  if id is already in vector do nothing
        //  else push it onto vector
        // if op is -, remove index with that id
        if(isEq){ 
            bool doIt = true;
            for(int j = 0; j < indexes[currValue].size(); j++){
                if(indexes[currValue][j] == id)
                    doIt = false;
            }
            if(doIt)
                indexes[currValue].push_back(id);
        }else{
            for(int j = 0; j < indexes[currValue].size(); j++){
                if(indexes[currValue][j] == id){
                    indexes[currValue].erase(indexes[currValue].begin() + j);
                }
            }
        }

        if(isEq) // if op is =, add it to boxes vector
            boxes[currValue][id] = focalLength;
        else    // if op is -, take away from boxes vector
            boxes[currValue].erase(id);

        // reset vars
        currValue = 0;
        id = "";
        focalLength = 0;
        isEq = false;
        
    }

    int final = 0;
    for(int i = 0; i < indexes.size(); i++){
        for(int j = 0; j < indexes[i].size(); j++){
            if(!indexes[i][j].empty()){
                final += (i + 1) * (j + 1) * boxes[i][indexes[i][j]];
            }
            
        }
    }

    std::cout << "part 2 final: " << final << std::endl;
}

int main(){
    part1();
    part2();
}