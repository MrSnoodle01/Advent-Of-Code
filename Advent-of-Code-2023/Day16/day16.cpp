#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class tile{
    public:
        char tileChar;
        bool isHitn;
        bool isHite;
        bool isHits;
        bool isHitw;
};

std::vector<std::string> input;
std::vector<std::vector<tile>> energizedInput; // change this vector to show energized tiles

// i and j are current coords, direction is current direction of travel(n,e,s,w)
void simBeam(int i, int j, char direction){
    energizedInput[i][j].tileChar = '#';
    switch(direction){
        case 'n':
            for(int i2 = i; i2 >= 0; i2--){
                if(input[i2][j] == '.'){
                    energizedInput[i2][j].tileChar = '#';
                }else 
                if(input[i2][j] == '-'){
                    if(!energizedInput[i2][j].isHitn && !energizedInput[i2][j].isHits){
                        energizedInput[i2][j].isHitn = true;
                        simBeam(i2, j, 'e');
                        simBeam(i2, j, 'w');
                    }
                    break;
                }else if(input[i2][j] == '\\'){
                    energizedInput[i2][j].tileChar = '#';
                    if(j - 1 >= 0)
                        simBeam(i2, j - 1, 'w');
                    break;
                }else if(input[i2][j] == '/'){
                    energizedInput[i2][j].tileChar = '#';
                    if(j + 1 < input[i].size())
                        simBeam(i2, j + 1, 'e');
                    break;
                }else if(input[i2][j] == '|'){
                    energizedInput[i2][j].tileChar = '#';
                }
            }
            break;
        case 'e':
            for(int j2 = j; j2 < input[i].size(); j2++){
                if(input[i][j2] == '.'){
                    energizedInput[i][j2].tileChar = '#';
                }else 
                if(input[i][j2] == '|'){
                    if(!energizedInput[i][j2].isHite && !energizedInput[i][j2].isHitw){
                        energizedInput[i][j2].isHite = true;
                        simBeam(i, j2, 'n');
                        simBeam(i, j2, 's');
                    }
                    break;
                }else if(input[i][j2] == '\\'){
                    energizedInput[i][j2].tileChar = '#';
                    if(i + 1 < input.size())
                        simBeam(i + 1, j2, 's');
                    break;
                }else if(input[i][j2] == '/'){
                    energizedInput[i][j2].tileChar = '#';
                    if(i - 1 >= 0)
                        simBeam(i - 1, j2, 'n');
                    break;
                }else if(input[i][j2] == '-'){
                    energizedInput[i][j2].tileChar = '#'; 
                }
            }
            break;
        case 's':
            for(int i2 = i; i2 < input.size(); i2++){
                if(input[i2][j] == '.'){
                    energizedInput[i2][j].tileChar = '#';
                }else 
                if(input[i2][j] == '-'){
                    if(!energizedInput[i2][j].isHitn && !energizedInput[i2][j].isHits){
                        energizedInput[i2][j].isHits = true;
                        simBeam(i2, j, 'e');
                        simBeam(i2, j, 'w');
                    }
                    break;
                }else if(input[i2][j] == '\\'){
                    energizedInput[i2][j].tileChar = '#';
                    energizedInput[i2][j].isHits = true;
                    if(j + 1 < input[i].size())
                        simBeam(i2, j + 1, 'e');
                    break;
                }else if(input[i2][j] == '/'){
                    energizedInput[i2][j].tileChar = '#';
                    energizedInput[i2][j].isHits = true;
                    if(j - 1 >= 0)
                        simBeam(i2, j - 1, 'w');
                    break;
                }else if(input[i2][j] == '|'){
                    energizedInput[i2][j].tileChar = '#';
                }
            }
            break;
        case 'w':
            for(int j2 = j; j2 >= 0; j2--){
                if(input[i][j2] == '.'){
                    energizedInput[i][j2].tileChar = '#';
                }else 
                if(input[i][j2] == '|'){
                    if(!energizedInput[i][j2].isHite && !energizedInput[i][j2].isHitw){
                        energizedInput[i][j2].isHitw = true;
                        simBeam(i, j2, 'n');
                        simBeam(i, j2, 's');
                    }
                    break;
                }else if(input[i][j2] == '\\'){
                    energizedInput[i][j2].tileChar = '#';
                    if(i - 1 >= 0)
                        simBeam(i - 1, j2, 'n');
                    break;
                }else if(input[i][j2] == '/'){
                    energizedInput[i][j2].tileChar = '#';
                    if(i + 1 < input.size())
                        simBeam(i + 1, j2, 's');
                    break;
                }else if(input[i][j2] == '-'){
                    energizedInput[i][j2].tileChar = '#'; 
                }
            }
            break;
    }
    // energizedInput[i][j] = '#';
}

