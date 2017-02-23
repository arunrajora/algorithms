
// Strongly Connected Graph

#include<iostream>
#include<vector>
using namespace std;

#define N 100005
vector<int> graph[N];
vector<int> revGraph[N];
bool vis[N];

void rdfs(int u){
	vis[u]=true;
	for(int j=0;j<graph[u].size();j++){
		int v=graph[u][j];
		if(!vis[v]){
			rdfs(v);
		}
	}
}

bool is_scg(int G_size){
	for(int i=0;i<G_size;i++){
		vis[i]=0;
	}
	rdfs(0);
	for(int i=0;i<G_size;i++){
		if(!vis[i]) return false;
	}
	for(int i=0;i<G_size;i++){
		revGraph[i].clear();
		vis[i]=0;
	}
	for(int i=0;i<G_size;i++){
		for(int j=0;j<graph[i].size();j++){
			revGraph[graph[i][j]].push_back(i);
		}
	}
	rdfs(0);
	for(int i=0;i<G_size;i++){
		if(!vis[i]) return true;
	}
	return true;
}

int main(){
	graph[0].push_back(5);
	graph[6].push_back(3);
	graph[4].push_back(0);
	graph[1].push_back(2);
	graph[1].push_back(4);
	graph[2].push_back(1);
	graph[2].push_back(3);
	graph[3].push_back(2);
	graph[4].push_back(1);
	graph[5].push_back(6);
	graph[6].push_back(5);
	
	cout<<is_scg(7);
}
