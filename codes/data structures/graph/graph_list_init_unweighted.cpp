
// Graph starting code
// Adjacency List

#include<iostream>
#include<vector>
using namespace std;

vector<int> graph[1000005];

void clear(int N=100000){
	for(int i=0;i<N;i++){
		graph[i].clear();
	}
}

void add_directed(int x,int y){
	graph[x].push_back(y);
}

void add_undirected(int x,int y){
	graph[x].push_back(y);
	graph[y].push_back(x);
}

int main(){
	
}
