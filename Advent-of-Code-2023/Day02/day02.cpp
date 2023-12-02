#include <iostream>
#include <string>
#include <vector>
#include <fstream>

const int totalRed = 12, totalGreen = 13, totalBlue = 14;

void part1(std::vector<std::string> input){
    int final = 0;
    
    for(int i = 0; i < input.size(); i++){
        int blueNum = 0, redNum = 0, greenNum = 0;
        int gameNum = 0;
        bool isSemi = false;
        std::string currentDigit = "";
        std::string temp = "";
        for(int j = 5; j < input[i].size(); j++){
            // get game number
            if(input[i][j] == ':'){
                isSemi = true;
                gameNum = std::stoi(temp);
                temp = "";
            }
            if(!isSemi){
                temp += input[i][j];
            }

            if(isdigit(input[i][j]) && isSemi){
                currentDigit += input[i][j];
            }

            // get each game and parse input accordingly
            if(isdigit(input[i][j]) && input[i][j + 1] == ' '){
                if(input[i][j + 2] == 'b'){
                    if(std::stoi(currentDigit) > blueNum){
                        blueNum = std::stoi(currentDigit); 
                    }
                    currentDigit = "";
                }else if(input[i][j + 2] == 'g'){
                    if(std::stoi(currentDigit) > greenNum){
                        greenNum = std::stoi(currentDigit);
                    }
                    currentDigit = "";
                }else if(input[i][j + 2] == 'r'){
                    if(std::stoi(currentDigit) > redNum){
                        redNum = std::stoi(currentDigit);
                    }
                    currentDigit = "";
                }
            }
        }
        if(blueNum <= totalBlue && greenNum <= totalGreen && redNum <= totalRed){
            final += gameNum;
        }
    }
    std::cout << final << std::endl;
}

void part2(std::vector<std::string> input){
    int final = 0;
    
    for(int i = 0; i < input.size(); i++){
        int blueNum = 0, redNum = 0, greenNum = 0;
        int gameNum = 0;
        bool isSemi = false;
        std::string currentDigit = "";
        std::string temp = "";
        for(int j = 5; j < input[i].size(); j++){
            // get game number
            if(input[i][j] == ':'){
                isSemi = true;
                gameNum = std::stoi(temp);
                temp = "";
            }
            if(!isSemi){
                temp += input[i][j];
            }

            if(isdigit(input[i][j]) && isSemi){
                currentDigit += input[i][j];
            }

            // get each game and parse input accordingly
            if(isdigit(input[i][j]) && input[i][j + 1] == ' '){
                if(input[i][j + 2] == 'b'){
                    if(std::stoi(currentDigit) > blueNum){
                        blueNum = std::stoi(currentDigit); 
                    }
                    currentDigit = "";
                }else if(input[i][j + 2] == 'g'){
                    if(std::stoi(currentDigit) > greenNum){
                        greenNum = std::stoi(currentDigit);
                    }
                    currentDigit = "";
                }else if(input[i][j + 2] == 'r'){
                    if(std::stoi(currentDigit) > redNum){
                        redNum = std::stoi(currentDigit);
                    }
                    currentDigit = "";
                }
            }
        }
        final += blueNum * greenNum * redNum;

    }
    std::cout << final << std::endl;
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