//
// Created by Jesse on 11/30/2015.
//

#include <iostream>
#include <map>
#include <math.h>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;


map<string, char> tempMap;
string output = "";

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

map <string, char> headerKey(string& pString){
    // map<string, char> tempMap;
    //keeps track of position in string
    int position = 0;
    //iterates through the string
    for(std::string::iterator it = pString.begin(); it != pString.end(); it++) {
        if(position == 0){
            tempMap["0"] = *it;
        }
        else
        if(position == 1){
            tempMap["00"] = *it;
        }
        else
        if(position == 2){
            tempMap["01"] = *it;
        }
        else
        if(position == 3){
            tempMap["10"] = *it;
        }
        else
        if(position == 4){
            tempMap["000"] = *it;
        }
        else
        if(position == 5){
            tempMap["001"] = *it;
        }
        else
        if(position == 6){
            tempMap["011"] = *it;
        }
        else
        if(position == 7){
            tempMap["100"] = *it;
        }
        else
        if(position == 8){
            tempMap["101"] = *it;
        }
        else
        if(position == 9){
            tempMap["110"] = *it;
        }
        position++;
    }
    return tempMap;
}

bool checkForOne (string& threeString, int groupSize) {
    int i = 0;
    while(threeString.at(i) == '1' ) {
        if(i == groupSize)
            return true;
        i++;
    }
    return false;
}

string returnMessage(string& pString, int groupSize) {
    string chunk = pString.substr(0, groupSize - 1);
    if (groupSize == 0) {
        return output;
    }
    else if(checkForOne(chunk, groupSize)) {
        int groupSize = returnBinary(pString.substr(0, 2));
        string newString = pString.substr(2);
        return returnMessage(newString, groupSize);
    }
    else {
        char decoded = tempMap[chunk];
        output += decoded;
        string temp = pString.substr(groupSize - 1);
        return returnMessage(temp, groupSize);
    }
}

int main() {
    string c;
    string header;
    string mainData;
    cin >> header;
    cout << header << endl;
    while (cin >> c){
        mainData += c;
        cout << mainData;
    }
    headerKey(header);
    cout << to_string(tempMap.at("0")) << endl;
    int groupSize = returnBinary(mainData.substr(0,2));
    cout << groupSize << endl;
    mainData = mainData.substr(2);
    cout << mainData << endl;
    returnMessage(mainData, groupSize);
}
