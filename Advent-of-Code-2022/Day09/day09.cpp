#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

const int SIZE = 500;

std::vector<std::vector<char>> grid;
std::vector<std::vector<char>> positions;
std::vector<char> commands;
std::vector<int> nums;

class ends{
    public: 
        int i;//row
        int j;//col

    bool operator==(ends const &obj){
        if(i == obj.i && j == obj.j){
            return true;
        }
        return false;
    }
};

ends head, tail;
std::vector<ends> tens;

bool checkHead();
bool checkClose(ends, ends);
void move(ends&, ends&);

int main(){
    std::fstream myfile("input.txt");

    std::string line, tempString;
    char tempChar;
    while(std::getline(myfile, line)){
        std::stringstream ss(line);

        ss >> tempChar;
        commands.push_back(tempChar);

        ss >> tempString;
        nums.push_back(stoi(tempString));
    }

    // part1();
    part2();

    return 0;
}

void part1(){
    //initialize grid
    std::vector<char> tempVect;
    for(int j = 0; j < SIZE; j++){
        tempVect.push_back('.');
    }
    for(int i = 0; i < SIZE; i++){
        grid.push_back(tempVect);
        positions.push_back(tempVect);
    }

    head.j = SIZE/2;
    head.i = SIZE/2;
    tail.j = SIZE/2;
    tail.i = SIZE/2;

    grid[head.i][head.j] = 'H';

    for(int a = 0; a < commands.size(); a++){

        //change position of head
        if(commands[a] == 'D'){
            for(int i = 0; i < nums[a]; i++){
                grid[tail.i][tail.j] = '.';
                grid[head.i][head.j] = '.';
                head.i++;

                if(!checkHead()){ //if head is not in proximity of tail
                    if(head.j < tail.j){ //if head is down and to left of tail
                        tail.j--;
                        tail.i++;
                    }else if(head.j > tail.j){ //if head is down and to right of tail
                        tail.j++;
                        tail.i++;
                    }else{ //if head is directly below tail
                        tail.i++;
                    }
                }
                
                grid[tail.i][tail.j] = 'T';
                grid[head.i][head.j] = 'H';
                positions[tail.i][tail.j] = '#';
            }
        }else if(commands[a] == 'U'){
            for(int i = 0; i < nums[a]; i++){
                grid[tail.i][tail.j] = '.';
                grid[head.i][head.j] = '.';
                head.i--;

                if(!checkHead()){ //if head is not in proximity of tail
                    if(head.j < tail.j){ //if head is up and to left of tail
                        tail.j--;
                        tail.i--;
                    }else if(head.j > tail.j){ //if head is up and to right of tail
                        tail.j++;
                        tail.i--;
                    }else{ //if head is directly above tail
                        tail.i--;
                    }
                }
                grid[tail.i][tail.j] = 'T';
                grid[head.i][head.j] = 'H';
                positions[tail.i][tail.j] = '#';
            }
        }else if(commands[a] == 'L'){
            for(int i = 0; i < nums[a]; i++){
                grid[tail.i][tail.j] = '.';
                grid[head.i][head.j] = '.';
                head.j--;

                if(!checkHead()){ //if head is not in proximity of tail
                    if(head.i < tail.i){ //if head is left and up of tail
                        tail.j--;
                        tail.i--;
                    }else if(head.i > tail.i){ //if head is left and down of tail
                        tail.j--;
                        tail.i++;
                    }else{ //if head is directly to left of tail
                        tail.j--;
                    }
                }
                grid[tail.i][tail.j] = 'T';
                grid[head.i][head.j] = 'H';
                positions[tail.i][tail.j] = '#';
            }
        }else if(commands[a] == 'R'){
            for(int i = 0; i < nums[a]; i++){
                grid[tail.i][tail.j] = '.';
                grid[head.i][head.j] = '.';
                head.j++;

                if(!checkHead()){ //if head is not in proximity of tail
                    if(head.i < tail.i){ //if head is right and below tail
                        tail.j++;
                        tail.i--;
                    }else if(head.i > tail.i){ //if head is right and above tail
                        tail.j++;
                        tail.i++;
                    }else{ //if head is directly to right of tail
                        tail.j++;
                    }
                }
                grid[tail.i][tail.j] = 'T';
                grid[head.i][head.j] = 'H';
                positions[tail.i][tail.j] = '#';
            }
        }
    }

    int final = 0;
    for(int i = 0; i < positions.size(); i++){
        for(int j = 0; j < positions[i].size(); j++){
            if(positions[i][j] == '#')
                final++;
        }
    }
    std::cout << "part2: " << final << std::endl;
}

