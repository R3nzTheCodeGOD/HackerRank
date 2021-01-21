#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

int numOps(int n) {
	int result = 0;
	result += n/5;
	n %= 5;
	result += n/2;
	n %= 2;
	result += n;
	return result;
}

int main() {
	int T, N;
	cin>>T;
	while(T > 0) {
		cin>>N;
		int input, smallestNum = INT_MAX;
		vector<int> vec;
		for(int i = 0; i < N; i++) {
			cin>>input;
			vec.push_back(input);
			if(input < smallestNum) {
				smallestNum = input;
			}
		}
		int answer = INT_MAX;
		for(int i = 0; i < 4; i++) {
			int tmpAnswer = 0;
			for(int j = 0; j < N; j++) {
				int minOps = INT_MAX;
				tmpAnswer += numOps(vec[j]-smallestNum+i);
			}
			if(tmpAnswer < answer) {
				answer = tmpAnswer;
			}
		}
		cout<<answer<<"\n";
		T--;
	}
    return 0;
}