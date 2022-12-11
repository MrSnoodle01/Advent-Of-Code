#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

class monkey{
    public:
        std::vector<std::string> items;
        std::string operation;
        std::string operationNum;
        int test;
        int ifTrue;
        int ifFalse;
        long long inspectNum;
};

std::vector<monkey> monkeys;

std::string add(std::string, std::string);
std::string multiply(std::string, std::string);
std::string divide(std::string, int);
int mod(std::string, int);
void part1();
void part2();

int main(){
    std::fstream myfile("input.txt");

    int monkeyCount = 0;
    std::string line, tempString;
    monkey tempMonkey;
    tempMonkey.inspectNum = 0;
    while(std::getline(myfile, line)){
        monkeys.push_back(tempMonkey);
        for(int i = 0; i < 6; i++){
            std::stringstream ss(line);
            if(line[0] == 'M'){

            }else if(line[2] == 'S'){ //get items
                ss >> tempString;
                ss >> tempString;

                while(ss >> tempString){
                    if(tempString.back() == ',')
                        tempString.pop_back();
                    monkeys[monkeyCount].items.push_back(tempString);
                }
            }else if(line[2] == 'O'){
                ss.ignore(23);

                ss >> tempString;
                monkeys[monkeyCount].operation = tempString;

                ss >> tempString;
                monkeys[monkeyCount].operationNum = tempString;
            }else if(line[2] == 'T'){
                ss >> tempString;
                ss >> tempString;
                ss >> tempString;

                ss >> tempString;
                monkeys[monkeyCount].test = stoi(tempString);
            }else if(line[7] == 't'){
                ss.ignore(29);

                ss >> tempString;
                monkeys[monkeyCount].ifTrue = stoi(tempString);
            }else if(line[7] == 'f'){
                ss.ignore(30);

                ss >> tempString;
                monkeys[monkeyCount].ifFalse = stoi(tempString);
            }
            std::getline(myfile,line);
        }
        monkeyCount++;
    }

    part1();
    // part2();

    return 0;
}

void part1(){
    for(int i = 0; i < 20; i++){ //num rounds
        for(int j = 0; j < monkeys.size(); j++){ //do each monkey turn
            for(int k = 0; k < monkeys[j].items.size(); k++){ //get each item from monkey
                monkeys[j].inspectNum++;
                if(monkeys[j].operation == "+"){ 
                    monkeys[j].items[k] = add(monkeys[j].items[k], monkeys[j].operationNum);
                }else if(monkeys[j].operation == "*"){
                    if(monkeys[j].operationNum == "old"){
                        monkeys[j].items[k] = multiply(monkeys[j].items[k], monkeys[j].items[k]);
                    }else{
                        monkeys[j].items[k] = multiply(monkeys[j].items[k], monkeys[j].operationNum);
                    }
                }


                monkeys[j].items[k] = divide(monkeys[j].items[k], 3);


                if(mod(monkeys[j].items[k], monkeys[j].test) == 0){
                    monkeys[monkeys[j].ifTrue].items.push_back(monkeys[j].items[k]);
                    monkeys[j].items.erase(monkeys[j].items.begin());
                    k--;
                }else{
                    monkeys[monkeys[j].ifFalse].items.push_back(monkeys[j].items[k]);
                    monkeys[j].items.erase(monkeys[j].items.begin());
                    k--;
                }
            }
        }
    }

    int final = 0, top = 0, second = 0;
    for(int i = 0; i < monkeys.size(); i++){
        if(monkeys[i].inspectNum > top){
            top = monkeys[i].inspectNum;
        }else if(monkeys[i].inspectNum > second){
            second = monkeys[i].inspectNum;
        }
    }

    for(int i = 0; i < monkeys.size(); i++){
        if(monkeys[i].inspectNum > top){
            top = monkeys[i].inspectNum;
        }else if(monkeys[i].inspectNum > second && monkeys[i].inspectNum != top){
            second = monkeys[i].inspectNum;
        }
    }
    final = top * second;
    std::cout << "part1: " << final << std::endl;
}

