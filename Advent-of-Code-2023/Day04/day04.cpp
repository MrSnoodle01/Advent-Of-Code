#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

void part1(){
    std::vector<std::string> input;
    std::vector<int> myNums;
    std::vector<int> winningNums;

    std::ifstream myfile("input.txt");

    std::string line;
    bool first = true;
    bool isSplit = false;
    int final = 0;

    while(myfile >> line){
        if(line == "Card" && first == false){
            // reset everything and add to final
            isSplit = false;
            int totalSame = 0;
            for(int i = 0; i < winningNums.size(); i++){
                for(int j = 0; j < myNums.size(); j++){
                    if(winningNums[i] == myNums[j]){
                        totalSame++;
                    }
                }
            }
            winningNums.clear();
            myNums.clear();
            if(totalSame > 0){
                final += pow(2, totalSame - 1);
            }
            myfile >> line;
        }else if(line == "Card"){
            first = false;
            myfile >> line;
        }else if(line != "Card"){
            if(line == "|"){
                isSplit = true;
            }else if(!isSplit){
                winningNums.push_back(stoi(line));
            }else if(isSplit){
                myNums.push_back(stoi(line));
            }
        }
    }

    std::cout << "part 1 final: " << final << std::endl;
}

void part2(){
    std::vector<std::string> input;
    std::vector<int> myNums;
    std::vector<int> winningNums;

    std::ifstream myfile("input.txt");

    std::vector<int> cards;
    std::vector<std::string> temp;
    std::string line;
    while(getline(myfile, line)){
        temp.push_back(line);
    }
    for(int i = 0; i < temp.size() + 1; i++){
        cards.push_back(1);
    }

    bool first = true;
    bool isSplit = false;
    int final = 0;
    int currentCard = 0;
    std::ifstream myfile2("input.txt");

    while(myfile2 >> line){
        if(line == "Card" && first == false){
            // reset everything and add to final
            isSplit = false;
            int totalSame = 0;
            for(int i = 0; i < winningNums.size(); i++){
                for(int j = 0; j < myNums.size(); j++){
                    if(winningNums[i] == myNums[j]){
                        totalSame++;
                    }
                }
            }
            winningNums.clear();
            myNums.clear();
            myfile2 >> line;

            for(int i = 1; i <= totalSame; i++){
                cards[currentCard + i] += cards[currentCard];
            }
            currentCard++;
        }else if(line == "Card"){
            first = false;
            myfile2 >> line;
            currentCard++;
        }else if(line != "Card"){
            if(line == "|"){
                isSplit = true;
            }else if(!isSplit){
                winningNums.push_back(stoi(line));
            }else if(isSplit){
                myNums.push_back(stoi(line));
            }
        }
    }
    for(int i = 1; i < cards.size(); i++){
        final += cards[i];
    }

    std::cout << "part 2 final: " << final << std::endl;
}

int main(){

    part1();
    part2();
}