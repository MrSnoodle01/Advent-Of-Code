#include <iostream>
#include <fstream>
#include <vector>
#include <string>

std::vector<std::string> graph;

int overallDistance = 0;

class tile{
    public:
        int i;
        int j;
        int distance;
        char type;
};

tile startAdjacent(tile currTile){
    int row[4] = {-1, 1, 0, 0};
    int col[4] = {0, 0, -1, 1};
    for(int i = 0; i < 4; i++){
        char pipe = graph[currTile.i + row[i]][currTile.j + col[i]];
        if(pipe != '.'){
            if(row[i] == -1 && (pipe == 'J' || pipe == 'L' || pipe == '-')){

            }else if(row[i] == 1 && (pipe == 'F' || pipe == '7' || pipe == '-')){

            }else if(col[i] == -1 && (pipe == 'J' || pipe == '7' || pipe == '|')){

            }else if(col[i] == 1 && (pipe == 'F' || pipe == 'L' || pipe == '|')){

            }else{
                tile temp;
                temp.i = currTile.i + row[i];
                temp.j = currTile.j + col[i];
                temp.distance = overallDistance;
                temp.type = pipe;
                graph[currTile.i + row[i]][currTile.j + col[i]] = '.';
                return temp;
            }
        }
    } 
    tile temp2;
    temp2.distance = -100;
    return temp2;
}

tile anyAdjacent(tile currTile){
    int row[4] = {0, 0, 1, -1};
    int col[4] = {1, -1, 0, 0};
    switch(currTile.type){
        case 'S':
            for(int i = 0; i < 4; i++){
                if(graph[currTile.i + row[i]][currTile.j + col[i]] != '.'){
                    tile temp;
                    temp.i = currTile.i + row[i];
                    temp.j = currTile.j + col[i];
                    temp.distance = overallDistance;
                    temp.type = graph[currTile.i + row[i]][currTile.j + col[i]];
                    graph[currTile.i + row[i]][currTile.j + col[i]] = '.';
                    graph[currTile.i][currTile.j] = '.';
                    return temp;
                }
            }   
            break;
        case '-':
            if(graph[currTile.i][currTile.j + 1] != '.'){
                tile temp;
                temp.i = currTile.i;
                temp.j = currTile.j + 1;
                temp.distance = overallDistance;
                temp.type = graph[currTile.i][currTile.j + 1];
                graph[currTile.i][currTile.j + 1] = '.';
                return temp;
            }else if(graph[currTile.i][currTile.j + -1] != '.'){
                tile temp;
                temp.i = currTile.i;
                temp.j = currTile.j + -1;
                temp.distance = overallDistance;
                temp.type = graph[currTile.i][currTile.j + -1];
                graph[currTile.i][currTile.j + -1] = '.';
                return temp;
            }
            break;
        case '|':
            if(graph[currTile.i + 1][currTile.j] != '.'){
                tile temp;
                temp.i = currTile.i + 1;
                temp.j = currTile.j;
                temp.distance = overallDistance;
                temp.type = graph[currTile.i + 1][currTile.j];
                graph[currTile.i + 1][currTile.j] = '.';
                return temp;
            }else if(graph[currTile.i + -1][currTile.j] != '.'){
                tile temp;
                temp.i = currTile.i + -1;
                temp.j = currTile.j;
                temp.distance = overallDistance;
                temp.type = graph[currTile.i + -1][currTile.j];
                graph[currTile.i + -1][currTile.j] = '.';
                return temp;
            }
            break;
        case '7':
            if(graph[currTile.i + 1][currTile.j] != '.'){
                tile temp;
                temp.i = currTile.i + 1;
                temp.j = currTile.j;
                temp.distance = overallDistance;
                temp.type = graph[currTile.i + 1][currTile.j];
                graph[currTile.i + 1][currTile.j] = '.';
                return temp;
            }else if(graph[currTile.i][currTile.j + -1] != '.'){
                tile temp;
                temp.i = currTile.i;
                temp.j = currTile.j + -1;
                temp.distance = overallDistance;
                temp.type = graph[currTile.i][currTile.j + -1];
                graph[currTile.i][currTile.j + -1] = '.';
                return temp;
            }
            break;
        case 'J':   
             if(graph[currTile.i + -1][currTile.j] != '.'){
                tile temp;
                temp.i = currTile.i + -1;
                temp.j = currTile.j;
                temp.distance = overallDistance;
                temp.type = graph[currTile.i + -1][currTile.j];
                graph[currTile.i + -1][currTile.j] = '.';
                return temp;
            }else if(graph[currTile.i][currTile.j + -1] != '.'){
                tile temp;
                temp.i = currTile.i;
                temp.j = currTile.j + -1;
                temp.distance = overallDistance;
                temp.type = graph[currTile.i][currTile.j + -1];
                graph[currTile.i][currTile.j + -1] = '.';
                return temp;
            }
            break;
        case 'L':  
            if(graph[currTile.i + -1][currTile.j] != '.'){
                tile temp;
                temp.i = currTile.i + -1;
                temp.j = currTile.j;
                temp.distance = overallDistance;
                temp.type = graph[currTile.i + -1][currTile.j];
                graph[currTile.i + -1][currTile.j] = '.';
                return temp;
            }else if(graph[currTile.i][currTile.j + 1] != '.'){
                tile temp;
                temp.i = currTile.i;
                temp.j = currTile.j + 1;
                temp.distance = overallDistance;
                temp.type = graph[currTile.i][currTile.j + 1];
                graph[currTile.i][currTile.j + 1] = '.';
                return temp;
            }
            break;
        case 'F':
            if(graph[currTile.i + 1][currTile.j] != '.'){
                tile temp;
                temp.i = currTile.i + 1;
                temp.j = currTile.j;
                temp.distance = overallDistance;
                temp.type = graph[currTile.i + 1][currTile.j];
                graph[currTile.i + 1][currTile.j] = '.';
                return temp;
            }else if(graph[currTile.i][currTile.j + 1] != '.'){
                tile temp;
                temp.i = currTile.i;
                temp.j = currTile.j + 1;
                temp.distance = overallDistance;
                temp.type = graph[currTile.i][currTile.j + 1];
                graph[currTile.i][currTile.j + 1] = '.';
                return temp;
            }
            break;
    }
    tile temp2;
    temp2.distance = -100;
    return temp2;
}

