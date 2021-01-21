#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int *dp = new int[41];
	dp[0] = 1;
	for(int i = 1; i < 41; i++) {
		dp[i] = dp[i-1] + i/4;
	}
	bool* prime = new bool[dp[40]];
	for(long long i = 0; i < dp[40]; i++) {
	    prime[i] = true;
	}
	for(long long i = 2; i*i < dp[40]; i++) {
	    if(prime[i]) {
	        for(long long j = i*i; j < dp[40]; j+=i) {
	            prime[j] = false;
	        }
	    }
	}

	int T;
	cin>>T;
	while(T > 0) {
		int N;
		cin>>N;
		int numPrimes = 0;
		for(int i = 2; i <= dp[N]; i++) {
		    if(prime[i]) {
		    	numPrimes++;
		    }
		}
		cout<<numPrimes<<"\n";
		T--;
	}
    return 0;
}