void part2(){
    //initialize grid
    std::vector<char> tempVect;
    for(int j = 0; j < SIZE; j++){
        tempVect.push_back('.');
    }
    for(int i = 0; i < SIZE; i++){
        grid.push_back(tempVect);
        positions.push_back(tempVect);
    }

    ends tempEnd;
    tempEnd.i = SIZE/2;
    tempEnd.j = SIZE/2;
    for(int i = 0; i < 10; i++){
        tens.push_back(tempEnd);
    }
    
    grid[tens[0].i][tens[0].j] = '0';
    for(int a = 0; a < commands.size(); a++){

        //change position of head
        if(commands[a] == 'D'){
            for(int i = 0; i < nums[a]; i++){
                for(int j = 0; j < tens.size(); j++){
                    grid[tens[j].i][tens[j].j] = '.';
                }
                tens[0].i++;

                for(int j = 1; j < tens.size(); j++){
                    move(tens[j], tens[j - 1]);
                }

                for(int j = 0; j < tens.size(); j++){
                    grid[tens[j].i][tens[j].j] = '0' + j;
                }
                positions[tens[9].i][tens[9].j] = '#';
            }
        }else if(commands[a] == 'U'){
            for(int i = 0; i < nums[a]; i++){
                for(int j = 0; j < tens.size(); j++){
                    grid[tens[j].i][tens[j].j] = '.';
                }
                tens[0].i--;

                for(int j = 1; j < tens.size(); j++){
                    move(tens[j], tens[j - 1]);
                }

                for(int j = 0; j < tens.size(); j++){
                    grid[tens[j].i][tens[j].j] = '0' + j;
                }
                positions[tens[9].i][tens[9].j] = '#';
            }
        }else if(commands[a] == 'L'){
            for(int i = 0; i < nums[a]; i++){
                for(int j = 0; j < tens.size(); j++){
                    grid[tens[j].i][tens[j].j] = '.';
                }
                tens[0].j--;

                for(int j = 1; j < tens.size(); j++){
                    move(tens[j], tens[j - 1]);
                }

                for(int j = 0; j < tens.size(); j++){
                    grid[tens[j].i][tens[j].j] = '0' + j;
                }
                positions[tens[9].i][tens[9].j] = '#';
            }
        }else if(commands[a] == 'R'){
            for(int i = 0; i < nums[a]; i++){
                for(int j = 0; j < tens.size(); j++){
                    grid[tens[j].i][tens[j].j] = '.';
                }
                tens[0].j++;

                for(int j = 1; j < tens.size(); j++){
                    move(tens[j], tens[j - 1]);
                }

                for(int j = 0; j < tens.size(); j++){
                    grid[tens[j].i][tens[j].j] = '0' + j;
                }
                positions[tens[9].i][tens[9].j] = '#';
            }
        }
    }

    int final = 0;
    for(int i = 0; i < positions.size(); i++){
        for(int j = 0; j < positions[i].size(); j++){
            if(positions[i][j] == '#')
                final++;
        }
    }
    std::cout << "part2: " << final << std::endl;

}

void move(ends &tail2, ends &head2){
    if(!checkClose(tail2, head2)){
        if(head2.i == tail2.i){ //if head in same row
            if(head2.j > tail2.j){
                tail2.j++;
            }else{
                tail2.j--;
            }
        }else if(head2.j == tail2.j){ // if head in same column
            if(head2.i > tail2.i){
                tail2.i++;
            }else{
                tail2.i--;
            }
        }else{ //check if headhas moved in two dimensions
            if(head2.j > tail2.j){ //if head is to right column
                if(head2.i > tail2.i){
                    tail2.j++;
                    tail2.i++;
                }else{
                    tail2.j++;
                    tail2.i--;
                }
            }else if(head2.j < tail2.j){ //if head is to left column
                if(head2.i > tail2.i){
                    tail2.j--;
                    tail2.i++;
                }else{
                    tail2.j--;
                    tail2.i--;
                }
            }
        }
    }
}

bool checkClose(ends tail2, ends head2){
    int rowCheck[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    int colCheck[8] = {1, 1, 1, 0, 0, -1, -1, -1};

    for(int i = 0; i < 8; i++){
        if(tail2.i + rowCheck[i] == head2.i && tail2.j + colCheck[i] == head2.j)
            return true;
    }

    if(tail2 == head2)
        return true;

    return false;
}

bool checkHead(){
    int rowCheck[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    int colCheck[8] = {1, 1, 1, 0, 0, -1, -1, -1};

    for(int i = 0; i < 8; i++){
        if(tail.i + rowCheck[i] == head.i && tail.j + colCheck[i] == head.j)
            return true;
    }

    if(tail == head)
        return true;
    
    return false;
}