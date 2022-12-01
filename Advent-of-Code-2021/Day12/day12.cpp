#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class tunnels{
    public:
        string first;
        string second;
};

void recursivePathfinding(string next, string current, vector<string> &totalPaths, string currentPath, vector<tunnels> tunnelVector, vector<string> &visited){
    cout << next << endl;
    if(current == "start"){
        return;
    }
    if(next == "end"){
        cout << "end" << endl;
        bool isGood = true;
        for(int i = 0; i < totalPaths.size(); i++){
            if(totalPaths[i] == currentPath){
                isGood = false;
            }
        }
        if(isGood == true){
            cout << currentPath << endl;
            totalPaths.push_back(currentPath);
        }
        currentPath = "";
        visited.clear();
        return;
    }

    cout << current << endl;
    if(current[0] == tolower(current[0] && current != "start")){
        cout << current[0] << " " << tolower(current[0]) << endl;
        for(int i = 0; i < visited.size(); i++){
            if(current == visited[i]){
                return;
            }
        }
    }

    visited.push_back(current);

    for(int i = 0; i < tunnelVector.size(); i++){
        if(tunnelVector[i].second == current){
            cout << "recursion moment: " << endl;
            recursivePathfinding(tunnelVector[i].second, tunnelVector[i].first, totalPaths, currentPath, tunnelVector, visited);
        }
    }

    return;
}

int main(){

    fstream myFile("testInput.txt");

    vector<tunnels> tunnelsVector;

    string line, temp;
    tunnels tempTunnel;
    while(getline(myFile, line)){
        temp = "";
        for(int i = 0; i < line.size() - 1; i++){
            if(line[i] == '-'){
                tempTunnel.first = temp;
                temp = "";
                i++;
            }
            temp += line[i];
        }
        tempTunnel.second = temp;
        tunnelsVector.push_back(tempTunnel);
    }

    // for(int i = 0; i < tunnelsVector.size(); i++){
    //     cout << "First: " << tunnelsVector[i].first << ", Second: " << tunnelsVector[i].second << endl;
    // }

    // for(int i = 0; i < 100; i++){
        // for(int j = 0; j < tunnelsVector.size(); j++){
        //     if(tunnelsVector[j].first == "start"){
        //         string firstPos = tunnelsVector[j].second;
        //     }        
        // }
    // }

    vector<string> totalPath;
    vector<string> visit;

    recursivePathfinding(tunnelsVector[0].second, tunnelsVector[0].first, totalPath, "", tunnelsVector, visit);
    for(int i = 0; i < totalPath.size(); i++){
        cout << totalPath[i] << endl;
    }

    return 0;
}