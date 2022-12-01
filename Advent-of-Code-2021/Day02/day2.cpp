#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main(){
    int horizontal = 0, depth = 0, intIn = 0, aim = 0;
    
    ifstream myFile("input.txt");

    string line;
    string move;
    
    while(getline(myFile, line)){
        istringstream ss(line);
        if(ss >> move >> intIn){
            if(move == "forward"){
                horizontal += intIn;
                depth += aim * intIn;
            }else if(move == "down"){
                aim += intIn;
            }else if(move == "up"){
                aim -= intIn;
            }
        }
    }

    cout << horizontal * depth << endl;

    return 0;
}