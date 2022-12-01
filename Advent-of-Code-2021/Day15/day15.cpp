#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

void printPath(vector<int>& path){
    int size = path.size();
    for(int i = 0; i < size; i++){
        cout << path[i] << " ";
    }
    cout << endl;
}

int isNotVisited(int x, vector<int>& path){
    int size = path.size();
    for(int i = 0; i < size; i++){
        if(path[i] == x){
            return 0;
        }
    }
    return 1;
}

void findPaths(vector<vector<int>> &g, int src, int dst, int v){

    queue<vector<int>> q;

    vector<int> path;
    path.push_back(src);
    q.push(path);
    while(!q.empty()){
        path = q.front();
        q.pop();
        int last = path[path.size() - 1];


        if(last == dst){
            printPath(path);
        }


        for(int i = 0; i < g[last].size(); i++){
            if(isNotVisited(g[last][i], path)){
                vector<int> newpath(path);
                newpath.push_back(g[last][i]);
                q.push(newpath);
            }
        }
    }
}

int main(){
    fstream inFile("testInput.txt");

    vector<vector<int>> cave;
    
    string line;
    while(getline(inFile, line)){
        // fill up cave 2d vector
        vector<int> temp;
        for(int i = 0; i < line.size(); i++){
            temp.push_back(line[i] - '0');
        }
        cave.push_back(temp);
    }

    

    // for(int i = 0; i < cave[0].size() - 1; i++){
    //     for(int j = 0; j < cave.size(); j++){
    //         cout << cave[i][j];
    //     }
    //     cout << endl;
    // }

    return 0;
}