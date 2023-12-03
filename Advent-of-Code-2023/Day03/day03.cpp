#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_map>

int x[5]={0,0,0,1,-1};
int y[5]={0,1,-1,0,0};

void part1(std::vector<std::string> input){
    bool isAdjacent = false;
    int final = 0;
    std::string digit = "";
    
    for(int i = 0; i < input.size(); i++){
        isAdjacent = false;
        digit = "";
        for(int j = 0; j < input[i].size(); j++){
            if(isdigit(input[i][j])){
                digit += input[i][j];
                for(int a = 1; a < 5; a++){
                    for(int b = 1; b < 5; b++){
                        if(i + x[a] >= 0 && j + y[b] >= 0 && i + x[a] < input.size() && j + y[b] < input[i].size() - 1){
                            int ascii = input[i+x[a]][j+y[b]];
                            if(ascii != 46 && !isdigit(input[i+x[a]][j+y[b]])){
                                isAdjacent = true;
                            }
                        }
                    }
                }
            }else{
                if(isAdjacent){
                    final += stoi(digit);
                }
                isAdjacent = false;
                digit = "";
            }
        }
        if(isAdjacent){
            final += stoi(digit);
        }
    }
    std::cout << "final: " << final << std::endl;
}

void part2(std::vector<std::string> input){
    // unique key as the concatinated coords, with array of potential nums
    std::unordered_map<int, std::vector<int>> gearCoords;
    std::string coords = "", digit = "";
    bool isAdjacent = false;
    int final = 0;

    for(int i = 0; i < input.size(); i++){
        isAdjacent = false;
        digit = "";
        coords = "";
        for(int j = 0; j < input[i].size(); j++){
            if(isdigit(input[i][j])){
                digit += input[i][j];
                for(int a = 1; a < 5; a++){
                    for(int b = 1; b < 5; b++){
                        if(i + x[a] >= 0 && j + y[b] >= 0 && i + x[a] < input.size() && j + y[b] < input[i].size() - 1){
                            int ascii = input[i+x[a]][j+y[b]];
                            // if it is *
                            if(ascii == 42){
                                coords = std::to_string(i+x[a]) + std::to_string(j+y[b]);
                                isAdjacent = true;
                            }
                        }
                    }
                }
            }else{
                if(isAdjacent){
                    std::vector<int> temp = gearCoords[stoi(coords)];
                    temp.push_back(stoi(digit));
                    gearCoords[stoi(coords)] = temp;
                }
                isAdjacent = false;
                digit = "";
            }
        }
    }

    std::unordered_map<int, std::vector<int>>::iterator itr;
    for(itr = gearCoords.begin(); itr != gearCoords.end(); itr++){
        if(itr->second.size() == 2){
            final += itr->second[0] * itr->second[1];
        }
    }

    std::cout << "final: " << final << std::endl;
}   

int main(){
    std::vector<std::string> input;

    std::ifstream myfile("input.txt");
    
    std::string line;
    while(std::getline(myfile, line)){
        input.push_back(line);
    }

    part1(input);
    part2(input);
}