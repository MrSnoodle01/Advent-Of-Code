#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

std::vector<std::string> cycle;
std::vector<int> value;

void part1();
void part2();

int main(){
    std::fstream myfile("input.txt");

    std::string line, tempString;
    while(std::getline(myfile, line)){
        std::stringstream ss(line);

        ss >> tempString;
        cycle.push_back(tempString);

        tempString = "test";
        ss >> tempString;
        if(tempString != "test"){
            value.push_back(stoi(tempString));
        }else{
            value.push_back(-3000); //if there is empty line
        }
    }

    part1();
    part2();

    return 0;
}

void part1(){
    std::vector<int> signalStrengths;
    int cycleCount = 0, signal = 1, specialCycle = 20;
    for(int i = 0; i < cycle.size(); i++){
        if(cycle[i] == "noop"){
            cycleCount++;
            if(cycleCount == specialCycle){
                int temp = signal * specialCycle;
                signalStrengths.push_back(temp);
                specialCycle += 40;
            }
        }else{
            for(int j = 0; j < 2; j++){
                cycleCount++;
                if(cycleCount == specialCycle){
                    int temp = signal * specialCycle;
                    signalStrengths.push_back(temp);
                    specialCycle += 40;
                }
            }
            signal += value[i];
        }
    }
    int final = 0;
    for(int i = 0; i < signalStrengths.size(); i++){
        final += signalStrengths[i];
    }
    std::cout << "part1: " << final << std::endl;
}

void part2(){
    std::vector<char> screen;
    int spritePosition = 1, cycleCount = 0, tempCycle = 0;

    for(int i = 0; i < cycle.size(); i++){
        if(cycle[i] == "noop"){
            tempCycle = cycleCount;
            if(cycleCount > 39){
                while(tempCycle > 39){
                    tempCycle -= 40;
                }
            }
            if(spritePosition == tempCycle || spritePosition + 1 == tempCycle || spritePosition - 1 == tempCycle){
                screen.push_back('#');
            }else{
                screen.push_back('.');
            }
            cycleCount++;
        }else{
            for(int j = 0; j < 2; j++){
                tempCycle = cycleCount;
                if(cycleCount > 39){
                    while(tempCycle > 39){
                        tempCycle -= 40;
                    }
                }
                if(spritePosition == tempCycle || spritePosition + 1 == tempCycle || spritePosition - 1 == tempCycle){
                    screen.push_back('#');
                }else{
                    screen.push_back('.');
                }
                cycleCount++;
            }
            spritePosition += value[i];
        }
    }   
    for(int i = 0; i < screen.size(); i++){
        if(i % 40 == 0){
            std::cout << std::endl;
        }
        std::cout << screen[i];
    }
    std::cout << std::endl;
}