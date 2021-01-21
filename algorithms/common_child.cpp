#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string s1, s2;
    cin>>s1;
    cin>>s2;
    static int array[5000][5000];
    for(int i = 0; i < s1.length(); i++) {
       for(int j = 0; j < s2.length(); j++) {
           array[i][j] = 0;
       }
    }
    for(int i = 0; i < s1.length(); i++) {
        for(int j = 0; j < s2.length(); j++) {
            if(s1[i] == s2[j]) {
                if(i > 0 && j > 0) {
                    array[i][j] = array[i-1][j-1] + 1;
                } else {
                    array[i][j] = 1;
                }
            } else if(i == 0 && j > 0) {
                array[i][j] = array[i][j-1];
            } else if(i > 0 && j == 0) {
                array[i][j] = array[i-1][j];
            } else if(i > 0 && j > 0) {
                if(array[i][j-1] > array[i-1][j]) {
                    array[i][j] = array[i][j-1];
                } else {
                    array[i][j] = array[i-1][j];
                }
            }
        }
    }
    cout<<array[s1.length()-1][s2.length()-1];
    return 0;
}