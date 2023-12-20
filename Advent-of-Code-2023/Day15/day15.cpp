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
    std::fstream myfile("testinput.txt");
    while(std::getline(myfile, line, ',')){
        input.push_back(line);
    }

    // vector to hold all 256 boxes holding multiple lenses
    std::vector<std::unordered_map<std::string, int>> boxes;
    for(int i = 0; i < 256; i++){
        std::unordered_map<std::string, int> temp;
        boxes.push_back(temp);
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

    for(int i = 0; i < boxes.size(); i++){
        if(!boxes[i].empty()){
            std::cout << "box: " << i << " ";
            for(auto j : boxes[i]){
                std::cout << "[" << j.first << " " << j.second << "] ";
            }
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;

    int final = 0;
    // go thorugh each hashmap in boxes vector
    for(int i = 0; i < boxes.size(); i++){
        // make sure that boxes isnt empty
        if(!boxes[i].empty()){
            // size keeps track of the slot that should be multiplied
            int size = boxes[i].size();
            // iterates through each lense in the box
            for(auto j : boxes[i]){
                // adds (box + 1) * slot num * focalLength to final value
                final += (i + 1) * size * j.second;
                // std::cout << i + 1 << " " << size << " " << j.second << std::endl;
                // std::cout << (i + 1) * size * j.second << std::endl;
                // reduce size cause I have the entries reversed
                size--;
            }
        }
    }

    std::cout << "part 2 final: " << final << std::endl;
}

int main(){
    part1();
    part2();
}