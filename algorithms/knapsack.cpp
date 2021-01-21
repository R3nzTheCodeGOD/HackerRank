#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int main() {
	int T, n, k;
	cin>>T;
	while(T > 0) {
		cin>>n>>k;
		int *a = new int[n]; 
		bool *buildable = new bool[k+1]; 
		for(int i = 0; i < n; i++) {
			cin>>a[i];
		}
		memset(buildable, 0, sizeof(buildable));
		buildable[0] = 1; 
		bool corner_case = 0;
		for(int i = 0; i < n; i++) {
			if(k%a[i] == 0 || a[i] == 1) {
				cout<<k<<"\n";
				corner_case = 1;
				break;
			}
		}
		if(corner_case) {
			T--;
			continue;
		}
		for(int i = 0; i < n; i++) {
			for(int j = 0; j + a[i] <= k; j++) {
				if(buildable[j]) {
					buildable[j + a[i]] = 1;
				}
			}
			if(buildable[k]) {
				break;
			}
		}
		bool builtInt = false;
		for(int i = k; i >= 0; i--) {
			if(buildable[i]) {
				cout<<i<<"\n";
				builtInt = true;
				break;
			}
		}
		if(!builtInt) {
			cout<<"0\n";
		}
		T--;
	}
    return 0;
}