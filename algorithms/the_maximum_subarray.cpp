#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;


int main() {
	int T, N, max1, max2;
	cin>>T;
	while(T > 0) {
		cin>>N;
		int *A = new int[N];
		for(int i = 0; i < N; i++) {
			cin>>A[i];
		}
		max1 = INT_MIN; 
		max2 = INT_MIN; 
		bool foundPositive = false;
		for(int i = 0; i < N; i++) {
			if(max2 > 0) {
				foundPositive = true;
			}
			if(max2 > 0 && A[i] > 0) {
				max2 += A[i];
			} else if(max2 < 0 && A[i] > max2) {
				max2 = A[i];
			}
		}
		if(foundPositive) {		
			for(int i = 1; i < N; i++) {
				if(A[i-1] + A[i] > 0) {
					A[i] = A[i-1] + A[i];
				} else {
					A[i] = 0;
				}
			}
		} else {
			max1 = max2;
		}
		for(int i = 0; i < N; i++) {
			if(A[i] > max1) {
				max1 = A[i];
			}
		}
		cout<<max1<<" "<<max2<<"\n";
		T--;
	}
    return 0;
}