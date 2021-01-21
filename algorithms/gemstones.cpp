#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {

    int N;
    string line;
    cin>>N;
    string stringArray[N];
    int counter = 0;

    for(int i = 0; i < N; i++) {
        string line;
        cin>>line;
        char alphabetChar = 'a';
        for(int i = 0; i < 26; i++) {  
            for(char& lineChar : line) {
                if(lineChar == alphabetChar) {
                    stringArray[counter].push_back(alphabetChar);
                    break;
                }
            }
            alphabetChar++;
        }
        counter++;
    } 

    int smallestStringLength = stringArray[0].length();
    int indexOfSmallestString = 0;

    for(int i = 1; i < N; i++) {
        if(stringArray[i].size() < smallestStringLength) {
            smallestStringLength = stringArray[i].length();
            indexOfSmallestString = i;
        }
    }
    int commonGems = 0;
    for(int i = 0; i < smallestStringLength; i++) {
        for(int j = 0; j < N; j++) { 
            bool found = false;
            for(char& lineChar : stringArray[j]) {
                if(lineChar == stringArray[indexOfSmallestString][i]) {
                    found = true;
                    break;
                }
            }
            if(found) {
                if(j == (N-1)) {
                    commonGems++;
                }
                continue;
            } else {
                break;
            }
        }
    }

    cout<<commonGems;
    return 0;
}