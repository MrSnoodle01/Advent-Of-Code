#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_map>
#include <ctype.h>

//this code is absolute fucking garbage
//but after what i went through to get it working
//i'm not convinced i will ever come back to make it better 

class directory{
    public:
        std::string name;
        int size;
        std::vector<std::string> needs;
};

std::vector<std::string> lines;

void part1();
void part2();

int main(){
    std::ifstream myfile("input.txt");

    std::string line;
    while(getline(myfile, line)){
        lines.push_back(line);
    }

    part1();
    part2();

    return 0;
}

void part1(){
    //get vector of every directory
    std::vector<directory> directories;
    std::string name = "";
    for(int i = 0; i < lines.size() - 1; i++){
        if(lines[i][2] == 'c' && lines[i][5] != '.'){
            for(int j = 5; j < lines[i].size() - 1; j++){
                name += lines[i][j];
            }
            if(name != "/")
                name += '/';
            directory temp;
            temp.name = name;
            temp.size = 0;
            directories.push_back(temp);
        }else if(lines[i][5] == '.'){
            name.erase(name.size() - 1, 1);
            for(int j = name.size() - 1; j >= 0; j--){
                if(name[j] != '/'){
                    name.erase(name.size() - 1, 1);
                }else{
                    j = -1;
                }
            }
        }
    }

    std::string currentDir;
    for(int i = 0; i < lines.size(); i++){ 
        if(lines[i][0] == '$' && lines[i][2] == 'c' && lines[i][5] != '.'){ //updates current directory
            for(int j = 5; j < lines[i].size() - 1; j++){
                currentDir += lines[i][j];
            }
            if(currentDir != "/")
                currentDir += '/';
        }else if(lines[i][0] == 'd'){ //adds directory for later addition
            std::string temp;
            for(int j = 4; j < lines[i].size() - 1; j++){
                temp += lines[i][j];
            }
            temp += '/';

            for(int j = 0; j < directories.size(); j++){
                if(directories[j].name == currentDir){
                    directories[j].needs.push_back(currentDir + temp);
                }
            }
        }else if(lines[i][0] != '$' && lines[i][5] != '.'){ //adds size to directory
            std::string size = "";
            for(int j = 0; j < lines[i].size(); j++){
                if(isdigit(lines[i][j])){ //fills size up with size
                    size += lines[i][j];
                }
            }

            for(int j = 0; j < directories.size(); j++){
                if(directories[j].name == currentDir){
                    directories[j].size += stoi(size);
                }
            }
        }else if(lines[i][5] == '.'){
            currentDir.erase(currentDir.size() - 1, 1);
            for(int j = currentDir.size() - 1; j >= 0; j--){
                if(currentDir[j] != '/'){
                    currentDir.erase(currentDir.size() - 1, 1);
                }else{
                    j= -1;
                }
            }
        }
    }

    for(int i = directories.size() - 1; i >= 0; i--){
        if(!directories[i].needs.empty()){
            for(int j = 0; j < directories[i].needs.size(); j++){
                for(int k = 0; k < directories.size(); k++){
                    if(directories[k].name == directories[i].needs[j]){
                        directories[i].size += directories[k].size;
                    }
                }
            }
        }
    }

    int final = 0;
    for(int i = 0; i < directories.size(); i++){
        if(directories[i].size <= 100000){
            final += directories[i].size;
        }
    }

    std::cout << "part1: " << final << std::endl;
}   

void part2(){
    //get vector of every directory
    std::vector<directory> directories;
    std::string name = "";
    for(int i = 0; i < lines.size() - 1; i++){
        if(lines[i][2] == 'c' && lines[i][5] != '.'){
            for(int j = 5; j < lines[i].size() - 1; j++){
                name += lines[i][j];
            }
            if(name != "/")
                name += '/';
            directory temp;
            temp.name = name;
            temp.size = 0;
            directories.push_back(temp);
        }else if(lines[i][5] == '.'){
            name.erase(name.size() - 1, 1);
            for(int j = name.size() - 1; j >= 0; j--){
                if(name[j] != '/'){
                    name.erase(name.size() - 1, 1);
                }else{
                    j = -1;
                }
            }
        }
    }

    std::string currentDir;
    for(int i = 0; i < lines.size(); i++){ 
        if(lines[i][0] == '$' && lines[i][2] == 'c' && lines[i][5] != '.'){ //updates current directory
            for(int j = 5; j < lines[i].size() - 1; j++){
                currentDir += lines[i][j];
            }
            if(currentDir != "/")
                currentDir += '/';
        }else if(lines[i][0] == 'd'){ //adds directory for later addition
            std::string temp;
            for(int j = 4; j < lines[i].size() - 1; j++){
                temp += lines[i][j];
            }
            temp += '/';

            for(int j = 0; j < directories.size(); j++){
                if(directories[j].name == currentDir){
                    directories[j].needs.push_back(currentDir + temp);
                }
            }
        }else if(lines[i][0] != '$' && lines[i][5] != '.'){ //adds size to directory
            std::string size = "";
            for(int j = 0; j < lines[i].size(); j++){
                if(isdigit(lines[i][j])){ //fills size up with size
                    size += lines[i][j];
                }
            }

            for(int j = 0; j < directories.size(); j++){
                if(directories[j].name == currentDir){
                    directories[j].size += stoi(size);
                }
            }
        }else if(lines[i][5] == '.'){
            currentDir.erase(currentDir.size() - 1, 1);
            for(int j = currentDir.size() - 1; j >= 0; j--){
                if(currentDir[j] != '/'){
                    currentDir.erase(currentDir.size() - 1, 1);
                }else{
                    j= -1;
                }
            }
        }
    }

    for(int i = directories.size() - 1; i >= 0; i--){
        if(!directories[i].needs.empty()){
            for(int j = 0; j < directories[i].needs.size(); j++){
                for(int k = 0; k < directories.size(); k++){
                    if(directories[k].name == directories[i].needs[j]){
                        directories[i].size += directories[k].size;
                    }
                }
            }
        }
    }

    //get amount of used space
    int usedSpace = directories[0].size;
    //get unused space
    int unUsedSpace = 70000000 - directories[0].size;

    int best = 70000000;
    for(int i = 0; i < directories.size(); i++){
        if(directories[i].size < unUsedSpace && directories[i].size >= 30000000 - unUsedSpace){
            if(directories[i].size < best){
                best = directories[i].size;
            }
        }
    }
    std::cout << "part2: " << best << std::endl;
}