
// Graph starting code
// Adjacency List weighted

#include<iostream>
#include<vector>
#include<set>
using namespace std;

vector<pair<int,int>> graph[1000005];

void clear(int N=100000){
	for(int i=0;i<N;i++){
		graph[i].clear();
	}
}

void add_directed(int x,int y,int wt){
	graph[x].push_back(make_pair(wt,y));
}

void add_undirected(int x,int y){
	graph[x].push_back(make_pair(wt,y));
	graph[y].push_back(make_pair(wt,x));
}

int main(){
	
}
