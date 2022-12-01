#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <bitset>

using namespace std;

string hexToBin(string hexString){
    string returnString;
    for(int i = 0; i < hexString.size(); i++){
 
        switch (hexString[i]) {
        case '0':
            returnString += "0000";
            break;
        case '1':
            returnString += "0001";
            break;
        case '2':
            returnString += "0010";
            break;
        case '3':
            returnString += "0011";
            break;
        case '4':
            returnString += "0100";
            break;
        case '5':
            returnString += "0101";
            break;
        case '6':
            returnString += "0110";
            break;
        case '7':
            returnString += "0111";
            break;
        case '8':
            returnString += "1000";
            break;
        case '9':
            returnString += "1001";
            break;
        case 'A':
            returnString += "1010";
            break;
        case 'B':
            returnString += "1011";
            break;
        case 'C':
            returnString += "1100";
            break;
        case 'D':
            returnString += "1101";
            break;
        case 'E':
            returnString += "1110";
            break;
        case 'F':
            returnString += "1111";
            break;
        }
    }
    return returnString;
}

// get sub packets within a packet
void getSubPackets(string packet, vector<string> &subPackets){

    string tempSubPacket;
    for(int i = 1; i < 7; i++){
        tempSubPacket += packet[i];
    }

    string tempTypeID;
    tempTypeID += packet[4];
    tempTypeID += packet[5];
    tempTypeID += packet[6];

    bitset<8> tempBit(tempTypeID);
    if(tempBit.to_ulong() != 4){ // if the subpacket is not a literal
        char lengthTypeID = packet[7];
        tempSubPacket += packet[7];
        if(lengthTypeID == '0'){ // next 15 bits = total length of bits
            string lengthOfBits;
            for(int i = 0; i < 15; i++){
                lengthOfBits += packet[i + 8];
                tempSubPacket += packet[i + 8]; // adds the next 15 bits since lengthtypeid = 0
            }

            bitset<64> bitsLengthOfBits(lengthOfBits);
            int totalBits = bitsLengthOfBits.to_ulong();

            for(int i = 23; i < totalBits + 23; i++){
                tempSubPacket += packet[i]; 
            }
            subPackets.push_back(tempSubPacket);
            if(totalBits + 23 < packet.size() - 10){
                string temp = " ";
                for(int j = totalBits + 23; j < packet.size(); j++){
                    temp += packet[j];
                }
                getSubPackets(temp, subPackets);
            }
        }else{ // next 11 bits = number of sub-packets
            string numOfSubPackets;
            for(int i = 0; i < 11; i++){
                numOfSubPackets += packet[i + 8];
            }
            bitset<16> bitNumOfSubPackets(numOfSubPackets);
            int totalSubPackets = bitNumOfSubPackets.to_ulong();

            int start = 19;
            for(int i = 1; i < totalSubPackets + 1; i++){
                string tempPacket;
                for(int j = start; j < 19 + 11 * i; j+=5){
                    tempPacket += packet[j];
                } 
                start += 11;
                subPackets.push_back(tempPacket);
                tempPacket.clear();
            }
            
        }
    }else{
        for(int i = 7; i < packet.size(); i+=5){
            if(packet[i] == '1'){
                tempSubPacket += packet[i];
                tempSubPacket += packet[i + 1];
                tempSubPacket += packet[i + 2];
                tempSubPacket += packet[i + 3];
                tempSubPacket += packet[i + 4];
            }else if(packet[i] == '0'){
                tempSubPacket += packet[i];
                tempSubPacket += packet[i + 1];
                tempSubPacket += packet[i + 2];
                tempSubPacket += packet[i + 3];
                tempSubPacket += packet[i + 4];
                subPackets.push_back(tempSubPacket);

                if(i < packet.size() - 10){
                    string temp = " ";
                    for(int j = i + 5; j < packet.size(); j++){
                        temp += packet[j];
                    }
                    getSubPackets(temp, subPackets);
                }
                break;
            }
        }
    }
    return;
}

