#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

class assignments {
    public:
        int lower;
        int upper;
};

void part1();
void part2();


std::vector<assignments> first;
std::vector<assignments> second;

int main(){

    std::ifstream myfile("input.txt");

    std::string line, temp;
    assignments tempas, tempas2;
    while(std::getline(myfile, line)){
        std::istringstream ss(line);
        
        ss >> tempas.lower;
        ss.ignore(1);
        ss >> tempas.upper;
        ss.ignore(1);
        ss >> tempas2.lower;
        ss.ignore(1);
        ss >>tempas2.upper;
        first.push_back(tempas);
        second.push_back(tempas2);
    }

    part1();
    part2();

    return 0;
}

void part1(){
    int numContains = 0;
    for(int i = 0; i < first.size(); i++){
        if(first[i].lower <= second[i].lower && first[i].upper >= second[i].upper){
            numContains++;
        }else if(second[i].lower <= first[i].lower && second[i].upper >= first[i].upper){
            numContains++;
        }
    }
    std::cout << "part1: " << numContains << std::endl;
}

void part2(){
    int overlaps = 0;
    for(int i = 0; i < first.size(); i++){
        if(first[i].upper >= second[i].lower && second[i].upper >= first[i].lower){
            overlaps++;
        }
    }
    std::cout << "part2: " << overlaps << std::endl;
}