void part2(){
    for(int i = 0; i < 500; i++){ //num rounds
        for(int j = 0; j < monkeys.size(); j++){ //do each monkey turn
            // std::cout << "MONKEY " << j << std::endl;
            for(int k = 0; k < monkeys[j].items.size(); k++){ //get each item from monkey
                // std::cout << "monkey inspects: " << monkeys[j].items[k] << std::endl;
                monkeys[j].inspectNum++;
                std::cout << "worry level: " << monkeys[j].items[k] << std::endl;
                if(monkeys[j].operation == "+"){ 
                    monkeys[j].items[k] = add(monkeys[j].items[k], monkeys[j].operationNum);
                }else if(monkeys[j].operation == "*"){
                    if(monkeys[j].operationNum == "old"){
                        monkeys[j].items[k] = multiply(monkeys[j].items[k], monkeys[j].items[k]);
                    }else{
                        monkeys[j].items[k] = multiply(monkeys[j].items[k], monkeys[j].operationNum);
                    }
                }

                std::cout << "worry level turns to: " << monkeys[j].items[k] << std::endl;

                if(mod(monkeys[j].items[k], monkeys[j].test) == 0){
                    std::cout << "is divisible" << std::endl << std::endl;
                    monkeys[monkeys[j].ifTrue].items.push_back(monkeys[j].items[k]);
                    monkeys[j].items.erase(monkeys[j].items.begin());
                    k--;
                }else{
                    std::cout << "not divisible" << std::endl << std::endl;
                    monkeys[monkeys[j].ifFalse].items.push_back(monkeys[j].items[k]);
                    monkeys[j].items.erase(monkeys[j].items.begin());
                    k--;
                }
            }
        }
    }

    for(int i = 0; i < monkeys.size(); i++){
        std::cout << "inspected: " << monkeys[i].inspectNum << std::endl;
    }


    long long final = 0, top = 0, second = 0;
    for(int i = 0; i < monkeys.size(); i++){
        if(monkeys[i].inspectNum > top){
            top = monkeys[i].inspectNum;
        }else if(monkeys[i].inspectNum > second){
            second = monkeys[i].inspectNum;
        }
    }

    for(int i = 0; i < monkeys.size(); i++){
        if(monkeys[i].inspectNum > top){
            top = monkeys[i].inspectNum;
        }else if(monkeys[i].inspectNum > second && monkeys[i].inspectNum != top){
            second = monkeys[i].inspectNum;
        }
    }

    final = top * second;
    std::cout << "part2: " << final << std::endl;
    std::cout << "top: " << top << ", second: " << second << std::endl;

}

//stole this from geeksforgeeks
std::string divide(std::string number, int divisor)
{
    // As result can be very large store it in string
    std::string ans;
 
    // Find prefix of number that is larger
    // than divisor.
    int idx = 0;
    int temp = number[idx] - '0';
    while (temp < divisor)
        temp = temp * 10 + (number[++idx] - '0');
 
    // Repeatedly divide divisor with temp. After
    // every division, update temp to include one
    // more digit.
    while (number.size() > idx) {
        // Store result in answer i.e. temp / divisor
        ans += (temp / divisor) + '0';
 
        // Take next digit of number
        temp = (temp % divisor) * 10 + number[++idx] - '0';
    }
 
    // If divisor is greater than number
    if (ans.length() == 0)
        return "0";
 
    // else return ans
    return ans;
}

//stole this from geeksforgeeks
std::string multiply(std::string num1, std::string num2)
{
    int len1 = num1.size();
    int len2 = num2.size();
    if (len1 == 0 || len2 == 0)
    return "0";
 
    // will keep the result number in vector
    // in reverse order
    std::vector<int> result(len1 + len2, 0);
 
    // Below two indexes are used to find positions
    // in result.
    int i_n1 = 0;
    int i_n2 = 0;
     
    // Go from right to left in num1
    for (int i=len1-1; i>=0; i--)
    {
        int carry = 0;
        int n1 = num1[i] - '0';
 
        // To shift position to left after every
        // multiplication of a digit in num2
        i_n2 = 0;
         
        // Go from right to left in num2            
        for (int j=len2-1; j>=0; j--)
        {
            // Take current digit of second number
            int n2 = num2[j] - '0';
 
            // Multiply with current digit of first number
            // and add result to previously stored result
            // at current position.
            int sum = n1*n2 + result[i_n1 + i_n2] + carry;
 
            // Carry for next iteration
            carry = sum/10;
 
            // Store result
            result[i_n1 + i_n2] = sum % 10;
 
            i_n2++;
        }
 
        // store carry in next cell
        if (carry > 0)
            result[i_n1 + i_n2] += carry;
 
        // To shift position to left after every
        // multiplication of a digit in num1.
        i_n1++;
    }
 
    // ignore '0's from the right
    int i = result.size() - 1;
    while (i>=0 && result[i] == 0)
    i--;
 
    // If all were '0's - means either both or
    // one of num1 or num2 were '0'
    if (i == -1)
    return "0";
 
    // generate the result string
    std::string s = "";
     
    while (i >= 0)
        s += std::to_string(result[i--]);
 
    return s;
}

//stole this from geeksforgeeks
std::string add(std::string str1, std::string str2)
{
    // Before proceeding further, make sure length
    // of str2 is larger.
    if (str1.length() > str2.length())
        swap(str1, str2);
 
    // Take an empty string for storing result
    std::string str = "";
 
    // Calculate length of both string
    int n1 = str1.length(), n2 = str2.length();
    int diff = n2 - n1;
 
    // Initially take carry zero
    int carry = 0;
 
    // Traverse from end of both strings
    for (int i=n1-1; i>=0; i--)
    {
        // Do school mathematics, compute sum of
        // current digits and carry
        int sum = ((str1[i]-'0') +
                   (str2[i+diff]-'0') +
                   carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }
 
    // Add remaining digits of str2[]
    for (int i=n2-n1-1; i>=0; i--)
    {
        int sum = ((str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }
 
    // Add remaining carry
    if (carry)
        str.push_back(carry+'0');
 
    // reverse resultant string
    reverse(str.begin(), str.end());
 
    return str;
}

//stole this from geeksforgeeks
int mod(std::string num, int a)
{
    // Initialize result
    int res = 0;
 
    // One by one process all digits of 'num'
    for (int i = 0; i < num.length(); i++)
        res = (res * 10 + (int)num[i] - '0') % a;
 
    return res;
}