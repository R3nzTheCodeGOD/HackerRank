#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int T, N;
	cin>>T;
	while(T > 0) {
		cin>>N;
		long long *price = new long long[N], *maxRight = new long long[N-1];
		for(int i = 0; i < N; i++) {
			cin>>price[i];
		}
		if(N == 1) {
			cout<<"0\n";
			continue;
		}
		maxRight[N-2] = price[N-1];
		for(int i = N-3; i >= 0; i--) {
			if(price[i+1] > maxRight[i+1]) {
				maxRight[i] = price[i+1];
			} else {
				maxRight[i] = maxRight[i+1];
			}
		}
		long long profit = 0;
		for(int i = 0; i < N-1; i++) {
			if(maxRight[i] > price[i]) {
				profit += (maxRight[i] - price[i]);
			}
		}
		cout<<profit<<"\n";
		T--;
	}
    return 0;
}