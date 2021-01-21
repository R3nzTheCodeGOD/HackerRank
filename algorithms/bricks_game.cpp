#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T > 0) {
		int N;
		cin>>N;
		long long *bricks = new long long[N];
		long long *sum = new long long[N];
		for(int i = 0; i < N; i++) {
			cin>>bricks[N-i-1];
		}
		sum[0] = bricks[0];
		for(int i = 1; i < N; i++) {
			sum[i] = sum[i-1] + bricks[i];
		}
		if(N < 4) {
			cout<<sum[N-1]<<"\n";
			T--;
		} else {
			long long *dp = new long long[N];
			dp[0] = sum[0];
			dp[1] = sum[1];
			dp[2] = sum[2];
			for(int i = 3; i < N; i++) {
				dp[i] = sum[i] - dp[i-3];
				dp[i] = max(dp[i], sum[i] - dp[i-2]); 
				dp[i] = max(dp[i], sum[i] - dp[i-1]);
			}
			cout<<dp[N-1]<<"\n";
			T--;
		}
	}
	return 0;
}