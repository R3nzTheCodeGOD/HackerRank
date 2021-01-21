#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	long long N;
	cin>>N;
	long long *rating = new long long[N], *candies = new long long[N];
	for(long long i = 0; i < N; i++) {
		cin>>rating[i];
		candies[i] = 1;
	}
	for(long long i = 1; i < N; i++) {
		if(rating[i] > rating[i-1]) {
			candies[i] += candies[i-1];
		}
	}
	for(long long i = N-2; i >= 0; i--) {
		if(rating[i] > rating[i+1] && candies[i] < candies[i+1]+1) {
			candies[i] = candies[i+1]+1;
		}
	}
	long long result = 0;
	for(long long i = 0; i < N; i++) {
		result += candies[i];
	}
	cout<<result;
    return 0;
}