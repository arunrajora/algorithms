
// Type of edge in graph

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define N 100005
enum edgeType{ unvisited , exploring , visited };

vector<int> graph[N];
vector<edgeType> vis;
vector<int> parent;

void dfs_check(int u){
	vis[u]=exploring;
	for(int j=0;j<graph[u].size();j++){
		int v=graph[u][j];
		if(vis[v]==unvisited){
			//TREE EDGE u->v
			parent[v]=u;
			dfs_check(v);
		}
		else if(vis[v]==exploring){
			if(v==parent[u]){
				//BACK EDGE
			}
			else{
				//CYCLE EDGE
			}
		}
		else if(vis[v]==visited){
			//FORWARD/CROSS EDGE
		}
	}
	vis[u]=visited;
}

void edge_type(int n){
	vis.assign(n,unvisited);
	parent.assign(n,-1);
	int num_comp=0;
	for(int i=0;i<n;i++){
		num_comp++;
		dfs_check(i);
	}
}

int main(){
	graph[1].push_back(2);
	graph[1].push_back(4);
	graph[2].push_back(3);
	graph[5].push_back(6);
	
	edge_type(7);
	for(int i=0;i<7;i++){
		cout<<"parent of "<<i<<" is- "<<parent[i]<<endl;
	}
}
