#include <iostream>
#include <vector>
#include <fstream>
#include <string>

int main(){
    std::vector<int> inputs;

    std::ifstream myfile("input.txt");

    std::string line;
    int temp = 0;
    if(myfile.is_open()){
        while(std::getline(myfile, line)){
            if(line.size() < 2){
                inputs.push_back(temp);
                temp = 0;
            }else{
                temp += std::stoi(line);
            }
        }
        inputs.push_back(temp);
        myfile.close();
    }

    temp = 0;
    int temp2 = 0;
    int final = 0;
    for(int j = 0; j < 3; j++){
        temp = 0;
        temp2 = 0;
        for(int i = 0; i < inputs.size(); i++){
            if(inputs[i] > temp){
                temp = inputs[i];
                temp2 = i;
            }
        } 
        final += temp;
        inputs[temp2] = 0;
    }
    

    std::cout << final << std::endl;

    return 0;
}