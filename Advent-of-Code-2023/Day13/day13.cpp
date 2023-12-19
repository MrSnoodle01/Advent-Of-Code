#include <vector>
#include <string>
#include <iostream>
#include <fstream>

int testHorizontal1(std::vector<std::string> mirror){
    for(int i = 0; i < mirror.size() - 1; i++){
        if(mirror[i] == mirror[i + 1]){
            bool reflects = true;
            int index = 2;
            while(reflects){
                if(i + index >= mirror.size() || i - index + 1 < 0){
                    return i + 1;
                }
                if(mirror[i - index + 1] != mirror[i + index]){
                    reflects = false;
                }
                index++;
            }
        }
    }
    return 0;
}

int testVertical1(std::vector<std::string> mirror){
    // turn the mirror on its side so we can easily check horizontals but stil have them count as verticals
    std::vector<std::string> rotatedMirror;
    int index = 0;
    std::string temp = "";
    for(int i = 0; i < mirror[0].size(); i++){
        for(int j = 0; j < mirror.size(); j++){
            temp += mirror[j][i];
        }
        rotatedMirror.push_back(temp);
        temp.clear();
        index++;
    }   

    int final = testHorizontal1(rotatedMirror);

    if(final > 0)
        return final;
    else   
        return 0;
}

class myClass{
    public:
        bool isVert;
        int index;
};

bool offByOne(std::string string1, std::string string2){ // checks if the strings have one char different
    int diffs = 0;
    for(int i = 0; i < string1.size(); i++){
        if(string1[i] != string2[i])
            diffs++;
    }
    if(diffs == 1)
        return true;
    else
        return false;
}

int testHorizontal2(std::vector<std::string> mirror, bool wasVertical, int indexNum){
    for(int i = 0; i < mirror.size() - 1; i++){
        if(!wasVertical)
            if(i == indexNum)
                i++;
        if(i >= mirror.size() - 1)
            break;
        
        int smudgeNum = 0;
        if(mirror[i] == mirror[i + 1] || offByOne(mirror[i], mirror[i + 1])){
            if(offByOne(mirror[i], mirror[i + 1]))
                smudgeNum++;
            bool reflects = true;
            int index = 2;
            while(reflects){
                
                if(i + index >= mirror.size() || i - index + 1 < 0){
                    return i + 1;
                }
                if(mirror[i - index + 1] != mirror[i + index]){
                    if(!offByOne(mirror[i - index + 1], mirror[i + index]))
                        reflects = false;
                }
                if(offByOne(mirror[i - index + 1], mirror[i + index]))
                    smudgeNum++;
                if(smudgeNum > 1)
                    reflects = false;
                index++;
            }
        }
    }
    return 0;
}

int testVertical2(std::vector<std::string> mirror, bool wasVertical, int indexNum){
    // rotate the mirror 90 degrees so we can easily check horizontals but stil have them count as verticals
    std::vector<std::string> rotatedMirror;
    std::string temp = "";
    for(int i = 0; i < mirror[0].size(); i++){
        for(int j = 0; j < mirror.size(); j++){
            temp += mirror[j][i];
        }
        rotatedMirror.push_back(temp);
        temp.clear();
    }   

    for(int i = 0; i < rotatedMirror.size() - 1; i++){
        if(wasVertical)
            if(i == indexNum)
                i++;
        if(i >= rotatedMirror.size() - 1)
            break;
        
        int smudgeNum = 0;
        if(rotatedMirror[i] == rotatedMirror[i + 1] || offByOne(rotatedMirror[i], rotatedMirror[i + 1])){
            if(offByOne(rotatedMirror[i], rotatedMirror[i + 1]))
                smudgeNum++;
            bool reflects = true;
            int index = 2;
            while(reflects){
                if(i + index >= rotatedMirror.size() || i - index + 1 < 0){
                    return i + 1;
                }
                if(rotatedMirror[i - index + 1] != rotatedMirror[i + index]){
                    if(!offByOne(rotatedMirror[i - index + 1], rotatedMirror[i + index]))
                        reflects = false;
                }
                if(offByOne(rotatedMirror[i - index + 1], rotatedMirror[i + index]))
                    smudgeNum++;
                if(smudgeNum > 1)
                    reflects = false;
                index++;
            }
        }
    }
    return 0;
}

void part1(){
    std::vector<std::vector<std::string>> input;
    std::fstream myfile("input.txt");
    std::string line;
    std::vector<std::string> temp;
    while(std::getline(myfile, line)){
        if(line[0] != '.' && line[0] != '#'){ // check for blankspace between mirrors
            input.push_back(temp);
            temp.clear();
        }else{
            if(line[line.size() - 1] != '.' && line[line.size() - 1] != '#')
                line.pop_back();
            temp.push_back(line);
        }
    }
    input.push_back(temp);

    int final = 0;

    for(int i = 0; i < input.size(); i++){
        final += testVertical1(input[i]);
        final += 100 * testHorizontal1(input[i]);
    }


    std::cout << "part 1 final: " << final << std::endl;
}

void part2(){
    std::vector<std::vector<std::string>> input;
    std::fstream myfile("input.txt");
    std::string line;
    std::vector<std::string> temp;
    while(std::getline(myfile, line)){
        if(line[0] != '.' && line[0] != '#'){ // check for blankspace between mirrors
            input.push_back(temp);
            temp.clear();
        }else{
            if(line[line.size() - 1] != '.' && line[line.size() - 1] != '#')
                line.pop_back();
            temp.push_back(line);
        }
    }
    input.push_back(temp);

    std::vector<myClass> oldValues;

    for(int i = 0; i < input.size(); i++){
        myClass temp;
        int v = testVertical1(input[i]);
        int h = testHorizontal1(input[i]);
        if(v > 0){
            temp.isVert = true;
            temp.index = v - 1;
            
        }
        if(h > 0){
            temp.isVert = false;
            temp.index = h - 1;
        }
        oldValues.push_back(temp);
    }

    int final = 0;
    for(int i = 0; i < input.size(); i++){
        final += testVertical2(input[i], oldValues[i].isVert, oldValues[i].index);
        final += 100 * testHorizontal2(input[i], oldValues[i].isVert, oldValues[i].index);
    }

    std::cout << "part 2 final: " << final << std::endl;
}

int main(){
    part1();
    part2();
}