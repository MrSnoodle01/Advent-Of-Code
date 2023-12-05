#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <climits>

class locations{
    public: 
        long int destStart;
        long int sourceStart;
        long int rangeLen;
};

class overlap{
    public:
        long int lowerBound;
        long int upperBound;
};

void part1(){
    std::vector<std::string> input;
    std::string line;
    std::ifstream myfile("input.txt");

    std::vector<long int> seedNums;
    std::vector<locations> myLocations;
    bool seedToSoil = false;
    myfile >> line;
    while(myfile >> line){
        if(line == "seed-to-soil"){
            seedToSoil = true;
            // for(int i = 0; i < seedNums.size(); i++){
            //     std::cout << "seed: " << seedNums[i] << std::endl;
            // }
            myfile >> line;
            myfile >> line;
        }else if(!isdigit(line[0]) && line[0] != ' '){
            // for each seed that we have
            for(int i = 0; i < seedNums.size(); i++){
                // check if it is in any maps
                for(int j = 0; j < myLocations.size(); j++){
                    if(seedNums[i] >= myLocations[j].sourceStart && seedNums[i] < myLocations[j].sourceStart + myLocations[j].rangeLen){
                        seedNums[i] = myLocations[j].destStart + (seedNums[i] - myLocations[j].sourceStart);
                        j = myLocations.size();
                    }// else it dont change 5 head
                }
            }
            // for(int i = 0; i < seedNums.size(); i++){
            //     std::cout << line << ": " << seedNums[i] << std::endl;
            // }
            myfile >> line;
            myfile >> line;
            myLocations.clear();
        }
        
        if(!seedToSoil){
            seedNums.push_back(std::stol(line));
        }else{
            locations tempLoc;
            tempLoc.destStart = std::stol(line);
            myfile >> line;
            tempLoc.sourceStart = std::stol(line);
            myfile >> line;
            tempLoc.rangeLen = std::stol(line);
            myLocations.push_back(tempLoc);
        }
        
    }
    for(int i = 0; i < seedNums.size(); i++){
        // check if it is in any maps
        for(int j = 0; j < myLocations.size(); j++){
            if(seedNums[i] >= myLocations[j].sourceStart && seedNums[i] < myLocations[j].sourceStart + myLocations[j].rangeLen){
                seedNums[i] = myLocations[j].destStart + (seedNums[i] - myLocations[j].sourceStart);
                j = myLocations.size();
            }// else it dont change 5 head
        }
    }
  
    long int final = LONG_MAX;
    for(int i = 0; i < seedNums.size(); i++){
        if(seedNums[i] < final){
            final = seedNums[i];
        }
        // std::cout << "final: " << seedNums[i] << std::endl;
    }
    std::cout << "part 1 final : " << final << std::endl;
}

