#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <ctype.h>

std::vector<std::string> grid;

void part1();
void part2();

int main(){
    std::ifstream myfile("input.txt");

    std::string line;
    while(std::getline(myfile, line)){
        grid.push_back(line);
    }

    part1();
    part2();
}

void part1(){
    int visible = 0;
    for(int i = 0; i < grid.size(); i++){ //iterate through each row
        for(int j = 0; j < grid[i].size(); j++){ //iterate through each char in row
            if(isdigit(grid[i][j])){
                bool left = true, right = true, up = true, down = true;

                for(int a = 0; a < grid[i].size(); a++){ //to check rows
                    if(grid[i][a] >= grid[i][j]){
                        if(a < j){
                            left = false;
                        }else if(j < a){
                            right = false;
                        }
                    }
                }

                for(int b = 0; b < grid.size(); b++){ //check columns
                    if(grid[b][j] >= grid[i][j]){
                        if(b < i){
                            up = false;
                        }else if(i < b){
                            down = false;
                        }
                    }
                }
                
                if(left || right || up || down){
                    visible++;
                }
            }
        }
    }
    std::cout << "part1: " << visible << std::endl;
}

void part2(){
    int scenicScore = 0;
    for(int i = 0; i < grid.size(); i++){ //iterate through each row
        for(int j = 0; j < grid[i].size(); j++){ //iterate through each char in row
            if(isdigit(grid[i][j])){
                int tempScore = 0;
                int left = 0, right = 0, up = 0, down = 0;

                if(i + 1 < grid.size()){
                   for(int a = i + 1; a < grid.size(); a++){ //check right
                        if(grid[a][j] < grid[i][j]){
                            right++;
                        }else{
                            right++;
                            a = grid[i].size();
                        }
                    } 
                }

                if(i - 1 > -1){
                    for(int a = i - 1; a >= 0; a--){ //check left
                        if(grid[a][j] < grid[i][j]){
                            left++;
                        }else{
                            left++;
                            a = -1;
                        }
                    }
                }

                if(j + 1 < grid.size()){
                    for(int a = j + 1; a < grid.size(); a++){ //check down
                        if(grid[i][a] < grid[i][j]){
                            down++;
                        }else{
                            down++;
                            a = grid.size();
                        }
                    }
                }

                if(j - 1 > -1){
                    for(int a = j - 1; a >= 0; a--){ //check up
                        if(grid[i][a] < grid[i][j]){
                            up++;
                        }else{
                            up++;
                            a = -1;
                        }
                    }
                }
                
                tempScore = up * down * left * right;
                if(tempScore > scenicScore)
                    scenicScore = tempScore;
            }
        }
    }
    std::cout << "part2: " << scenicScore << std::endl;
}