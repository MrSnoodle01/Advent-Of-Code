#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

class monkey{
    public:
        std::vector<long> items;
        std::string operation;
        std::string operationNum;
        int test;
        int ifTrue;
        int ifFalse;
        int inspectNum;
};

std::vector<monkey> monkeys;

void part1();
void part2();

int main(){
    std::fstream myfile("input.txt");

    int monkeyCount = 0;
    std::string line, tempString;
    monkey tempMonkey;
    tempMonkey.inspectNum = 0;
    while(std::getline(myfile, line)){
        monkeys.push_back(tempMonkey);
        for(int i = 0; i < 6; i++){
            std::stringstream ss(line);
            if(line[0] == 'M'){

            }else if(line[2] == 'S'){ //get items
                ss >> tempString;
                ss >> tempString;

                while(ss >> tempString){
                    if(tempString.back() == ',')
                        tempString.pop_back();
                    monkeys[monkeyCount].items.push_back(stoi(tempString));
                }
            }else if(line[2] == 'O'){
                ss.ignore(23);

                ss >> tempString;
                monkeys[monkeyCount].operation = tempString;

                ss >> tempString;
                monkeys[monkeyCount].operationNum = tempString;
            }else if(line[2] == 'T'){
                ss >> tempString;
                ss >> tempString;
                ss >> tempString;

                ss >> tempString;
                monkeys[monkeyCount].test = stoi(tempString);
            }else if(line[7] == 't'){
                ss.ignore(29);

                ss >> tempString;
                monkeys[monkeyCount].ifTrue = stoi(tempString);
            }else if(line[7] == 'f'){
                ss.ignore(30);

                ss >> tempString;
                monkeys[monkeyCount].ifFalse = stoi(tempString);
            }
            std::getline(myfile,line);
        }
        monkeyCount++;
    }

    // part1();
    part2();

    return 0;
}

void part1(){
    for(int i = 0; i < 20; i++){ //num rounds
        for(int j = 0; j < monkeys.size(); j++){ //do each monkey turn
            for(int k = 0; k < monkeys[j].items.size(); k++){ //get each item from monkey
                monkeys[j].inspectNum++;
                if(monkeys[j].operation == "+"){ 
                    // monkeys[j].items[k] = add(monkeys[j].items[k], monkeys[j].operationNum);
                    monkeys[j].items[k] += stoi(monkeys[j].operationNum);
                }else if(monkeys[j].operation == "*"){
                    if(monkeys[j].operationNum == "old"){
                        // monkeys[j].items[k] = multiply(monkeys[j].items[k], monkeys[j].items[k]);
                        monkeys[j].items[k] *= monkeys[j].items[k];
                    }else{
                        // monkeys[j].items[k] = multiply(monkeys[j].items[k], monkeys[j].operationNum);
                        monkeys[j].items[k] *= stoi(monkeys[j].operationNum);
                    }
                }


                // monkeys[j].items[k] = divide(monkeys[j].items[k], 3);
                monkeys[j].items[k] /= 3;

                //mod(monkeys[j].items[k], monkeys[j].test) == 0
                if(monkeys[j].items[k] % monkeys[j].test == 0){
                    monkeys[monkeys[j].ifTrue].items.push_back(monkeys[j].items[k]);
                    monkeys[j].items.erase(monkeys[j].items.begin());
                    k--;
                }else{
                    monkeys[monkeys[j].ifFalse].items.push_back(monkeys[j].items[k]);
                    monkeys[j].items.erase(monkeys[j].items.begin());
                    k--;
                }
            }
        }
    }

    int final = 0, top = 0, second = 0;
    for(int i = 0; i < monkeys.size(); i++){
        if(monkeys[i].inspectNum > top){
            top = monkeys[i].inspectNum;
        }else if(monkeys[i].inspectNum > second){
            second = monkeys[i].inspectNum;
        }
    }

    for(int i = 0; i < monkeys.size(); i++){
        if(monkeys[i].inspectNum > top){
            top = monkeys[i].inspectNum;
        }else if(monkeys[i].inspectNum > second && monkeys[i].inspectNum != top){
            second = monkeys[i].inspectNum;
        }
    }
    final = top * second;
    std::cout << "part1: " << final << std::endl;
}

void part2(){
    int superMod = 1;
    for(int i = 0; i < monkeys.size(); i++){
        superMod *= monkeys[i].test;
    }
    for(int i = 0; i < 10000; i++){ //num rounds
        for(int j = 0; j < monkeys.size(); j++){ //do each monkey turn
            for(int k = 0; k < monkeys[j].items.size(); k++){ //get each item from monkey
                monkeys[j].inspectNum++;
                if(monkeys[j].operation == "+"){ 
                    monkeys[j].items[k] += stoi(monkeys[j].operationNum);
                }else if(monkeys[j].operation == "*"){
                    if(monkeys[j].operationNum == "old"){
                        monkeys[j].items[k] *= monkeys[j].items[k];
                    }else{
                        monkeys[j].items[k] *= stoi(monkeys[j].operationNum);
                    }
                    monkeys[j].items[k] = monkeys[j].items[k] % superMod;
                }

               

                if(monkeys[j].items[k] % monkeys[j].test == 0){
                    monkeys[monkeys[j].ifTrue].items.push_back(monkeys[j].items[k]);
                    monkeys[j].items.erase(monkeys[j].items.begin());
                    k--;
                }else{
                    monkeys[monkeys[j].ifFalse].items.push_back(monkeys[j].items[k]);
                    monkeys[j].items.erase(monkeys[j].items.begin());
                    k--;
                }
            }
        }
    }

    long long final = 0, top = 0, second = 0;
    for(int i = 0; i < monkeys.size(); i++){
        if(monkeys[i].inspectNum > top){
            top = monkeys[i].inspectNum;
        }else if(monkeys[i].inspectNum > second){
            second = monkeys[i].inspectNum;
        }
    }

    for(int i = 0; i < monkeys.size(); i++){
        if(monkeys[i].inspectNum > top){
            top = monkeys[i].inspectNum;
        }else if(monkeys[i].inspectNum > second && monkeys[i].inspectNum != top){
            second = monkeys[i].inspectNum;
        }
    }

    final = top * second;
    std::cout << "part2: " << final << std::endl;
}