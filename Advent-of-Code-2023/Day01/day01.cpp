#include <iostream>
#include <vector>
#include <fstream>
#include <string>

int main(){
    std::vector<std::string> input;
    
    std::ifstream myfile("input.txt");

    std::string line;
    while(std::getline(myfile, line)){
        input.push_back(line);
    }

    std::vector<char> nums;
    int final = 0;
    for(int i = 0; i < input.size(); i++){
        nums.clear();
        for(int j = 0; j < input[i].size(); j++){
            if(isdigit(input[i][j])){
                nums.push_back(input[i][j]);
            }else if(input[i][j] == 'o'){
                if(input[i][j + 1] == 'n'){
                    if(input[i][j + 2] == 'e'){
                        nums.push_back('1');
                    }
                }
            }else if(input[i][j] == 't'){
                if(input[i][j + 1] == 'w'){
                    if(input[i][j + 2] == 'o'){
                        nums.push_back('2');
                    }
                }
                if(input[i][j + 1] == 'h'){
                    if(input[i][j + 2] == 'r'){
                        if(input[i][j + 3] == 'e'){
                            if(input[i][j + 4] == 'e'){
                                nums.push_back('3');
                            }
                        }
                    }
                }
            }else if(input[i][j] == 'f'){
                if(input[i][j + 1] == 'o'){
                    if(input[i][j + 2] == 'u'){
                        if(input[i][j + 3] == 'r'){
                            nums.push_back('4');
                        }
                    }
                }
                if(input[i][j + 1] == 'i'){
                    if(input[i][j + 2] == 'v'){
                        if(input[i][j + 3] == 'e'){
                            nums.push_back('5');
                        }
                    }
                }
            }if(input[i][j] == 's'){
                if(input[i][j + 1] == 'i'){
                    if(input[i][j + 2] == 'x'){
                        nums.push_back('6');
                    }
                }
                if(input[i][j + 1] == 'e'){
                    if(input[i][j + 2] == 'v'){
                        if(input[i][j + 3] == 'e'){
                            if(input[i][j + 4] == 'n'){
                                nums.push_back('7');
                            }
                        }
                    }
                }
            }if(input[i][j] == 'e'){
                if(input[i][j + 1] == 'i'){
                    if(input[i][j + 2] == 'g'){
                        if(input[i][j + 3] == 'h'){
                            if(input[i][j + 4] == 't'){
                                nums.push_back('8');
                            }
                        }
                    }
                }
            }if(input[i][j] == 'n'){
                if(input[i][j + 1] == 'i'){
                    if(input[i][j + 2] == 'n'){
                        if(input[i][j + 3] == 'e'){
                            nums.push_back('9');
                        }
                    }
                }
            }
        }
        int temp1 = ((nums[0]) - '0') * 10;
        int temp2 = nums[nums.size() - 1] - '0';
        final += temp1 + temp2;
    }

    std::cout << final << std::endl;
}