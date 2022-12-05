#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stack>
#include <sstream>

std::vector<int> from;
std::vector<int> count;
std::vector<int> to;

std::vector<std::stack<char>> stacks;

void part1();
void part2();

int main(){
    std::ifstream myfile("input.txt");

    std::vector<std::string> crates;
    std::string line, temp;
    while(std::getline(myfile, line)){

        //get directions for where to move crates
        if(line[0] == 'm'){
            std::istringstream ss(line);

            ss.ignore(5);

            ss >> temp;
            count.push_back(stoi(temp));
            ss.ignore(6);

            ss >> temp;
            from.push_back(stoi(temp));
            ss.ignore(4);

            ss >> temp;
            to.push_back(stoi(temp));
        }else{
            crates.push_back(line);
        }
    }

    //get number of different crates
    int numCrates = 0;
    for(int i = 0; i < crates.size(); i++){
        if(crates[i][1] == '1'){
            for(int j = 0; j < crates[i].size() - 1; j++){
                if(crates[i][j] != ' '){
                    numCrates = crates[i][j] - '0';
                }
            }
        }
    }

    //initializing stacks
    std::stack<char> tempStack;
    for(int i = 0; i < numCrates; i++){
        stacks.push_back(tempStack);
    }

    //put crates into stack
    for(int i = 0; i < crates.size() - 2; i++){
        int count = 0;
        for(int j = 1; j < crates[i].size(); j+=4){
            if(crates[i][j] != ' '){
                stacks[count].push(crates[i][j]);
            }
            count++;
        }
    }

    //shit gets put on in reverse
    //so this puts it in normal order
    for(int i = 0; i < stacks.size(); i++){
        while(!stacks[i].empty()){
            tempStack.push(stacks[i].top());
            stacks[i].pop();
        }
        stacks[i] = tempStack;
        while(!tempStack.empty()){
            tempStack.pop();
        }
    }

    // part1();
    part2();
    
    return 0;
}

void part1(){
    for(int i = 0; i < from.size(); i++){
        for(int j = 0; j < count[i]; j++){
            stacks[to[i] - 1].push(stacks[from[i] - 1].top());
            stacks[from[i] - 1].pop();
        }
    }

    std::cout << "part1: ";
    for(int i = 0; i < stacks.size(); i++){
        std::cout << stacks[i].top();
    }
    std::cout << std::endl;
}

void part2(){
    for(int i = 0; i < from.size(); i++){
        std::vector<char> tempVector;
        for(int j = 0; j < count[i]; j++){
            tempVector.push_back(stacks[from[i] - 1].top());
            stacks[from[i] - 1].pop();
        }
        for(int j = tempVector.size() - 1; j >= 0; j--){
            stacks[to[i] - 1].push(tempVector[j]);
        }
    }
    
    std::cout << "part2: ";
    for(int i = 0; i < stacks.size(); i++){
        std::cout << stacks[i].top();
    }
    std::cout << std::endl;
}