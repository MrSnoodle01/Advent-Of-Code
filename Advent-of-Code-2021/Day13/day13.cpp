#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

class foldClass{
    public:
        int line;
        char XorY;
};

void foldX(int foldLine, char **myArray, int maxY, int maxX){
    char **tempArray = new char*[maxY];
    for(int i = 0; i < maxY; i++){
        tempArray[i] = new char[maxX / 2];
    }

    for(int i = 0; i < maxY; i++){
        for(int j = 0; j < maxX / 2; j++){
            tempArray[i][j] = '.';
        }
    }

    for(int i = 0; i < maxY; i++){
        for(int j = foldLine + 1; j < maxX; j++){
            if(j > maxX / 2){
                tempArray[i][j - maxX / 2 - 1] = myArray[i][j];
            }
        }
    }
    cout << "maxY: " << maxY << ", maxX: " << maxX << endl;
    cout << "TEMP ARRAY BEFORE" << endl;
    if(maxY < 100 && maxX < 100){
        for(int i = 0; i < maxY; i++){
            for(int j = 0; j < maxX / 2; j++){
                cout << tempArray[i][j];
            }
            cout << endl;
        }
    }
    cout << "TEMP ARRAY BEFORE" << endl;

    // SOMETHING WRONG WITH THIS PIECE OF SHIT
    char tempChar;
    int bottom = maxX / 2 - 1;
    for(int i = 0; i < maxY / 2; i++){
        bottom = maxX / 2 - 1;
        for(int j = 0; j < maxY / 2 - 1; j++){
            tempChar = tempArray[i][j];
            tempArray[i][j] = tempArray[i][bottom];
            tempArray[i][bottom] = tempChar;
            bottom--;
        }
    }

    cout << "TEMP ARRAY AFTER" << endl;
    if(maxY < 100 && maxX < 100){
        for(int i = 0; i < maxY; i++){
            for(int j = 0; j < maxX / 2; j++){
                cout << tempArray[i][j];
            }
            cout << endl;
        }
    }
    cout << "TEMP ARRAY AFTER" << endl;

    for(int i = 0; i < maxY; i++){
        for(int j = 0; j < maxX / 2; j++){
            if(tempArray[i][j] == '#' || myArray[i][j] == '#'){
                myArray[i][j] = '#';
            }
        }
    }

    for(int i = 0; i < maxX / 2; i++){
        delete[] tempArray[i];
    }
    delete[] tempArray;
}

void foldY(int foldLine, char **myArray, int maxY, int maxX){   
    char **tempArray = new char*[maxY / 2];
    for(int i = 0; i < maxY / 2; i++){
        tempArray[i] = new char[maxX];
    }

    for(int i = 0; i < maxY / 2; i++){
        for(int j = 0; j < maxX; j++){
            tempArray[i][j] = '.';
        }
    }
    
    for(int i = foldLine + 1; i < maxY; i++){
        for(int j = 0; j < maxX; j++){
            if(i > maxY / 2){
                tempArray[i - maxY / 2 - 1][j] = myArray[i][j];  
            }
        }
    }

    // cout << "TEMP ARRAY BEFORE" << endl;
    // for(int i = 0; i < maxY / 2; i++){
    //     for(int j = 0; j < maxX; j++){
    //         cout << tempArray[i][j];
    //     }
    //     cout << endl;
    // }
    // cout << "TEMP ARRAY BEFORE" << endl;
    
    string lineTemp;
    int bottom = maxY / 2 - 1;
    for(int i = 0; i < maxY / 4; i++){
        for(int j = 0; j < maxX; j++){
            lineTemp += tempArray[i][j];
        }   

        for(int j = 0; j < maxX; j++){
            tempArray[i][j] = tempArray[bottom][j];
            tempArray[bottom][j] = lineTemp[j];
        }

        bottom--;
        lineTemp = "";
    }

    // cout << "TEMP ARRAY AFTER" << endl;
    // for(int i = 0; i < maxY / 2; i++){
    //     for(int j = 0; j < maxX; j++){
    //         cout << tempArray[i][j];
    //     }
    //     cout << endl;
    // }
    // cout << "TEMP ARRAY AFTER" << endl;

    for(int i = 0; i < maxY / 2; i++){
        for(int j = 0; j < maxX; j++){
            if(tempArray[i][j] == '#' || myArray[i][j] == '#'){
                myArray[i][j] = '#';
            }
        }
    }
    for(int i = 0; i < maxY / 2; i++){
        delete[] tempArray[i];
    }
    delete[] tempArray;
}

