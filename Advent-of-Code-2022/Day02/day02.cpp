#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>

void part1(std::vector<std::string>);
void part2(std::vector<std::string>);

int main(){

    std::ifstream myfile("input.txt");
    std::string line;
    std::vector<std::string> lines;

    //had to use temp var
    //some weird character at end of line kept fucking up the hashmap
    std::string temp;
    while(std::getline(myfile, line)){
        temp = "";
        temp += line[0];
        temp += line[1];
        temp += line[2];
        lines.push_back(temp);
    }

    part1(lines);
    part2(lines);

    return 0;
}

void part1(std::vector<std::string> lines){
    std::unordered_map<std::string, int> map;
    map["A X"] = 4;
    map["A Y"] = 8;
    map["A Z"] = 3;
    map["B Y"] = 5;
    map["B Z"] = 9;
    map["B X"] = 1;
    map["C Z"] = 6;
    map["C X"] = 7;
    map["C Y"] = 2;

    int final = 0;
    for(int i = 0; i < lines.size(); i++){
        final += map[lines[i]];
    }

    std::cout << "part 1: " << final << std::endl;
}

void part2(std::vector<std::string> lines){
    std::unordered_map<std::string, int> map;
    map["A X"] = 3;
    map["A Y"] = 4;
    map["A Z"] = 8;
    map["B Y"] = 5;
    map["B Z"] = 9;
    map["B X"] = 1;
    map["C Z"] = 7;
    map["C X"] = 2;
    map["C Y"] = 6;

    int final = 0;
    for(int i = 0; i < lines.size(); i++){
        final += map[lines[i]];
    }

    std::cout << "part 2: " << final << std::endl;
}