
// Graph starting code
// Adjacency Matrix

#include<iostream>
#include<vector>
using namespace std;

int graph[1005][1005];

void clear(int N=1005){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			graph[i][j]=0;
		}
	}
}

void add_directed(int x,int y){
	graph[x][y]=1;
}

void add_undirected(int x,int y){
	graph[x][y]=1;
	graph[y][x]=1;
}

int main(){
	
}
