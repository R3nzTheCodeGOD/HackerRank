#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Finds the next largest lexographical permutation of a string (ex. dkhc -> hcdk)
// Explanation: http://www.nayuki.io/page/next-lexicographical-permutation-algorithm
// Note: In the future you can use std::next_permutation which already has this algorithm implemented
int main() {
    int t;
    cin>>t;
    while(t--) {
        if(t<0) {
            break;
        }
        string s;
        cin>>s;
        char pivot;
        int index_of_pivot;
        bool found = false;
        for(int i = s.length(); i > 0; i--) {
            if(s[i] > s[i-1]) {
                found = true;
                pivot = s[i-1];
                index_of_pivot = i-1;
                break;
            }
        }

        if(!found) {
            cout<<"no answer\n";
            continue;
        }

        string before_pivot, suffix;
        char swap_char; 
        before_pivot = s.substr(0, index_of_pivot);
        suffix = s.substr(index_of_pivot+1, s.length()-index_of_pivot-1);
        for(int i = suffix.length()-1; i >= 0; i--) {
            if(suffix[i] > pivot) {
                swap_char = suffix[i];
                suffix.erase(i, 1);
                suffix+=pivot;
                pivot = swap_char;
                break;
            }
        }
        char letter = 'a';
        string sorted_suffix;
        for(int i = 0; i < 27; i++) {
            for(int j = 0; j < suffix.length(); j++) {
                if(suffix[j] == letter) {
                    sorted_suffix += letter;
                }
            }
            letter++;
        }
        cout<<before_pivot<<pivot<<sorted_suffix<<"\n";
    }
    return 0;
}