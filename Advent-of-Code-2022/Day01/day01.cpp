#include <iostream>
#include <vector>
#include <fstream>
#include <string>

int main(){
    std::vector<int> inputs;

    std::ifstream myfile("input.txt");

    std::string line;
    int temp = 0;
     while(std::getline(myfile, line)){
        if(line.size() == 1){
            inputs.push_back(temp);
            temp = 0;
        }else{
            temp += std::stoi(line);
        }
    }
    inputs.push_back(temp);

    temp = 0;
    int iterator = 0, final = 0;
    for(int j = 0; j < 3; j++){
        temp = 0;
        for(int i = 0; i < inputs.size(); i++){
            if(inputs[i] > temp){
                temp = inputs[i];
                iterator = i;
            }
        } 
        final += temp;
        inputs[iterator] = 0;
    }
    
    std::cout << final << std::endl;

    return 0;
}