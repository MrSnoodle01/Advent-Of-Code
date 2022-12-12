#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <queue>
#include <climits>

std::vector<std::string> map;

class pos{
    public:
        int i;
        int j;
        int dist;
};

int pathFinding(pos);
void part1();
void part2();

int main(){
    std::fstream myfile("input.txt");

    std::string line;
    while(std::getline(myfile, line)){
        map.push_back(line);
    }

    part1();
    part2();

    return 0;
}

void part1(){
    pos start, end;
    for(int i = 0; i < map.size(); i++){
        for(int j = 0; j < map[i].size(); j++){
            if(map[i][j] == 'S'){
                start.i = i;
                start.j = j;
            }
            if(map[i][j] == 'E'){
                end.i = i;
                end.j = j;
            }
        }
    }
    int final = 0;
    final = pathFinding(start);
    std::cout << "part1: " << final << std::endl;
    
}   

void part2(){
    pos start, end;
    for(int i = 0; i < map.size(); i++){
        for(int j = 0; j < map[i].size(); j++){
            if(map[i][j] == 'S'){
                start.i = i;
                start.j = j;
            }
            if(map[i][j] == 'E'){
                end.i = i;
                end.j = j;
            }
        }
    }

    std::vector<pos> starts;
    for(int i = 0; i < map.size(); i++){
        for(int j = 0; j < map[i].size(); j++){
            if(map[i][j] == 'a' || map[i][j] == 'S'){
                pos temp;
                temp.i = i;
                temp.j = j;
                temp.dist = 0;
                starts.push_back(temp);
            }
        }
    }

    int final = INT_MAX;
    for(int i = 0; i < starts.size(); i++){
        int temp = 0;
        temp = pathFinding(starts[i]);
        if(temp < final && temp != -1){
            final = temp;
        }
    }
    std::cout << "part2: " << final << std::endl;
}

int pathFinding(pos start){
    std::vector<std::vector<bool>> visited;
    for(int i = 0; i < map.size(); i++){
        std::vector<bool> temp;
        for(int j = 0; j < map[i].size(); j++){
            temp.push_back(false);
        }
        visited.push_back(temp);
    }

    std::queue<pos> q;
    start.dist = 0;
    q.push(start);
    visited[start.i][start.j] = true;
    map[start.i][start.j] = 'a';
    while(!q.empty()){
        pos p = q.front();
        q.pop();

        if(map[p.i][p.j] == 'E'){
            return p.dist;
        }

        if(p.i - 1 >= 0 && visited[p.i - 1][p.j] == false && map[p.i - 1][p.j] - 1 <= map[p.i][p.j]){
            if(map[p.i - 1][p.j] == 'E' && map[p.i][p.j] + 1 >= 'z'){
                pos temp;
                temp.i = p.i - 1;
                temp.j = p.j;
                temp.dist = p.dist + 1;
                q.push(temp);
                visited[p.i - 1][p.j] = true;
            }else if(map[p.i - 1][p.j] != 'E'){
                pos temp;
                temp.i = p.i - 1;
                temp.j = p.j;
                temp.dist = p.dist + 1;
                q.push(temp);
                visited[p.i - 1][p.j] = true;
            }
        }

        if(p.i + 1 < map.size() && visited[p.i + 1][p.j] == false && map[p.i + 1][p.j] - 1 <= map[p.i][p.j]){
            if(map[p.i + 1][p.j] == 'E' && map[p.i][p.j] + 1 >= 'z'){
                pos temp;
                temp.i = p.i + 1;
                temp.j = p.j;
                temp.dist = p.dist + 1;
                q.push(temp);
                visited[p.i + 1][p.j] = true;
            }else if(map[p.i + 1][p.j] != 'E'){
                pos temp;
                temp.i = p.i + 1;
                temp.j = p.j;
                temp.dist = p.dist + 1;
                q.push(temp);
                visited[p.i + 1][p.j] = true;
            }
        }

        if(p.j - 1 >= 0 && visited[p.i][p.j - 1] == false && map[p.i][p.j - 1] - 1 <= map[p.i][p.j]){
            if(map[p.i][p.j - 1] == 'E' && map[p.i][p.j] + 1 >= 'z'){
                pos temp;
                temp.i = p.i;
                temp.j = p.j - 1;
                temp.dist = p.dist + 1;
                q.push(temp);
                visited[p.i][p.j - 1] = true;
            }else if(map[p.i][p.j - 1] != 'E'){
                pos temp;
                temp.i = p.i;
                temp.j = p.j - 1;
                temp.dist = p.dist + 1;
                q.push(temp);
                visited[p.i][p.j - 1] = true;
            }
        }

        if(p.j + 1 < map[0].size() && visited[p.i][p.j + 1] == false && map[p.i][p.j + 1] - 1 <= map[p.i][p.j]){
            if(map[p.i][p.j + 1] == 'E' && map[p.i][p.j] + 1 >= 'z'){
                pos temp;
                temp.i = p.i;
                temp.j = p.j + 1;
                temp.dist = p.dist + 1;
                q.push(temp);
                visited[p.i][p.j + 1] = true;
            }else if(map[p.i][p.j + 1] != 'E'){
                pos temp;
                temp.i = p.i;
                temp.j = p.j + 1;
                temp.dist = p.dist + 1;
                q.push(temp);
                visited[p.i][p.j + 1] = true;
            }
        }
    }

    return -1;
}