void part1(){
    
    std::string line;
    std::fstream myfile("input.txt");
    std::vector<std::vector<tile>> reserveVector;
    while(std::getline(myfile, line)){
        input.push_back(line);
        std::vector<tile> tempV;
        for(int i = 0; i < line.size(); i++){
            tile temp;
            temp.isHitn = false;
            temp.isHite = false;
            temp.isHits = false;
            temp.isHitw = false;
            temp.tileChar = line[i];
            tempV.push_back(temp);
        }
        energizedInput.push_back(tempV);
        reserveVector.push_back(tempV);
    }

    simBeam(0, 0, 'e');

    int final = 0;
    for(int i = 0; i < energizedInput.size(); i++){
        for(int j = 0; j < energizedInput[i].size(); j++){
            if(energizedInput[i][j].tileChar == '#')
                final++;
            if(energizedInput[i][j].tileChar == '|' && (energizedInput[i][j].isHite || energizedInput[i][j].isHitw))
                final++;
            if(energizedInput[i][j].tileChar == '-' && (energizedInput[i][j].isHitn || energizedInput[i][j].isHits))
                final++;
        }
    }

    std::cout << "part 1 final: " << final << std::endl;
}

void part2(){
    std::string line;
    std::fstream myfile("input.txt");
    std::vector<std::vector<tile>> reserveVector;
    while(std::getline(myfile, line)){
        input.push_back(line);
        std::vector<tile> tempV;
        for(int i = 0; i < line.size(); i++){
            tile temp;
            temp.isHitn = false;
            temp.isHite = false;
            temp.isHits = false;
            temp.isHitw = false;
            temp.tileChar = line[i];
            tempV.push_back(temp);
        }
        energizedInput.push_back(tempV);
        reserveVector.push_back(tempV);
    }

    int final = 0;
    std::vector<int> finalNums;

    // do all of the left side
    for(int i = 0; i < input.size(); i++){
        simBeam(i, 0, 'e');
        for(int a = 0; a < energizedInput.size(); a++){
            for(int b = 0; b < energizedInput[a].size(); b++){
                if(energizedInput[a][b].tileChar == '#')
                    final++;
                if(energizedInput[a][b].tileChar == '|' && (energizedInput[a][b].isHite || energizedInput[a][b].isHitw))
                    final++;
                if(energizedInput[a][b].tileChar == '-' && (energizedInput[a][b].isHitn || energizedInput[a][b].isHits))
                    final++;
            }
        }
        finalNums.push_back(final);
        energizedInput = reserveVector;
        final = 0;
    }

    // do all of top row
    for(int j = 0; j < input[0].size(); j++){
        simBeam(0, j, 's');
        for(int a = 0; a < energizedInput.size(); a++){
            for(int b = 0; b < energizedInput[a].size(); b++){
                if(energizedInput[a][b].tileChar == '#')
                    final++;
                if(energizedInput[a][b].tileChar == '|' && (energizedInput[a][b].isHite || energizedInput[a][b].isHitw))
                    final++;
                if(energizedInput[a][b].tileChar == '-' && (energizedInput[a][b].isHitn || energizedInput[a][b].isHits))
                    final++;
            }
        }
        finalNums.push_back(final);
        energizedInput = reserveVector;
        final = 0;
    }

    // do all of right side
    for(int i = 0; i < input.size(); i++){
        simBeam(i, input[i].size() - 1, 'w');
        for(int a = 0; a < energizedInput.size(); a++){
            for(int b = 0; b < energizedInput[a].size(); b++){
                if(energizedInput[a][b].tileChar == '#')
                    final++;
                if(energizedInput[a][b].tileChar == '|' && (energizedInput[a][b].isHite || energizedInput[a][b].isHitw))
                    final++;
                if(energizedInput[a][b].tileChar == '-' && (energizedInput[a][b].isHitn || energizedInput[a][b].isHits))
                    final++;
            }
        }
        finalNums.push_back(final);
        energizedInput = reserveVector;
        final = 0;
    }

    // do all of bottom
    for(int j = 0; j < input[0].size(); j++){
        simBeam(input.size() - 1, j, 'n');
        for(int a = 0; a < energizedInput.size(); a++){
            for(int b = 0; b < energizedInput[a].size(); b++){
                if(energizedInput[a][b].tileChar == '#')
                    final++;
                if(energizedInput[a][b].tileChar == '|' && (energizedInput[a][b].isHite || energizedInput[a][b].isHitw))
                    final++;
                if(energizedInput[a][b].tileChar == '-' && (energizedInput[a][b].isHitn || energizedInput[a][b].isHits))
                    final++;
            }
        }
        finalNums.push_back(final);
        energizedInput = reserveVector;
        final = 0;
    }

    final = 0;
    for(int i = 0; i < finalNums.size(); i++){
        if(finalNums[i] > final)
            final = finalNums[i];
    }

    std::cout << "part 2 final: " << final << std::endl;
}

int main(){
    // global variables fuck it if both run at same time :)
    // part1();
    part2();
}