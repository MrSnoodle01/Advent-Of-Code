#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <climits>

class pair{
    public:
        std::string first;
        std::string second;
};

std::vector<pair> pairs;
std::vector<bool> order; //if pairs are in right order

std::vector<char> getList(std::string, int);
void part1();
void part2();

int main(){ 
    std::fstream myfile("testinput.txt");

    std::string line;
    int place = 0;
    pair tempPair;
    while(std::getline(myfile,line)){   
        if(line.back() != ']')
            line.pop_back();
        if(line.size() > 1){
            if(place == 0){
                tempPair.first = line;
                place = 1;
            }else if(place == 1){
                tempPair.second = line;
                pairs.push_back(tempPair);
                place = 0;
            }
        }
    }

    for(int i = 0; i < pairs.size(); i++){
        order.push_back(true);
    }

    part1();
    part2();

    return 0;
}

void part1(){
    for(int i = 0; i < pairs.size(); i++){ //iterate through each pair
        for(int j = 0; j < INT_MAX; j++){ //iterate through each character INT_MAX for different sizes between first&second
            if(j > pairs[i].first.size())
                break;
            if(j > pairs[i].second.size())
                order[i] = false;
                break;

                //make function for each unique case
        }
    }

    // for(int i = 0; i < pairs.size(); i++){
    //     int firstItems = 0, secondItems = 0;
    //     for(int j = 1; j < pairs[i].first.size() - 1; j++){
    //         if(pairs[i].first[j] != '[' && pairs[i].first[j] != ','){
    //             firstItems++;
    //         }else if(pairs[i].first[j] == '['){
    //             firstItems++;
    //             while(pairs[i].first[j] != ']'){
    //                 j++;
    //             }
    //         }
    //     }

    //     for(int j = 1; j < pairs[i].second.size() - 1; j++){
    //         if(pairs[i].second[j] != '[' && pairs[i].second[j] != ','){
    //             secondItems++;
    //         }else if(pairs[i].second[j] == '['){
    //             secondItems++;
    //             while(pairs[i].second[j] != ']'){
    //                 j++;
    //             }
    //         }
    //     }

    //     int limit = firstItems;
    //     if(secondItems > firstItems)
    //         limit = secondItems;

    //     for(int j = 1; j < limit; j++){
    //         if(j > firstItems){ //check if left side ran out of items
    //             break;
    //         }
    //         if(j > secondItems){ //check if right side ran out of items
    //             order[i] = false;
    //             break;
    //         }

    //         if(pairs[i].first[j] != '[' && pairs[i].second[j] != '['){ //both items are digits
    //             if(pairs[i].first[j] > pairs[i].second[j]){
    //                 order[i] = false;
    //                 break;
    //             }
    //         }else if(pairs[i].first[j] == '[' && pairs[i].second[j] == '['){ //both items are lists
    //             std::cout << i << " list: " << std::endl;
    //             std::vector<char> firstList = getList(pairs[i].first, j);
    //             std::vector<char> secondList = getList(pairs[i].second, j);
    //             std::cout << std::endl;

    //             int limit2 = firstList.size();
    //             if(secondList.size() > limit2)
    //                 limit2 = secondList.size();
                
    //             int a;
    //             for(a = 0; a < limit2; a++){
    //                 if(a > firstList.size()){
    //                     a = 12000;
    //                 }
    //                 if(a > secondList.size()){
    //                     order[i] = false;
    //                     a = 12000;
    //                 }
    //             }
    //             if(a = 12000)
    //                 break;

    //         }
    //     }
    // }

    int final = 0;
    for(int i = 0; i < order.size(); i++){
        if(order[i]){
            final += i + 1;
            std::cout << i << " is correct" << std::endl;
        }else{
            std::cout << i << " is incorrect" << std::endl;
        }
    }
    std::cout << "part1: " << final << std::endl;
}

void part2(){

}

std::vector<char> getList(std::string line, int sIndex){
    std::vector<char> list;
    int i = sIndex + 1;
    while(line[i] != ']'){
        if(line[i] != ','){
            list.push_back(line[i]);
        }
        i++;
    }
    std::cout << "LIST: [";
    for(int i = 0; i < list.size(); i++){
        std::cout << list[i] << ",";
    }
    std::cout << "]" << std::endl;
    return list;
}