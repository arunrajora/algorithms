
// Topological sort ( Tarjan )

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

#define N 100005
vector<int> graph[N];
vector<bool> vis;

vector<int> ts;

void dfs_ts(int u){
	
	 vis[u]=true;
	 for(int j=0;j<graph[u].size();j++){
	 	int v=graph[u][j];
	 	if(!vis[v]){
	 		dfs_ts(v);
		 }
	 }
	 ts.push_back(u);
}

void tsort(int n){
	ts.clear();
	vis.assign(n,0);
	for(int i=0;i<n;i++){
		if(!vis[i]){
			dfs_ts(i);
		}
	}
	reverse(ts.begin(),ts.end());
}

int main(){
	graph[1].push_back(2);
	graph[1].push_back(4);
	graph[2].push_back(3);
	graph[5].push_back(6);
	
	tsort(7);
	for(int i=0;i<7;i++){
		cout<<"at step "<<i<<" visit "<<ts[i]<<endl;
	}
}