void part2(){
    std::vector<std::string> input;
    std::string line;
    std::ifstream myfile("testinput.txt");

    std::vector<long int> ranges;
    std::vector<long int> seedNums;
    std::vector<locations> myLocations;
    std::vector<overlap> myOverlaps;
    std::vector<overlap> newOverlaps;
    bool seedToSoil = false;
    myfile >> line;
    while(myfile >> line){
        if(line == "seed-to-soil"){
            seedToSoil = true;

            myfile >> line;
            myfile >> line;
        }else if(!isdigit(line[0]) && line[0] != ' '){
            // for each seed that we have
            for(int i = 0; i < myOverlaps.size(); i++){
                std::cout << line << ", lower: " << myOverlaps[i].lowerBound << ", upper: " << myOverlaps[i].upperBound << std::endl;
            }
            for(int i = 0; i < myLocations.size(); i++){
                // check if it is in any maps
                for(int j = 0; j < myOverlaps.size(); j++){
                    // if lowerbound >= startsource && upperbound <= startsource + range - 1; translate accordingly
                    // if lowerbound >= startsource && upperbound > startsource + range - 1; do nothing
                    // if lowerbound < startsource && upperbound <= startsource + range - 1; do nothing
                    // if lowerbound < startsource && upperbound > startSource + range - 1; split the range(x3) and add them to myOverlaps
                    long int tempLowerBound = myOverlaps[j].lowerBound;
                    long int tempUpperBound = myOverlaps[j].upperBound;
                    long int tempRange = myLocations[i].rangeLen;
                    long int tempStartSource = myLocations[i].sourceStart;
                    if(tempLowerBound >= tempStartSource && tempUpperBound < tempStartSource + tempRange){
                        myOverlaps[j].lowerBound = myLocations[i].destStart + (tempLowerBound - tempStartSource);
                        myOverlaps[j].upperBound = myLocations[i].destStart + (tempUpperBound - tempStartSource);
                    }else if(tempLowerBound >= tempStartSource && tempUpperBound > tempStartSource + tempRange - 1){
                        
                    }else if(tempLowerBound < tempStartSource && tempUpperBound <= tempStartSource + tempRange - 1){
                        
                    }else if(tempLowerBound < tempStartSource && tempUpperBound > tempStartSource + tempRange - 1){
                        overlap temp1, temp2, temp3;
                        temp1.lowerBound = tempLowerBound;
                        temp1.upperBound = tempStartSource - 1;
                        temp2.lowerBound = tempStartSource;
                        temp2.upperBound = tempStartSource + tempRange - 1;
                        temp3.lowerBound = tempStartSource + tempRange;
                        temp3.upperBound = tempUpperBound;
                        myOverlaps.push_back(temp1);
                        myOverlaps.push_back(temp2);
                        myOverlaps.push_back(temp3);
                        myOverlaps.erase(myOverlaps.begin() + j);
                        j--;
                    }
                }
            }

            myfile >> line;
            myfile >> line;
            myLocations.clear();
        }
        
        if(!seedToSoil){
            std::string first;
            first = line;
            myfile >> line;
            overlap temp;
            temp.lowerBound = stol(first);
            temp.upperBound = temp.lowerBound + stol(line) - 1;
            myOverlaps.push_back(temp);
            
        }else{
            locations tempLoc;
            tempLoc.destStart = stol(line);
            myfile >> line;
            tempLoc.sourceStart = stol(line);
            myfile >> line;
            tempLoc.rangeLen = stol(line);
            myLocations.push_back(tempLoc);
        }
        
    }
    for(int i = 0; i < myLocations.size(); i++){
        // check if it is in any maps
        for(int j = 0; j < myOverlaps.size(); j++){
            // if lowerbound >= startsource && upperbound <= startsource + range - 1; translate accordingly
            // if lowerbound >= startsource && upperbound > startsource + range - 1; do nothing
            // if lowerbound < startsource && upperbound <= startsource + range - 1; do nothing
            // if lowerbound < startsource && upperbound > startSource + range - 1; split the range(x3) and add them to myOverlaps
            long int tempLowerBound = myOverlaps[j].lowerBound;
            long int tempUpperBound = myOverlaps[j].upperBound;
            long int tempRange = myLocations[i].rangeLen;
            long int tempStartSource = myLocations[i].sourceStart;
            if(tempLowerBound >= tempStartSource && tempUpperBound <= tempStartSource + tempRange){
                myOverlaps[j].lowerBound = myLocations[i].destStart + (tempLowerBound - tempStartSource);
                myOverlaps[j].upperBound = myLocations[i].destStart + (tempUpperBound - tempStartSource);
            }else if(tempLowerBound >= tempStartSource && tempUpperBound > tempStartSource + tempRange - 1){
                
            }else if(tempLowerBound < tempStartSource && tempUpperBound <= tempStartSource + tempRange - 1){
                
            }else if(tempLowerBound < tempStartSource && tempUpperBound > tempStartSource + tempRange - 1){
                overlap temp1, temp2, temp3;
                temp1.lowerBound = tempLowerBound;
                temp1.upperBound = tempStartSource - 1;
                temp2.lowerBound = tempStartSource;
                temp2.upperBound = tempStartSource + tempRange - 1;
                temp3.lowerBound = tempStartSource + tempRange;
                temp3.upperBound = tempUpperBound;
                myOverlaps.push_back(temp1);
                myOverlaps.push_back(temp2);
                myOverlaps.push_back(temp3);
                myOverlaps.erase(myOverlaps.begin() + j);
                j--;
            }
        }
    }
    long int final = LONG_MAX;
    for(int i = 0; i < myOverlaps.size(); i++){
        std::cout << "lower: " << myOverlaps[i].lowerBound << ", upper: " << myOverlaps[i].upperBound << std::endl;
        if(myOverlaps[i].lowerBound < final){
            final = myOverlaps[i].lowerBound;
        }
        // std::cout << "final: " << seedNums[i] << std::endl;
    }
    std::cout << "part 2 final : " << final << std::endl;
}

int main(){
    part1();
    part2();
}