// parse all the packets to return the version numbers
void parsePacket(string packet, int &total){
    cout << "packet: " << packet << endl;

    string packetVersion, packetTypeID;
    // get packet version
    packetVersion += packet[0];
    packetVersion += packet[1];
    packetVersion += packet[2];
    cout << " aspiodufhasfhsdouiasdf" << endl;
    bitset<8> bitsVersion(packetVersion);
    total += bitsVersion.to_ulong();
    cout << "asdfjh" << endl;
    // get packet type ID
    packetTypeID += packet[3];
    packetTypeID += packet[4];
    packetTypeID += packet[5];

    bitset<8> bitsPacketTypeID(packetTypeID);
    if(bitsPacketTypeID.to_ulong() != 4){
        char lengthTypeID = packet[6];
        if(lengthTypeID == '0'){ // next 15 bits will be total length of bits in sub-packets
            string lengthOfBits;
            for(int i = 0; i < 15; i++){
                lengthOfBits += packet[i + 7];
            }
            bitset<64> bitsLengthOfBits(lengthOfBits);
            int totalBits = bitsLengthOfBits.to_ulong();

            vector<string> subPackets; 
            string tempSubPacket = " ";
            for(int i = 22; i < totalBits + 22; i++){// i = 22 so that we start after length of bits
                tempSubPacket += packet[i]; // gets entire packet afterwards to make splitting it up into sub-packets easier
            }

            getSubPackets(tempSubPacket, subPackets);
            for(int i = 0; i < subPackets.size(); i++){
                cout << "subPacket: " << subPackets[i] << endl;
            }

            for(int i = 0; i < subPackets.size(); i++){
                parsePacket(subPackets[i], total);
            }
        }else{ // next 11 bits will be total number of sub-packets
            string numOfSubPacket;
            for(int i = 0; i < 11; i++){
                numOfSubPacket += packet[i + 7];
            }
            // bitset<16> bitNumOfSubPacket(numOfSubPacket);
            // int totalSubPackets = bitNumOfSubPacket.to_ulong();

            vector<string> subPackets;
            string tempSubPacket = " ";
            for(int i = 0; i < 18; i++){
                tempSubPacket += packet[i];
            }

            getSubPackets(tempSubPacket, subPackets);
            for(int i = 0; i < subPackets.size(); i++){
                cout << "subPacket: " << subPackets[i] << endl;
                parsePacket(subPackets[i], total);
            }
        }
    }else{
        // IF PACKET REPRESENTS A LITERAL VALUE
        string newLine = " ";
        for(int i = 6; i < packet.size(); i++){
            newLine += packet[i];
        }

        cout << "new line: " << newLine << endl;

        // converting the binary recieved from input to actual binary
        string finalBits;
        for(int i = 1; i < newLine.size(); i+=5){
            if(newLine[i] == '1'){  
                finalBits += newLine[i + 1];
                finalBits += newLine[i + 2];
                finalBits += newLine[i + 3];
                finalBits += newLine[i + 4];
            }else if(newLine[i] == '0'){
                finalBits += newLine[i + 1];
                finalBits += newLine[i + 2];
                finalBits += newLine[i + 3];
                finalBits += newLine[i + 4];
                break;
            }
        }

        cout << "final bits: " << finalBits << endl;

        // convert binary to decimal
        bitset<64> bits(finalBits);
        cout << "final bits decimal: " << bits.to_ulong() << endl;
    }
    return;
}
 
int main(){

    fstream inFile("testInput.txt");

    string line;
    getline(inFile, line);

    // convert hex input to binary
    line = hexToBin(line);
    int versionTotal = 0;
    parsePacket(line, versionTotal);
    cout << "versionTotal: " << versionTotal << endl;


    // string packetVersion, packetTypeID;
    // // get packet version
    // packetVersion += line[0];
    // packetVersion += line[1];
    // packetVersion += line[2];

    // // get packet type ID
    // packetTypeID += line[3];
    // packetTypeID += line[4];
    // packetTypeID += line[5];

    // cout << packetVersion << " " << packetTypeID << endl;

    // bitset<8> bitsTypeID(packetTypeID);
    // if(bitsTypeID.to_ulong() != 4){
    //     char lengthTypeID = line[6];
    //     if(lengthTypeID == '0'){ // next 15 bits will be total length of bits in sub-packets
    //         string lengthOfBits;
    //         for(int i = 0; i < 15; i++){
    //             lengthOfBits += line[i + 7];
    //         }
    //         bitset<64> bitsLengthOfBits(lengthOfBits);
    //         cout << "length of bits: " << bitsLengthOfBits.to_ulong() << endl;

    //         vector<string> subPackets;
    //         string tempSubPacket;
    //         for(int i = 23; i < line.size(); i++){

    //         }

    //     }else{ // next 11 bits will be total number of sub-packets

    //     }
    // }else{
    //     // IF PACKET REPRESENTS A LITERAL VALUE
    //     string newLine = " ";
    //     for(int i = 6; i < line.size(); i++){
    //         newLine += line[i];
    //     }

    //     cout << newLine << endl;

    //     // converting the binary recieved from input to actual binary
    //     string finalBits;
    //     for(int i = 1; i < newLine.size(); i+=5){
    //         if(newLine[i] == '1'){  
    //             finalBits += newLine[i + 1];
    //             finalBits += newLine[i + 2];
    //             finalBits += newLine[i + 3];
    //             finalBits += newLine[i + 4];
    //         }else if(newLine[i] == '0'){
    //             finalBits += newLine[i + 1];
    //             finalBits += newLine[i + 2];
    //             finalBits += newLine[i + 3];
    //             finalBits += newLine[i + 4];
    //             break;
    //         }
    //     }

    //     cout << finalBits << endl;

    //     // convert binary to decimal
    //     bitset<64> bits(finalBits);
    //     cout << bits.to_ulong() << endl;
    // }

    return 0;
}