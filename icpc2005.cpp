//
// Created by Jesse on 11/30/2015.
//

#include <iostream>
#include <sstream>
#include <map>
#include <math.h>
#include <algorithm>

using namespace std;

string returnMessage(string& pString, int groupSize);
int returnBinary(string pString);
void headerKey(string& pString);
bool checkForOne (string& threeString, int groupSize);

map <string, string> tempMap;
string output = "";

string readData(istream& data) {
    string header;
    string mainData;
    string tempData;
    int x = 0;

    while (getline(data, tempData) && tempData != "") {
        if(x == 0){
            header = tempData;
            x++;
        }
        else {
            mainData += tempData;
//            cout << mainData << endl;
        }
    }

//    cout << mainData << endl;
    headerKey(header);
    int groupSize = returnBinary(mainData.substr(0,3));
    mainData = mainData.substr(3);
//    cout << "starting Recursion" << endl;
    return returnMessage(mainData, groupSize);
}

int returnBinary(string pString){
    if(pString == "000"){
        return 0;
    }
    int exponent = pString.size() - 1;
    int total = 0;
    for(std::string::iterator it = pString.begin(); it != pString.end(); ++it) {
        if(*it == '1'){
            total += pow(2.0, exponent);
        }
        exponent--;
    }
    return total;
}

void headerKey(string& pString){
    //keeps track of position in string
    int count = 0;
    vector <string> binaryToChar = {"0", "00", "01", "10", "000", "001", "010", "011", "100", "101", "110"};
    //iterates through the string
    for(std::string::iterator itr = pString.begin(); itr != pString.end(); ++itr) {
        tempMap[binaryToChar.at(count)] = *itr;
        count++;
    }
}

bool checkForOne (string& threeString, int groupSize) {
    int i = 1;
    while(i <= threeString.size() && threeString.at(i - 1) == '1' ) {
        if(i == groupSize)
            return true;
        i++;
    }
    return false;
}

string returnMessage(string& pString, int groupSize) {
    string chunk = pString.substr(0, groupSize);
    if (groupSize == 0) {
        return output;
    }
    else if(checkForOne(chunk, groupSize)) {
        pString = pString.substr(groupSize, pString.size());
        int groupSize = returnBinary(pString.substr(0, 3));
        string newString = pString.substr(3);
        return returnMessage(newString, groupSize);
    }
    else {
        string decoded = tempMap[chunk];
        output += decoded;
        string temp = pString.substr(groupSize, pString.size());
        return returnMessage(temp, groupSize);
    }
}

int main() {
#ifdef ONLINE_JUDGE
    string testData = "$#**/\n"
            "01\n"
            "00000\n"
            "1011011\n"
            "000111\n"
            "00101000\n";
    istringstream data (testData);
#else
    istream& data = cin;
#endif
    cout << readData(data) << "\n" << endl;
}

//$#**/\r
//01\r
//00000\r
//1011011\r
//000111\r
//00101000\r

//$#**/
//01
//00000
//1011011
//000111
//00101000

//$#**/
//01
//00000
//1011011
//000111
//$#**/
//01
//00000
//1011011
//000111

//**&^$
//000101010
//001010111010
//01010101011