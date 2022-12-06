#include <iostream>
#include <fstream>
#include <vector>
#include <string>

void part1(std::string);
void part2(std::string);

int main(){
    std::ifstream myfile("input.txt");

    std::string line;
    std::getline(myfile,line);

    part1(line);
    part2(line);

    return 0;
}

void part1(std::string line){
    char first, second, third, fourth;
    int final = 0;
    for(int i = 0; i < line.size(); i++){
        first = line[i];
        second = line[i + 1];
        third = line[i + 2];
        fourth = line[i + 3];
        if(first == second || first == third || first == fourth || second == third || second == fourth || third == fourth){
            
        }else{
            final = i + 4;
            break;
        }
    }
    std::cout << "part1: " << final << std::endl;
}

void part2(std::string line){
    int final = 0;
    bool isSame = false;
    for(int i = 0; i < line.size(); i++){
        isSame = false;
        for(int j = 0; j < 14; j++){
            for(int k = 0; k < 14; k++){
                if(line[i + j] == line[i + k] && i + j != i + k){
                    isSame = true;
                }
            }
        }
        
        if(!isSame){
            final = i + 14;
            std::cout << "part2: " << final << std::endl;
            for(int j = i; j < i + 14; j++){
                std::cout << line[j];
            }
            std::cout << std::endl;
            return;
        }
    }
}