void part1(){
    std::ifstream myfile("input.txt");
    std::string line;
    while(std::getline(myfile, line)){
        graph.push_back(line);
    }

    tile start;
    start.distance = 0;
    start.type = 'S';
    for(int i = 0; i < graph.size(); i++){
        for(int j = 0; j < graph[i].size(); j++){
            if(graph[i][j] == 'S'){
                start.i = i;
                start.j = j;
            }
        }
    }

    // overall distance++ in while loop that goes through each tile
    tile temp1 = startAdjacent(start);
    tile temp2 = anyAdjacent(start);
    while(temp1.distance != -100 || temp2.distance != -100){
        overallDistance++;
        temp1 = anyAdjacent(temp1);
        temp2 = anyAdjacent(temp2);
    }

    std::cout << "part 1 final: " << overallDistance << std::endl;
}

void part2(){
    std::ifstream myfile("testinput.txt");
    std::string line;
    graph.clear();
    while(std::getline(myfile, line)){
        graph.push_back(line);
    }
    std::vector<std::string> ogGraph = graph;

    tile start;
    start.distance = 0;
    start.type = 'S';
    for(int i = 0; i < graph.size(); i++){
        for(int j = 0; j < graph[i].size(); j++){
            if(graph[i][j] == 'S'){
                start.i = i;
                start.j = j;
            }
        }
    }
    
    int fLeft = 1000, fRight = -1, fUp = 1000, fDown = -1;
    tile temp1 = startAdjacent(start);
    tile temp2 = anyAdjacent(start);
    while(temp1.distance != -100 || temp2.distance != -100){
        if(temp1.i < fLeft){
            fLeft = temp1.i;
        }else if(temp2.i < fLeft){
            fLeft = temp2.i;
        }
        if(temp1.i > fRight){
            fRight = temp1.i;
        }else if(temp2.i > fRight){
            fRight = temp2.i;
        }
        if(temp1.j < fUp){
            fUp = temp1.j;
        }else if(temp2.j < fUp){
            fUp = temp2.j;
        }
        if(temp1.j > fDown){
            fDown = temp1.j;
        }else if(temp2.j > fDown){
            fDown = temp2.j;
        }
        if(temp1.distance != -100)
            temp1 = anyAdjacent(temp1);
        if(temp2.distance != -100)
            temp2 = anyAdjacent(temp2);
    }

    // for(int i = fLeft; i <= fRight; i++){
    //     for(int j = fUp; j <= fDown; j++){
    //         std::cout << ogGraph[i][j];
    //     }
    //     std::cout << std::endl;
    // }
    for(int i = 0; i < graph.size(); i++){
        for(int j = 0; j < graph[i].size(); j++){
            std::cout << ogGraph[i][j];
        }
        std::cout << std::endl;
    }

    std::cout << "down: " << fDown << ", up: " << fUp << ", left: " << fLeft << ", right: " << fRight << std::endl;
    std::cout << "rows: " << graph.size() << ", cols: " << graph[0].size() << std::endl;
    std::cout << "part 2 final: " << overallDistance << std::endl;
}

int main(){
    part1();
    part2();
}