#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <unordered_map>

class myClass{
    public:
        int bid;
        std::string hand;

        bool operator>(myClass const& obj){
            for(int i = 0; i < hand.size(); i++){
                if(hand[i] == obj.hand[i]){

                }else if(hand[i] == 'A' && obj.hand[i] != 'A'){
                    return true;
                }else if(hand[i] != 'A' && obj.hand[i] == 'A'){
                    return false;
                }else if(hand[i] == 'K' && obj.hand[i] != 'K'){
                    return true;
                }else if(hand[i] != 'K' && obj.hand[i] == 'K'){
                    return false;
                }else if(hand[i] == 'Q' && obj.hand[i] != 'Q'){
                    return true;
                }else if(hand[i] != 'Q' && obj.hand[i] == 'Q'){
                    return false;
                }else if(hand[i] == 'T' && obj.hand[i] != 'T'){
                    return true;
                }else if(hand[i] != 'T' && obj.hand[i] == 'T'){
                    return false;
                }else if(hand[i] > obj.hand[i] && hand[i] != 'J' && obj.hand[i] != 'J'){
                    return true;
                }else if(hand[i] < obj.hand[i] && hand[i] != 'J' && obj.hand[i] != 'J'){
                    return false;
                }else if(hand[i] == 'J' && obj.hand[i] != 'J'){
                    return false;
                }else if(hand[i] != 'J' && obj.hand[i] == 'J'){
                    return true;
                }else{
                    std::cout << "if you see this you fucked something up" << std::endl;    
                }
            }
            return false;
        }
};

void part1(){
    std::vector<myClass> hands;
    std::vector<myClass> fiveKind, fourKind, fullHouse, threeKind, twoPair, onePair, highCard;
    std::vector<myClass> orderedHands; // ordered hands from strongest >> weakest
    std::string line;
    std::ifstream myfile("input.txt");

    while(myfile >> line){
        myClass temp;
        temp.hand = line;
        myfile >> line;
        temp.bid = stoi(line);
        hands.push_back(temp);
    }

    for(int i = 0; i < hands.size(); i++){ // add each hand to proper type vector
        std::unordered_map<char, int> temp;
        temp['A'] = 0;
        temp['K'] = 0;
        temp['Q'] = 0;
        temp['J'] = 0;
        temp['T'] = 0;
        for(int j = 2; j <= 9; j++){
            temp[j + '0'] = 0;
        }
        for(int j = 0; j < hands[i].hand.size(); j++){
            temp[hands[i].hand[j]]++;
        }
        int highest = 0;
        for(auto x : temp){
            if(x.second > highest){
                highest = x.second;
            }
        }
        if(highest == 3){
            bool isFull = false;
            for(auto x : temp){
                if(x.second == 2){
                    isFull = true;
                    fullHouse.push_back(hands[i]);  // push to full house
                }
            }
            if(!isFull)
                threeKind.push_back(hands[i]);      // push to 3 of a kind
        }else if(highest == 2){                      // check for 2 pair
            int numTwo = 0;
            for(auto x : temp){
                if(x.second == 2){
                    numTwo++;
                }
            }
            if(numTwo == 2)
                twoPair.push_back(hands[i]);        // push to 2 pair
            else if(numTwo == 1)
                onePair.push_back(hands[i]);        // push to pair
        }else if(highest == 5){                     // push to 5 of a kind
            fiveKind.push_back(hands[i]);
        }else if(highest == 4){                     // push to 4 of a kind
            fourKind.push_back(hands[i]);
        }else{                                      // push to high card
            highCard.push_back(hands[i]);
        }
    }

    // sort each type vector so that strongest hand is at highest element
    // then insert them into the ordered vector
    myClass key;
    // five of a kind
    if(fiveKind.size() > 1){
        for(int i = 1; i < fiveKind.size(); i++){
            key = fiveKind[i];
            int j = i - 1;

            while(j >= 0 && fiveKind[j] > key){
                fiveKind[j + 1] = fiveKind[j];
                j = j - 1;
            }
            fiveKind[j + 1] = key;
        }
    }
    for(int i = fiveKind.size() - 1; i >= 0; i--){
        orderedHands.push_back(fiveKind[i]);
    }

    // four of a kind
    if(fourKind.size() > 1){
        for(int i = 1; i < fourKind.size(); i++){
            key = fourKind[i];
            int j = i - 1;

            while(j >= 0 && fourKind[j] > key){
                fourKind[j + 1] = fourKind[j];
                j = j - 1;
            }
            fourKind[j + 1] = key;
        } 
    }
    for(int i = fourKind.size() - 1; i >= 0; i--){
        orderedHands.push_back(fourKind[i]);
    }

    // full house
    if(fullHouse.size() > 1){
        for(int i = 1; i < fullHouse.size(); i++){
            key = fullHouse[i];
            int j = i - 1;

            while(j >= 0 && fullHouse[j] > key){
                fullHouse[j + 1] = fullHouse[j];
                j = j - 1;
            }
            fullHouse[j + 1] = key;
        }
    }
    for(int i = fullHouse.size() - 1; i >= 0; i--){
        orderedHands.push_back(fullHouse[i]);
    }

    // three of a kind
    if(threeKind.size() > 1){
        for(int i = 1; i < threeKind.size(); i++){
            key = threeKind[i];
            int j = i - 1;

            while(j >= 0 && threeKind[j] > key){
                threeKind[j + 1] = threeKind[j];
                j = j - 1;
            }
            threeKind[j + 1] = key;
        }
    }
    for(int i = threeKind.size() - 1; i >= 0; i--){
        orderedHands.push_back(threeKind[i]);
    }

    // two pair
    if(twoPair.size() > 1){
        for(int i = 1; i < twoPair.size(); i++){
            key = twoPair[i];
            int j = i - 1;

            while(j >= 0 && twoPair[j] > key){
                twoPair[j + 1] = twoPair[j];
                j = j - 1;
            }
            twoPair[j + 1] = key;
        }
    }
    for(int i = twoPair.size() - 1; i >= 0; i--){
        orderedHands.push_back(twoPair[i]);
    }

    // one pair
    if(onePair.size() > 1){
        for(int i = 1; i < onePair.size(); i++){
            key = onePair[i];
            int j = i - 1;

            while(j >= 0 && onePair[j] > key){
                onePair[j + 1] = onePair[j];
                j = j - 1;
            }
            onePair[j + 1] = key;
        } 
    }
    for(int i = onePair.size() - 1; i >= 0; i--){
        orderedHands.push_back(onePair[i]);
    }

    // high card
    if(highCard.size() > 1){
        for(int i = 1; i < highCard.size(); i++){
            key = highCard[i];
            int j = i - 1;

            while(j >= 0 && highCard[j] > key){
                highCard[j + 1] = highCard[j];
                j = j - 1;
            }
            highCard[j + 1] = key;
        }
    }
    for(int i = highCard.size() - 1; i >= 0; i--){
        orderedHands.push_back(highCard[i]);
    }

    long int final = 0, rank = orderedHands.size();

    for(int i = 0; i < orderedHands.size(); i++){
        final += orderedHands[i].bid * rank;
        rank--;
    }

    std::cout << "part 1 final: " << final << std::endl;
}

