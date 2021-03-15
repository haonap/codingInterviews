#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <sstream>
using namespace std;


/*1. parse a string
 *
 */
vector<string> Parse(string myString, char delim){
    vector<string> parsedString;

    stringstream sstream(myString);
    string temp;

    while(getline(sstream, temp, delim)) parsedString.push_back(temp);
    return parsedString;
}





/*2. pattern matching (matching string with char)
 * e.g., string1 = "bla bli bla", string2 = "a b a": True
 *       string1 = "bla bli bla", string2 = "a b c": False
*/
bool PatternMatching(string array1, string array2){

    vector<string> myVec1, myVec2;
    myVec1 = Parse(array1, ' ');
    myVec2 = Parse(array2, ' ');

    set<string> mySet1, mySet2;
    for(int i = 0; i < myVec1.size(); i++){
        mySet1.insert(myVec1[i]);
        mySet2.insert(myVec2[i]);
    }

    if(mySet1.size() != mySet2.size()) return false;

    map<string, set<string>> myMap1, myMap2;

    for(int i = 0; i < myVec1.size(); i++){
        myMap1[myVec1[i]].insert(myVec2[i]);
        myMap2[myVec2[i]].insert(myVec1[i]);
    }

    for(auto x: myMap1){
        if(x.second.size() > 1) return false;
    }

    /*
    for(auto x: myMap2){
        if(x.second.size() > 1) return false;
    }
     */

    return true;

}





int main() {

    string string1 = "bla bli bla hao";
    string string2 = "a b a a";
    cout << PatternMatching(string1, string2) << endl;

    return 0;

}
