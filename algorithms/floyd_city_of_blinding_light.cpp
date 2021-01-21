#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

int main() {
    int V, E;
    cin>>V>>E;

    int **dist = new int*[V];
    for(int i = 0; i < V; i++) {
        dist[i] = new int[V];
        for(int j = 0; j < V; j++) {
            if(i != j) {
                dist[i][j] = INT_MAX;
            } else {
                dist[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < E; ++i) {
        int s, d, w;
        cin>>s>>d>>w;
        dist[s-1][d-1] = w;
    }
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            for (int k = 0; k < V; ++k) {
                if(dist[j][i] == INT_MAX || dist[i][k] == INT_MAX) {
                    continue; 
                }
                if(dist[j][k] > dist[j][i] + dist[i][k]) {
                    dist[j][k] = dist[j][i] + dist[i][k];
               }
            }
        }
    }

    int Q = 0;
    cin>>Q;
    for(int i = 0; i < Q; i++) {
        int a, b;
        cin>>a>>b;
        if(dist[a-1][b-1] == INT_MAX) {
            cout<<"-1"<<"\n";
        } else {
            cout<<dist[a-1][b-1]<<"\n";
        }
    }

    return 0;
}