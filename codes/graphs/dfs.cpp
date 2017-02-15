
// Depth First Search

#include<iostream>
#include<vector>
using namespace std;

#define N 100005
vector<int> graph[N];
bool vis[N];

void rdfs(int u){
	cout<<" at "<<u<<endl;
	
	vis[u]=true;
	for(int j=0;j<graph[u].size();j++){
		int v=graph[u][j];
		if(!vis[v]){
			rdfs(v);
		}
	}
}

void dfs(int G_size){
	for(int i=0;i<G_size;i++){
		if(!vis[i]){
			rdfs(i);
		}
	}
}

int main(){
	graph[1].push_back(2);
	graph[1].push_back(4);
	graph[2].push_back(1);
	graph[2].push_back(3);
	graph[3].push_back(2);
	graph[4].push_back(1);
	graph[5].push_back(6);
	graph[6].push_back(5);
	
	dfs(7);
}
