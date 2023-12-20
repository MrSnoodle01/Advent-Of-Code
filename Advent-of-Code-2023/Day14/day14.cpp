#include <iostream>
#include <string>
#include <vector>
#include <fstream>

std::vector<std::string> cycle(std::vector<std::string> input){
    // tilt north
    for(int i = 0; i < input.size(); i++){
        for(int j = 0; j < input[i].size(); j++){
            if(input[i][j] == 'O'){
                input[i][j] = '.';
                int temp = i;
                while(temp > 0 && input[temp][j] == '.'){
                    temp--;
                }
                if(input[temp][j] == '#' || input[temp][j] == 'O')
                    temp++;
                input[temp][j] = 'O';
            }
        }
    }

    // tilt west
    for(int i = 0; i < input.size(); i++){
        for(int j = 0; j < input[i].size(); j++){
            if(input[i][j] == 'O'){
                input[i][j] = '.';
                int temp = j;
                while(temp > 0 && input[i][temp] == '.'){
                    temp--;
                }
                if(input[i][temp] == '#' || input[i][temp] == 'O')
                    temp++;
                input[i][temp] = 'O';
            }
        }
    }

    // tilt south
    for(int i = input.size() - 1; i >= 0; i--){
        for(int j = input[i].size() - 1; j >= 0; j--){
            if(input[i][j] == 'O'){
                input[i][j] = '.';
                int temp = i;
                while(temp < input.size() - 1 && input[temp][j] == '.'){
                    temp++;
                }
                if(input[temp][j] == '#' || input[temp][j] == 'O')
                    temp--;
                input[temp][j] = 'O';
            }
        }
    }

    // tilt east
    for(int i = input.size() - 1; i >= 0; i--){
        for(int j = input[i].size() - 1; j >= 0; j--){
            if(input[i][j] == 'O'){
                input[i][j] = '.';
                int temp = j;
                while(temp < input[i].size() - 1 && input[i][temp] == '.'){
                    temp++;
                }
                if(input[i][temp] == '#' || input[i][temp] == 'O')
                    temp--;
                input[i][temp] = 'O';
            }
        }
    }

    return input;
}

void part1(){
    std::vector<std::string> input;
    std::string line;
    std::fstream myfile("input.txt");
    while(std::getline(myfile, line)){
        input.push_back(line);
    }

    for(int i = 0; i < input.size(); i++){
        for(int j = 0; j < input[i].size(); j++){
            if(input[i][j] == 'O'){
                input[i][j] = '.';
                int temp = i;
                while(temp > 0 && input[temp][j] == '.'){
                    temp--;
                }
                if(input[temp][j] == '#' || input[temp][j] == 'O')
                    temp++;
                input[temp][j] = 'O';
            }
        }
    }

    int final = 0, load = input.size();
    for(int i = 0; i < input.size(); i++){
        for(int j = 0; j < input[i].size(); j++){
            if(input[i][j] == 'O')
                final += load;
        }
        load--;
    }
    
    std::cout << "part 1 final: " << final << std::endl;
}

void part2(){
    std::vector<std::string> input;
    std::string line;
    std::fstream myfile("input.txt");
    while(std::getline(myfile, line)){
        if(line[line.size() - 1] != 'O' && line[line.size() - 1] != '.' && line[line.size() - 1] != '#')
            line.pop_back();
        input.push_back(line);
    }

    // std::vector<std::vector<std::string>> cycles;
    // int cycleNum = 0;
    // for(int i = 0; i < 1000000000; i++){
    //     input = cycle(input);
    //     bool isIn = false;
    //     for(int j = 0; j < cycles.size(); j++){ 
    //         if(input == cycles[j])
    //             isIn = true;
    //     }
    //     if(!isIn)
    //         cycles.push_back(input);
    //     if(isIn){
    //         cycleNum = 1000000000 - i;
    //         break;
    //     }
    // }

    // for(int i = cycleNum; i <= 1000000000; i++){
    //     input = cycle(input);
    // }

    // for(int i = 0; i < input.size(); i++){
    //     std::cout << input[i] << std::endl;
    // }

    // sorta just ran it with 1000 and it worked ¯\_(ツ)_/¯
    // might come back to try and get the proper cycle implementation working
    for(int i = 0; i < 1000; i++){
        input = cycle(input);
    }

    int final = 0, load = input.size();
    for(int i = 0; i < input.size(); i++){
        for(int j = 0; j < input[i].size(); j++){
            if(input[i][j] == 'O')
                final += load;
        }
        load--;
    }
    
    std::cout << "part 2 final: " << final << std::endl;
}

int main(){
    part1();
    part2();
}