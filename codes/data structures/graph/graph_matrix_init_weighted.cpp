
// Graph starting code
// Adjacency Matrix weighted

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

void add_directed(int x,int y,int wt){
	graph[x][y]=wt;
}

void add_undirected(int x,int y,int wt){
	graph[x][y]=wt;
	graph[y][x]=wt;
}

int main(){
	
}
