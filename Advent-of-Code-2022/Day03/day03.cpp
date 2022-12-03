#include <iostream>
#include <fstream>
#include <vector>
#include <string>

void part1(std::vector<std::string>);
void part2(std::vector<std::string>);

int main(){
    std::ifstream myfile("input.txt");
    std::string line;

    std::vector<std::string> ruckSack;

    while(std::getline(myfile, line)){
        ruckSack.push_back(line);
    }

    part1(ruckSack);
    part2(ruckSack);

    return 0;
}

void part1(std::vector<std::string> ruckSack){
    std::vector<char> common;
    std::vector<char> firstHalf;
    std::vector<char> secondHalf;
    std::vector<char> same;
    std::vector<char> tempSame;

    //go through each ruckSack
    for(int i = 0; i < ruckSack.size(); i++){
        firstHalf.clear();
        secondHalf.clear();
        int temp;
        //get two halfs
        for(int j = 0; j < ruckSack[i].size() / 2; j++){
            firstHalf.push_back(ruckSack[i][j]);
            temp = j;
        }
        for(int j = temp + 1; j < ruckSack[i].size(); j++){
            secondHalf.push_back(ruckSack[i][j]);
        }
        
        //find similarities
        for(int a = 0; a < firstHalf.size(); a++){
            for(int j = 0; j < secondHalf.size(); j++){
                if(firstHalf[a] == secondHalf[j]){
                    bool isIn = false;
                    for(int k = 0; k < tempSame.size(); k++){
                        if(firstHalf[a] == tempSame[k]){
                            isIn = true;
                        }
                    }
                    if(!isIn){
                        tempSame.push_back(firstHalf[a]);
                    }
                }
            }
        }
        //using tempsame to ensure no duplicates in same
        for(int j = 0; j < tempSame.size(); j++){
            same.push_back(tempSame[j]);
        }
        tempSame.clear();
    }

    //calculate priority
    int final = 0;
    for(int i = 0; i < same.size(); i++){
        if(same[i] > 96){
            final += same[i] - 96;
        }else{
            final += same[i] - 38;
        }
    }
    
    std::cout << "part 1: " << final << std::endl;
}

void part2(std::vector<std::string> ruckSack){
    std::vector<char> common;
    std::vector<char> one;
    std::vector<char> two;
    std::vector<char> three;

    bool isIn;
    for(int i = 0; i < ruckSack.size(); i+=3){
        one.clear();
        two.clear();
        three.clear();

        //get each unique char in first rucksack
        for(int j = 0; j < ruckSack[i].size(); j++){
            for(int k = 0; k < one.size(); k++){
                isIn = false;
                if(ruckSack[i][j] == one[k]){
                    isIn = true;
                }
            }
            if(!isIn){
                one.push_back(ruckSack[i][j]);
            }
        }

        //get each unique char in second rucksack
        for(int j = 0; j < ruckSack[i + 1].size(); j++){
            for(int k = 0; k < two.size(); k++){
                isIn = false;
                if(ruckSack[i + 1][j] == two[k]){
                    isIn = true;
                }
            }
            if(!isIn){
                two.push_back(ruckSack[i + 1][j]);
            }
        }

        //get each unique char in third rucksack
        for(int j = 0; j < ruckSack[i + 2].size(); j++){
            for(int k = 0; k < three.size(); k++){
                isIn = false;
                if(ruckSack[i + 2][j] == three[k]){
                    isIn = true;
                }
            }
            if(!isIn){
                three.push_back(ruckSack[i + 2][j]);
            }
        }

        //find shared value from rucksacks
        for(int j = 0; j < one.size(); j++){
            for(int a = 0; a < two.size(); a++){
                for(int b = 0; b < three.size(); b++){
                    if(one[j] == two[a] && two[a] == three[b] && one[j] != 13){
                        common.push_back(one[j]);
                        j = one.size();
                        a = two.size();
                        b = three.size();
                    }
                }
            }
        }
    }   

    //calculate priority
    int final = 0;
    for(int i = 0; i < common.size(); i++){
        if(common[i] > 96){
            final += common[i] - 96;
        }else{
            final += common[i] - 38;
        }
    }

    std::cout << "part 2: " << final << std::endl;
}