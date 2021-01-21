#include <cmath>
#include <cstdio>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

map<string, int>::iterator it;

int main() {
    int T;
    cin>>T;
    while(T--) {
        if(T < 0) {
            break;
        }
        string s;
        cin>>s;
        map<string, int> string_map;
        for(int i = 0; i < s.length(); i++) {
            for(int j = 1; j <= s.length()-i; j++) {
                char letter = 'a';
                string substring, sorted_substring;
                substring = s.substr(i, j);
                for(int k = 0; k < 27; k++) {
                    for(int l = 0; l < substring.length(); l++) {
                        if(substring[l] == letter) {
                            sorted_substring += letter;
                        }
                    }
                    letter++;
                }
                if(string_map.count(sorted_substring) == 0) {
                    string_map[sorted_substring] = 0;
                } else {
                    string_map[sorted_substring] += 1;
                }
            }
        }
        int count = 0;
        for (it = string_map.begin(); it != string_map.end(); it++)
        {
            int value = it->second;
            if(value > 0) {
                count += (value*(value+1)/2);
            }
        }
        cout<<count<<"\n";
    }
    return 0;
}