void part2(){
    std::vector<myClass> hands;
    std::vector<myClass> fiveKind, fourKind, fullHouse, threeKind, twoPair, onePair, highCard;
    std::vector<myClass> orderedHands; // ordered hands from strongest >> weakest
    std::string line;
    std::ifstream myfile("input.txt");

    while(myfile >> line){
        myClass temp;
        temp.hand = line;
        myfile >> line;
        temp.bid = stoi(line);
        hands.push_back(temp);
    }

    for(int i = 0; i < hands.size(); i++){ // add each hand to proper type vector
        std::unordered_map<char, int> temp;
        temp['A'] = 0;
        temp['K'] = 0;
        temp['Q'] = 0;
        temp['J'] = 0;
        temp['T'] = 0;
        for(int j = 2; j <= 9; j++){
            temp[j + '0'] = 0;
        }
        for(int j = 0; j < hands[i].hand.size(); j++){
                temp[hands[i].hand[j]]++;
        }
        int highest = 0;
        for(auto x : temp){
            if(!(x.first == 'J')){ // dont check for number of jokers in hand
                if(x.second > highest){
                    highest = x.second;
                }
            }
        }

        // change strongest hand based on number of jokers
        if(temp['J'] == 5){ // JJJJJ > 5 of a kind
            highest += 5;
        }else if(highest == 4 && temp['J'] == 1){ // AAJAA > 5 of a kind
            highest++;
        }else if(highest == 3 && temp['J'] == 2){ // AAJJA > 5 of a kind
            highest += 2;
        }else if(highest == 3 && temp['J'] == 1){ // AAJAK > 4 of a kind
            highest++;
        }else if(highest == 2 && temp['J'] == 3){ // AJJJA > 5 of a kind
            highest += 3;
        }else if(highest == 2 && temp['J'] == 2){ // AAKJJ > 4 of a kind
            highest += 2;
        }else if(highest == 2 && temp['J'] == 1){ // AAKKJ > full house, AAKJQ > 3 of a kind
            highest++;
        }else if(highest == 1 && temp['J'] == 4){ // AJJJJ > 5 of a kind
            highest += 4;
        }else if(highest == 1 && temp['J'] == 3){ // AJJJK > 4 of a kind
            highest += 3;
        }else if(highest == 1 && temp['J'] == 2){ // AJJKQ > 3 of a kind
            highest += 2;
        }else if(highest == 1 && temp['J'] == 1){ // AJKQT > one pair
            highest++;
        }

        if(highest == 3){
            bool isFull = false;
            int numTwo = 0;
            if(temp['J'] == 1){
                for(auto x : temp){ // check if there is actually a 3 of the same card to determine if full house possibility or  not
                    if(x.second == 2){
                        numTwo++;
                    }
                }
                if(numTwo == 2){
                    fullHouse.push_back(hands[i]);      // push to full house
                }else if(numTwo == 1){
                    threeKind.push_back(hands[i]);      // push to 3 of  akind
                }
            }else{
                for(auto x : temp){ 
                    if(!isFull){
                        if(x.second == 2 && x.first != 'J'){
                            isFull = true;
                            fullHouse.push_back(hands[i]);  // push to full house
                        }
                    }
                }
                if(!isFull)
                    threeKind.push_back(hands[i]);   // push to 3 of a kind
            }
        }else if(highest == 2){                      // check for 2 pair
            int numTwo = 0;
            for(auto x : temp){
                if(x.second == 2){
                    numTwo++;
                }
            }
            if(numTwo == 2)
                twoPair.push_back(hands[i]);        // push to 2 pair
            else if(numTwo == 1 || numTwo == 0)
                onePair.push_back(hands[i]);        // push to pair
        }else if(highest == 5){                     // push to 5 of a kind
            fiveKind.push_back(hands[i]);
        }else if(highest == 4){                     // push to 4 of a kind
            fourKind.push_back(hands[i]);
        }else{                                      // push to high card
            highCard.push_back(hands[i]);
        }
    }

    // sort each type vector so that strongest hand is at highest element
    // then insert them into the ordered vector
    myClass key;
    // five of a kind
    if(fiveKind.size() > 1){
        for(int i = 1; i < fiveKind.size(); i++){
            key = fiveKind[i];
            int j = i - 1;

            while(j >= 0 && fiveKind[j] > key){
                fiveKind[j + 1] = fiveKind[j];
                j = j - 1;
            }
            fiveKind[j + 1] = key;
        }
    }
    for(int i = fiveKind.size() - 1; i >= 0; i--){
        orderedHands.push_back(fiveKind[i]);
    }

    // four of a kind
    if(fourKind.size() > 1){
        for(int i = 1; i < fourKind.size(); i++){
            key = fourKind[i];
            int j = i - 1;

            while(j >= 0 && fourKind[j] > key){
                fourKind[j + 1] = fourKind[j];
                j = j - 1;
            }
            fourKind[j + 1] = key;
        } 
    }
    for(int i = fourKind.size() - 1; i >= 0; i--){
        orderedHands.push_back(fourKind[i]);
    }

    // full house
    if(fullHouse.size() > 1){
        for(int i = 1; i < fullHouse.size(); i++){
            key = fullHouse[i];
            int j = i - 1;

            while(j >= 0 && fullHouse[j] > key){
                fullHouse[j + 1] = fullHouse[j];
                j = j - 1;
            }
            fullHouse[j + 1] = key;
        }
    }
    for(int i = fullHouse.size() - 1; i >= 0; i--){
        orderedHands.push_back(fullHouse[i]);
    }

    // three of a kind
    if(threeKind.size() > 1){
        for(int i = 1; i < threeKind.size(); i++){
            key = threeKind[i];
            int j = i - 1;

            while(j >= 0 && threeKind[j] > key){
                threeKind[j + 1] = threeKind[j];
                j = j - 1;
            }
            threeKind[j + 1] = key;
        }
    }
    for(int i = threeKind.size() - 1; i >= 0; i--){
        orderedHands.push_back(threeKind[i]);
    }

    // two pair
    if(twoPair.size() > 1){
        for(int i = 1; i < twoPair.size(); i++){
            key = twoPair[i];
            int j = i - 1;

            while(j >= 0 && twoPair[j] > key){
                twoPair[j + 1] = twoPair[j];
                j = j - 1;
            }
            twoPair[j + 1] = key;
        }
    }
    for(int i = twoPair.size() - 1; i >= 0; i--){
        orderedHands.push_back(twoPair[i]);
    }

    // one pair
    if(onePair.size() > 1){
        for(int i = 1; i < onePair.size(); i++){
            key = onePair[i];
            int j = i - 1;

            while(j >= 0 && onePair[j] > key){
                onePair[j + 1] = onePair[j];
                j = j - 1;
            }
            onePair[j + 1] = key;
        } 
    }
    for(int i = onePair.size() - 1; i >= 0; i--){
        orderedHands.push_back(onePair[i]);
    }

    // high card
    if(highCard.size() > 1){
        for(int i = 1; i < highCard.size(); i++){
            key = highCard[i];
            int j = i - 1;

            while(j >= 0 && highCard[j] > key){
                highCard[j + 1] = highCard[j];
                j = j - 1;
            }
            highCard[j + 1] = key;
        }
    }
    for(int i = highCard.size() - 1; i >= 0; i--){
        orderedHands.push_back(highCard[i]);
    }

    long int final = 0, rank = orderedHands.size();

    for(int i = 0; i < fullHouse.size(); i++){
        std::cout << fullHouse[i].hand << std::endl;
    }

    for(int i = 0; i < orderedHands.size(); i++){
        // std::cout << orderedHands[i].hand << std::endl;
        final += orderedHands[i].bid * rank;
        rank--;
    }
    std::cout << orderedHands.size() << std::endl;

    std::cout << "part 2 final: " << final << std::endl;
}

int main(){
    part1();
    part2();
}