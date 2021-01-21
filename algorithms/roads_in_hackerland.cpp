#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

string addBitStrings( string first, string second );
 
int makeEqualLength(string &str1, string &str2)
{
    int len1 = str1.size();
    int len2 = str2.size();
    if (len1 < len2)
    {
        for (int i = 0 ; i < len2 - len1 ; i++)
            str1 = '0' + str1;
        return len2;
    }
    else if (len1 > len2)
    {
        for (int i = 0 ; i < len1 - len2 ; i++)
            str2 = '0' + str2;
    }
    return len1;
}

string addBitStrings( string first, string second )
{
    string result;  

    int length = makeEqualLength(first, second);
 
    int carry = 0;  
 
    for (int i = length-1 ; i >= 0 ; i--)
    {
        int firstBit = first.at(i) - '0';
        int secondBit = second.at(i) - '0';
 
        int sum = (firstBit ^ secondBit ^ carry)+'0';
 
        result = (char)sum + result;
 
        carry = (firstBit & secondBit) | (secondBit & carry) | (firstBit & carry);
    }
 
    if (carry)
        result = '1' + result;
 
    return result;
}

int main() {
	int V, E; 
	cin>>V>>E;
	int **matrix = new int*[V];
	for(int i = 0; i < V; i++) {
		matrix[i] = new int[V];
		for(int j = 0; j < V; j++) {
			matrix[i][j] = -1;
		}
	}
	pair<int,int> *edges = new pair<int,int>[E];
	for(int i = 0; i < E; i++) {
		int v1, v2, w;
		cin>>v1>>v2>>w;
		matrix[v1-1][v2-1] = w;
		matrix[v2-1][v1-1] = w;
		edges[w] = pair<int,int>(v1-1,v2-1);
	}
	string answer = "0";
	for(int i = 0; i < V; i++) {
		set<int> sortedEdges;
		int *visited = new int[V];
		for(int i = 0; i < V; i++) {
			visited[i] = false;
		}
		visited[i] = true;
		for(int j = 0; j < V; j++) {
			if(matrix[i][j] != -1) {
				sortedEdges.insert(matrix[i][j]);
			}
		}
		bool visitedAllVertices = true;
		for(int i = 0; i < V; i++) {
			if(!visited[i]) {
				visitedAllVertices = false;
				break;
			}
		}
		string *dist = new string[E];
		for(int i = 0; i < E; i++) {
			dist[i] = string(E, '0');
		}
		while(!visitedAllVertices) {
			auto it = sortedEdges.begin();
			int v1 = edges[*it].first;
			int v2 = edges[*it].second;
			bool edgeRemoved = false;
			if(!visited[v2]) {
				for(int j = 0; j < dist[v1].size(); j++) {
					if(dist[v1][j] == '1') {
						dist[v2][j] = '1';
					}
				}
				dist[v2][E-*it-1] = '1';
				if(v2 > i) {
					answer = addBitStrings(answer, dist[v2]);
				}
				visited[v2] = true;
				sortedEdges.erase(it); 
				edgeRemoved = true;
				for(int j = 0; j < V; j++) {
					if(matrix[v2][j] != -1) {
						sortedEdges.insert(matrix[v2][j]);
					}
				}
			} else if(!visited[v1]) {
				for(int j = 0; j < dist[v2].size(); j++) {
					if(dist[v2][j] == '1') {
						dist[v1][j] = '1';
					}
				} 
				dist[v1][E-*it-1] = '1';
				if(v1 > i) {
					answer = addBitStrings(answer, dist[v1]);
				}
				visited[v1] = true;
				sortedEdges.erase(it); 
				edgeRemoved = true;
				for(int j = 0; j < V; j++) {
					if(matrix[v1][j] != -1) {
						sortedEdges.insert(matrix[v1][j]);
					}
				}
			}
			if(!edgeRemoved) {
				sortedEdges.erase(it);
			}
			visitedAllVertices = true;
			for(int i = 0; i < V; i++) {
				if(!visited[i]) {
					visitedAllVertices = false;
					break;
				}
			}
		}
	}
	cout<<answer;
    return 0;
}