#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

int main(){

    std::ifstream myfile("input.txt");

    std::string line;

    std::vector<char> opponent;
    std::vector<char> me;

    while(std::getline(myfile, line)){
        opponent.push_back(line[0]);
        me.push_back(line[2]);
    }

    int score = 0;
    for(int i = 0; i < opponent.size(); i++){
        // FOR PART 1
        // if(me[i] == 'X'){
        //     score += 1;
        // }else if(me[i] == 'Y'){
        //     score += 2;
        // }else{
        //     score += 3;
        // }

        // FOR PART 1
        // switch(opponent[i]){
        //     case 'A':
        //         if(me[i] == 'X'){
        //             score += 3;
        //             break;
        //         }else if(me[i] == 'Y'){
        //             score += 6;
        //         }
        //         break;
        //     case 'B':
        //         if(me[i] == 'Y'){
        //             score += 3;
        //             break;
        //         }else if(me[i] == 'Z'){
        //             score += 6;
        //         }
        //         break;
        //     case 'C':
        //         if(me[i] == 'Z'){
        //             score += 3;
        //             break;
        //         }else if(me[i] == 'X'){
        //             score += 6;
        //         }
        //         break;
        // }

        // FOR PART 2
        // switch(opponent[i]){
        //     case 'A':
        //         if(me[i] == 'X'){
        //             score += 3;
        //             break;
        //         }else if(me[i] == 'Y'){
        //             score += 4;
        //             break;
        //         }
        //         score += 8;
        //         break;
        //     case 'B':
        //         if(me[i] == 'Y'){
        //             score += 5;
        //             break;
        //         }else if(me[i] == 'Z'){
        //             score += 9;
        //             break;
        //         }
        //         score += 1;
        //         break;
        //     case 'C':
        //         if(me[i] == 'Z'){
        //             score += 7;
        //             break;
        //         }else if(me[i] == 'X'){
        //             score += 2;
        //             break;
        //         }
        //         score += 6;
        //         break;
        // }
    }

    std::cout << score << std::endl;

    return 0;
}