int main(){

    fstream myFile("testInput.txt");

    vector<int> xCoords;
    vector<int> yCoords;
    vector<foldClass> foldVector;

    string line;
    int temp;
    while(getline(myFile, line)){
        if(line[0] != 'f' && line.size() > 2){
            istringstream ss(line);
            ss >> temp;
            xCoords.push_back(temp);

            ss.ignore();
            ss >> temp;
            yCoords.push_back(temp);
        }else if(line[0] == 'f'){
            foldClass tempFold;
            tempFold.XorY = line[11];
            tempFold.line = line[13] - '0';

            int index = foldVector.size();
            foldVector.push_back(tempFold);
        }
    }

    int xMax = 0, yMax = 0;
    for(int i = 0; i < xCoords.size(); i++){
        if(xCoords[i] > xMax){
            xMax = xCoords[i];
        }
        if(yCoords[i] > yMax){
            yMax = yCoords[i];
        }
    }

    // [yMax][xMax]
    cout << "xmax: " << xMax << ", ymax: " << yMax << endl;
    xMax++;
    yMax++;

    char **paperArray = new char*[yMax];
    for(int i = 0; i < yMax; i++){
        paperArray[i] = new char[xMax];
    }

    for(int i = 0; i < yMax; i++){
        for(int j = 0; j < xMax; j++){
            paperArray[i][j] = '.';
        }
    }

    for(int i = 0; i < yMax; i++){
        for(int j = 0; j < xMax; j++){
            for(int k = 0; k < xCoords.size(); k++){
                if(xCoords[k] == j && yCoords[k] == i){
                    paperArray[i][j] = '#';
                }
            }
        }
    }

    // if(foldVector[0].XorY == 'y'){
    //     foldY(foldVector[0].line, paperArray, yMax, xMax);
    //     yMax /= 2;
    // }
    

    // if(foldVector[1].XorY == 'x'){
    //     foldX(foldVector[1].line, paperArray, yMax, xMax);
    //     xMax /=2;
    // }

    // if(foldVector[0].XorY == 'x'){
    //     foldX(foldVector[0].line, paperArray, yMax, xMax);
    //     xMax /= 2;
    // }

    for(int i = 0; i < foldVector.size(); i++){
        if(i >= 8){
            cout << endl;
            for(int i = 0; i < yMax; i++){
                for(int j = 0; j < xMax; j++){
                    cout << paperArray[i][j];
                }
                cout << endl;
            }
        }

        if(foldVector[i].XorY == 'x'){
            foldX(foldVector[i].line, paperArray, yMax, xMax);
            xMax /= 2;
        }else if(foldVector[i].XorY == 'y'){
            foldY(foldVector[i].line, paperArray, yMax, xMax);
            yMax /= 2;
        }
    }

    cout << endl;
    for(int i = 0; i < yMax; i++){
        for(int j = 0; j < xMax; j++){
            cout << paperArray[i][j];
        }
        cout << endl;
    }

    int total = 0;
    for(int i = 0; i < yMax; i++){
        for(int j = 0; j < xMax; j++){
            if(paperArray[i][j] == '#'){
                total++;
            }
        }
    }

    cout << "Total: " << total << endl;

    return 0;
}