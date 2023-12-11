#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <unordered_map>

class node{
    public:
        std::string left;
        std::string right;
};

// find greatest common divisor
long int gcd(long int a, long int b){
    if (b == 0){
        return a;
    }
    return gcd(b, a % b);
}

void part1(){
    std::unordered_map<std::string, node> nodeMap;
    std::string rotations;

    std::string line;
    std::ifstream myfile("input.txt");
    myfile >> rotations;
    while(myfile >> line){
        std::string elementName = line;

        myfile >> line; // = 
        myfile >> line;
        line.erase(line.begin());
        line.erase(line.end() - 1);
        node temp;
        temp.left = line;

        myfile >> line;
        line.erase(line.end() - 1);
        temp.right = line;

        nodeMap[elementName] = temp;
    }

    int stepCounter = 0, rotationsCounter = 0;
    std::string currentElement = "AAA";
    while(true){
        if(currentElement == "ZZZ"){
            break;
        }   
        stepCounter++;
        
        if(rotations[rotationsCounter] == 'R'){
            currentElement = nodeMap[currentElement].right;
        }else if(rotations[rotationsCounter] == 'L'){
            currentElement = nodeMap[currentElement].left;
        }

        if(rotationsCounter == rotations.size() - 1){
            rotationsCounter = 0;
        }else{
            rotationsCounter++;
        }
    }
    std::cout << "part 1 final: " << stepCounter << std::endl;
}

void part2(){
    std::unordered_map<std::string, node> nodeMap;
    std::string rotations;
    std::vector<std::string> startNodes;

    std::string line;
    std::ifstream myfile("input.txt");
    myfile >> rotations;
    while(myfile >> line){
        std::string elementName = line;
        if(elementName[2] == 'A'){
            startNodes.push_back(elementName);
        }

        myfile >> line; // = 
        myfile >> line;
        line.erase(line.begin());
        line.erase(line.end() - 1);
        node temp;
        temp.left = line;

        myfile >> line;
        line.erase(line.end() - 1);
        temp.right = line;

        nodeMap[elementName] = temp;
    }

    int stepCounter = 0, rotationsCounter = 0;
    std::vector<std::string> currentElement;
    std::vector<int> elementPattern;
    for(int i = 0; i < startNodes.size(); i++){
        currentElement.push_back(startNodes[i]);
        elementPattern.push_back(0);
    }
   
    bool allZ = true;
    while(true){
        allZ = true;
        for(int i = 0; i < currentElement.size(); i++){ // check if all end in Z
            if(currentElement[i][2] == 'Z'){
                elementPattern[i] = stepCounter;
            }
        }
        bool allDone = true;
        for(int i = 0; i < elementPattern.size(); i++){
            if(elementPattern[i] == 0){
                allDone = false;
            }
        }
        if(allDone)
            break;
        stepCounter++;

        for(int i = 0; i < currentElement.size(); i++){
            if(rotations[rotationsCounter] == 'R'){
                currentElement[i] = nodeMap[currentElement[i]].right;
            }else if(rotations[rotationsCounter] == 'L'){
                currentElement[i] = nodeMap[currentElement[i]].left;
            }
        }

        if(rotationsCounter == rotations.size() - 1){
            rotationsCounter = 0;
        }else{
            rotationsCounter++;
        }
    }

    long int final = elementPattern[0];
    for(int i = 1; i < elementPattern.size(); i++){
        final = (((elementPattern[i] * final)) / (gcd(elementPattern[i], final)));
    }

    std::cout << "part 2 final: " << final << std::endl;

}

int main(){
    part1();
    part2();
}