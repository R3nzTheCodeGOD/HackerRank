#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int m, n;
	cin>>m>>n;
	bool **land = new bool*[m];
	int **left = new int*[m], **right = new int*[m], **up = new int*[m], **down = new int*[m];
	for(int i = 0; i < m; i++) {
		land[i] = new bool[n];
		left[i] = new int[n];
		right[i] = new int[n];
		up[i] = new int[n];
		down[i] = new int[n];
		int spaces = 0;
		for(int j = 0; j < n; j++) {
			char c;
			cin>>c;
			if(c == 46) {
				land[i][j] = true;
				left[i][j] = spaces++;
			} else {
				land[i][j] = false;
				left[i][j] = -1;
				spaces = 0;
			}
		}
	}
	for(int i = 0; i < m; i++) {
		int spaces = 0;
		for(int j = n-1; j >= 0; j--) {
			if(land[i][j]) {
				right[i][j] = spaces++;
			} else {
				right[i][j] = -1;
				spaces = 0;
			}
		}
	}
	for(int i = 0; i < n; i++) {
		int spaces = 0;
		for(int j = 0; j < m; j++) {
			if(land[j][i]) {
				up[j][i] = spaces++;
			} else {
				up[j][i] = -1;
				spaces = 0;
			}
		}
	}
	for(int i = 0; i < n; i++) {
		int spaces = 0;
		for(int j = m-1; j >= 0; j--) {
			if(land[j][i]) {
				down[j][i] = spaces++;
			} else {
				down[j][i] = -1;
				spaces = 0;
			}
		}
	}

	int maxPerimeter = 0;
	for(int i = 0; i < m-1; i++) {
		for(int j = 0; j < n-1; j++) {
			if(!land[i][j]) {
				continue;
			}
			for(int x = i+down[i][j]; x >= i+1; x--) {
				for(int y = j+right[i][j]; y >= j+1; y--) {
					int side1 = y-j;
					int side2 = x-i;
					if(side1 + side2 <= maxPerimeter) {
						break;
					}
					if(land[x][y] && left[x][y] >= side1 && up[x][y] >= side2) {			
						if(side1 + side2 > maxPerimeter) {
							maxPerimeter = side1 + side2;
						}
					}
				}
			}
		}
	}
	if(maxPerimeter == 0) {
		cout<<"impossible\n";
	} else {
		cout<<maxPerimeter*2<<"\n";
	}
    return 0;
}