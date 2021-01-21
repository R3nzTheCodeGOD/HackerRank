#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int dfs(vector<vector<int> > adjList, bool **visited, int node) {
	int numVisited = 0;
	for(int i = 0; i < adjList[node].size(); i++) {
		if(!(*visited)[adjList[node][i]]) {
			numVisited++;
			(*visited)[adjList[node][i]] = true;
			numVisited += dfs(adjList, visited, adjList[node][i]);
		}
	}
	return numVisited;
}

int cutEdges(vector<vector<int> > adjList, int answer, int N) {
	bool evenNode = false;
	int node;
	for(int i = 0; i < N; i++) {
		if(adjList[i].size() % 2 == 0) {
			evenNode = true;
			node = i;
			break;
		}
	}

	if(!evenNode) {
		return answer;
	}

	for(int i = 0; i < adjList[node].size(); i++) {
		bool *visited = new bool[N];
		for(int j = 0; j < N; j++) {
			visited[j] = false;
		}
		visited[node] = true;
		int node2 = adjList[node][i];
		int sizeOfSubtree = dfs(adjList, &visited, node2);
		if(sizeOfSubtree != 0 && sizeOfSubtree % 2 == 0) {
			vector<int>::iterator pos = find(adjList[node2].begin(), adjList[node2].end(), node);
			adjList[node2].erase(pos);
			adjList[node].erase(adjList[node].begin() + i);
			answer++;
			break;
		}
	}

	return cutEdges(adjList, answer, N);
}

int main() {
	int N, M;
	cin>>N>>M;
	vector<vector<int> > adjList;
	adjList.resize(N);
	for(int i = 0; i < M; i++) {
		int node1, node2;
		cin>>node1>>node2;
		adjList[node1-1].push_back(node2-1);
		adjList[node2-1].push_back(node1-1);
	}
	cout<<cutEdges(adjList, 0, N)<<"\n";
    return 0;
}