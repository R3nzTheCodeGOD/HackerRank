#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T > 0) {
		long long N, K;
		cin>>N>>K;

		
		if(K == 0) {
			for(long long i = 1; i <= N; i++) {
				cout<<i<<" ";
			}
			cout<<"\n";
			T--;
			continue;
		}
		if(K > N/2 || N%2 == 1) {
			cout<<"-1\n";
			T--;
			continue;
		}
		bool possible = true;
		bool *used = new bool[N+1];
		long long *answer = new long long[N];
		memset(used, false, sizeof(used));
		for(long long i = 1; i <= N/2; i++) {
			if(i+K <= N && i-K >= 1) {
				if(!used[i+K] && !used[i-K]) {
					used[i-K] = true;
					answer[i-1] = i-K;
				} else if(!used[i+K] && used[i-K]) {
					used[i+K] = true;
					answer[i-1] = i+K;
				} else if(used[i+K] && !used[i-K]) {
					used[i-K] = true;
					answer[i-1] = i-K;
				} else {
					possible = false;
					break;
				}
			} else if(i+K > N && i-K >= 1) {
				if(!used[i-K]) {
					used[i-K] = true;
					answer[i-1] = i-K;
				} else {
					possible = false;
					break;
				}
			} else if(i+K <= N && i-K <= 1) {
				if(!used[i+K]) {
					used[i+K] = true;
					answer[i-1] = i+K;
				} else {
					possible = false;
					break;
				}
			} else {
				possible = false;
				break;
			}
			long long rightIndex = N-i+1;
			if(rightIndex+K <= N && rightIndex-K >= 1) {
				if(!used[rightIndex+K] && !used[rightIndex-K]) {
					used[rightIndex+K] = true;
					answer[rightIndex-1] = rightIndex+K;
				} else if(!used[rightIndex+K] && used[rightIndex-K]) {
					used[rightIndex+K] = true;
					answer[rightIndex-1] = rightIndex+K;
				} else if(used[rightIndex+K] && !used[rightIndex-K]) {
					used[rightIndex-K] = true;
					answer[rightIndex-1] = rightIndex-K;
				} else {
					possible = false;
					break;
				}
			} else if(rightIndex+K > N && rightIndex-K >= 1) {
				if(!used[rightIndex-K]) {
					used[rightIndex-K] = true;
					answer[rightIndex-1] = rightIndex-K;
				} else {
					possible = false;
					break;
				}
			} else if(rightIndex+K <= N && rightIndex-K <= 1) {
				if(!used[rightIndex+K]) {
					used[rightIndex+K] = true;
					answer[rightIndex-1] = rightIndex+K;
				} else {
					possible = false;
					break;
				}
			} else {
				possible = false;
				break;
			}
		}
		if(!possible) {
			cout<<"-1";
		} else {
			for(int i = 0; i < N; i++) {
				cout<<answer[i]<<" ";
			}
		}
		cout<<"\n";
		T--;
	}
    return 0;
}