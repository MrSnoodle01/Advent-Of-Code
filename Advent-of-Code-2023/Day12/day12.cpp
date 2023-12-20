#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

// whole thing is wrong because it cant track if there is more than 1 space between springs
// function to recursively return the number of arrangements of springs
// int arrangements(std::string record, std::vector<int> nums, int start){
//     int final = 0, index = 0;

//     bool canFit = true;
//     // iterate through each char in record, and determine if the num can go there
//     for(int i = start; i < record.size(); i++){
//         // if ther is a possible spring then determine if the correct index from nums can fit there
//         if(record[i] == '?' || record[i] == '#'){
//             canFit = true;
//             int lastIndex = false;
//             for(int j = 0; j < nums[index]; j++){
//                 if(i + j < record.size()){ // dont go out of bounds
//                     if(record[i + j] == '.'){
//                         canFit = false;
//                     }
//                 }else{
//                     canFit = false;
//                 }   
//                 lastIndex = j;
//             }

//             if(i + lastIndex + 1 < record.size()){ // dont go out of bounds
//                 if(record[i + lastIndex + 1] == '#'){ // if directly after the spring there is another it cannot fit
//                     canFit = false;
//                 }
//             }

//             i += nums[index]; // increment i by the num
//             if(i < record.size())
//                 index++;
//             if(!canFit){
//                 i = record.size(); // test to see if break works here, it should but man I aint tryna figure it out rn
//             }
//         }
//     }

//     if(index < nums.size() - 1) // make sure that every spring fit
//         canFit = false;

//     if(canFit){ // if all springs fit then increment the number of possible arangements
//         final++;
//         std::cout << "start: " << start << std::endl;
//     }
        
//     if(start + 1 < record.size())
//         final += arrangements(record, nums, start + 1);
//     return final;
// }



void part1(){
    std::ifstream myfile("testinput.txt");
    std::string line;
    std::vector<std::string> records;
    std::vector<std::vector<int>> nums;
    while(myfile >> line){
        records.push_back(line);
        myfile >> line;
        int temp;
        char ch;
        std::vector<int> tempVector;
        std::stringstream ss(line);
        while(ss >> temp){
            tempVector.push_back(temp);
            ss >> ch;
        }
        nums.push_back(tempVector);
    }

    int final = 0;
    // go through each record and find the number of different arrangements
    for(int i = 0; i < records.size(); i++){
        
    }

    std::cout << "part 1 final: " << final << std::endl;
}

void part2(){

}

int main(){
    part1();
    part2();
}