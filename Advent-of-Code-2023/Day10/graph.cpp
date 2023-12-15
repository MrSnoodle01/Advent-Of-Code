#include <iostream>
#include <string>
#include <vector>

int main(){
    std::vector<std::string> graph;
    std::string temp;
    for(int i = 1; i < 10; i++){
        temp += std::to_string(i);
        if(i % 3 == 0){
            graph.push_back(temp);
            temp.clear();
        }
    }

    for(int i = 0; i < graph.size(); i++){
        for(int j = 0; j < graph[i].size(); j++){
            std::cout << graph[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    std::cout << "1,1 is: " << graph[1][1] << std::endl;
    std::cout << "1,0 is: " << graph[1][0] << std::endl;
    std::cout << "0,1 is: " << graph[0][1] << std::endl;
    std::cout << "1,2 is: " << graph[1][2] << std::endl;
    std::cout << "2,1 is: " << graph[2][1] << std::endl;
}