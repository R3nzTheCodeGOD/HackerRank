#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int visit(int ***A, int i, int j, int n, int m, int size) {
    (*A)[i][j] = -1;
    size++;
    if(i-1 >= 0 && j-1 >= 0 && (*A)[i-1][j-1] == 1) {
    	size += visit(A, i-1, j-1, n, m, 0);
    }
    if(i-1 >= 0 && (*A)[i-1][j] == 1) {
        size += visit(A, i-1, j, n, m, 0);
    }
    if(i-1 >= 0 && j+1 < m && (*A)[i-1][j+1] == 1) {
        size += visit(A, i-1, j+1, n, m, 0);
    }
    if(j-1 >= 0 && (*A)[i][j-1] == 1) {
        size += visit(A, i, j-1, n, m, 0);
    }
    if(j+1 < m && (*A)[i][j+1] == 1) {
        size += visit(A, i, j+1, n, m, 0);
    }
    if(i+1 < n && j-1 >= 0 && (*A)[i+1][j-1] == 1) {
        size += visit(A, i+1, j-1, n, m, 0);
    }
    if(i+1 < n && (*A)[i+1][j] == 1) {
        size += visit(A, i+1, j, n, m, 0);
    }
    if(i+1 < n && j+1 < m && (*A)[i+1][j+1] == 1) {
        size += visit(A, i+1, j+1, n, m, 0);
    }
    return size;
}

int main() {
	int n, m;
	cin>>n>>m;
	int **matrix = new int*[n];
	for(int i = 0; i < n; i++) {
		matrix[i] = new int[m];
		for(int j = 0; j < m; j++) {
			cin>>matrix[i][j];
		}
	}
	int maxSize = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(matrix[i][j] == 1) {
				int size = visit(&matrix, i, j, n, m, 0);
				if(size > maxSize) {
					maxSize = size;
				}
			}
		}
	}
	cout<<maxSize;
    return 0;
}