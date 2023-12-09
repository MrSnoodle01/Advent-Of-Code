#include <iostream>
#include <string> 
#include <vector>
#include <fstream>

void part1(){
    std::vector<int> times;
    std::vector<int> distances;
    std::string line;
    std::ifstream myfile("input.txt");

    bool isTime = true;
    myfile >> line;
    while(myfile >> line){
        if(isTime && line != "Distance:")
            times.push_back(stoi(line));
        else if(line == "Distance:")
            isTime = false;
        else if(!isTime)
            distances.push_back(stoi(line));
    }   

    int final = 1;
    for(int i = 0; i < times.size(); i++){ // iterate through each toy boat
        int numBeat = 0;
        for(int j = 0; j <= times[i]; j++){ // iterate through each possible number of milliseconds to hold down button
            if(j * (times[i] - j) > distances[i])
                numBeat++;
        }
        final *= numBeat;
    }

    std::cout << "part 1 final: " << final << std::endl;
}

void part2(){
    std::string line;
    std::ifstream myfile("input.txt");

    bool isTime = true;
    myfile >> line;
    std::string time = "", distance  ="";
    long int iTime = 0, iDistance = 0;
    while(myfile >> line){
        if(isTime && line != "Distance:")
            time += line;
        else if(line == "Distance:")
            isTime = false;
        else if(!isTime)
            distance += line;
    }   

    std::cout << time << ", " << distance << std::endl;
    iTime = stol(time);
    iDistance = stol(distance);

    int final = 1;
    int numBeat = 0;
    for(long int j = 0; j <= iTime; j++){ // iterate through each possible number of milliseconds to hold down button
        if(j * (iTime - j) > iDistance)
            numBeat++;
    }
    final *= numBeat;

    std::cout << "part 2 final: " << final << std::endl;
}

int main(){
    part1();
    part2();
}