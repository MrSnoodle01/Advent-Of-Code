#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

long int diff1(long int a, long int b){
    return b - a;
}

long int diff2(long int a, long int b){
    return a - b;
}

void part1(){
    std::vector<std::string> lines;
    std::ifstream myfile("input.txt");
    std::string line;
    while(std::getline(myfile, line)){
        lines.push_back(line);
    }

    long int final = 0;
    for(int a = 0; a < lines.size(); a++){
        std::stringstream stream(lines[a]);
        std::vector<std::vector<long int>> values;
        std::vector<long int> temp;
        long int n = 0;
        while(stream >> n){
            temp.push_back(n);
        }
        values.push_back(temp);

        bool notDone = true;
        int index = 0;
        while(notDone){ // add all differences to values array
            notDone = false;
            temp.clear();
            if(values[index].size() == 1){
                temp.push_back(0);
            }else{
                for(int i = 0; i < values[index].size() - 1; i++){
                    temp.push_back(diff1(values[index][i], values[index][i + 1]));
                } 
            }
              
            values.push_back(temp);
            for(int j = 0; j < temp.size(); j++){
                if(temp[j] != 0){
                    notDone = true;
                }
            }
            index++;
        }
        values[values.size() - 1].push_back(0); // initial addition of zero
        for(int i = values.size() - 2; i >= 0; i--){
            values[i].push_back(values[i + 1][values[i + 1].size() - 1] + values[i][values[i].size() - 1]);
        }
        final += values[0][values[0].size() - 1];
    }

    std::cout << "part 1 final: " << final << std::endl;
}

void part2(){
    std::vector<std::string> lines;
    std::ifstream myfile("input.txt");
    std::string line;
    while(std::getline(myfile, line)){
        lines.push_back(line);
    }

    long int final = 0;
    for(int a = 0; a < lines.size(); a++){
        std::stringstream stream(lines[a]);
        std::vector<std::vector<long int>> values;
        std::vector<long int> temp;
        long int n = 0;
        while(stream >> n){
            temp.push_back(n);
        }
        values.push_back(temp);

        bool notDone = true;
        int index = 0;
        while(notDone){ // add all differences to values array
            notDone = false;
            temp.clear();
            if(values[index].size() == 1){
                temp.push_back(0);
            }else{
                for(int i = 0; i < values[index].size() - 1; i++){
                    temp.push_back(diff2(values[index][i], values[index][i + 1]));
                } 
            }
              
            values.push_back(temp);
            for(int j = 0; j < temp.size(); j++){
                if(temp[j] != 0){
                    notDone = true;
                }
            }
            index++;
        }
        values[values.size() - 1].push_back(0); // initial addition of zero
        for(int i = values.size() - 2; i >= 0; i--){
            values[i].push_back(values[i + 1][values[i + 1].size() - 1] + values[i][0]);
        }
        final += values[0][values[0].size() - 1];
    }

    std::cout << "part 2 final: " << final << std::endl;
}

int main(){
    part1();
    part2();
}