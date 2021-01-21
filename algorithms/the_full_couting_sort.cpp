#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int main() {
    int count[100], n, tmp;
    cin>>n;
    int *key = new int[n]; 
    memset(count, 0, sizeof(count)); 
    string s, *input = new string[n], *output = new string[n];
    
    for(int i = 0; i < n; i++) {
        cin>>tmp;
        count[tmp]++;
        cin>>s;
        if(i < n/2) {
            input[i] = '-';
        } else {
            input[i]= s;
        }
        key[i] = tmp;
    }

    int total = 0;
    for(int i = 0; i < 100; i++) {
        total += count[i];
        count[i] = total;
    }

    for(int i = n-1; i >= 0; i--) {
        output[count[key[i]]-1] = input[i];
        count[key[i]]--;
    }

    for(int i = 0; i < n; i++) {
        cout<<output[i]<<" ";
    }
    return 0;
}