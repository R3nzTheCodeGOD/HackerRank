#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <limits.h>
using namespace std;

map<int,int>::iterator it, it2;

int main() {
    int n, tmp;
    cin>>n;
    int *input = new int[n];
    map<int,int> answer; 
    for(int i = 0; i < n; i++) {
       cin>>input[i];
       answer.insert(pair<int,int>(input[i], 0));
    }

    sort(input, input+n);

    int smallestDifference = INT_MAX;
    for(int i = 0; i < n-1; i++) {
    	if(input[i+1]-input[i] < smallestDifference) {
    		smallestDifference = input[i+1]-input[i];
    	}
    }
    
    for(it = answer.begin(); it != answer.end(); it++) {
    	int key = it->first;
    	it2 = answer.find(key+smallestDifference);
    	if(it2 != answer.end()) {
    		it->second++;
    		it2->second++;
    	}
    }

    for(it = answer.begin(); it != answer.end(); it++) {
		for(int i = 0; i < it->second; i++) {
			cout<<it->first<<" ";
		}
	}
    return 0;
}