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
    getline(data,header);
    string c;
    while (getline(data, c) &&  c != "" && c != "") {
        mainData += c;
//        if(getline(data, c) && c != ""){
//            mainData += c;
//            break;
//        }
    }
    headerKey(header);
    int groupSize = returnBinary(mainData.substr(0,3));
    mainData = mainData.substr(3);
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
    int position = 0;
    //iterates through the string
    for(std::string::iterator it = pString.begin(); it != pString.end(); ++it) {
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
//    string a = "$#**/";
//    string b = "0100000101101100011100101000";
//
//    headerKey(a);
//    cout << "output tempMat at 0" << endl;
//    cout << tempMap.at("0") << endl;
//    int groupSize = returnBinary(b.substr(0,3));
//    cout << groupSize << endl;
//    b = b.substr(3);
//    cout << b << endl;
//    cout << returnMessage(b, groupSize) << endl;


    istream& data = cin;
    cout << readData(data);
}

//$#**/
//01
//00000
//1011011
//000111
//00101000
