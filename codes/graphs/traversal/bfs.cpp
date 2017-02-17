
// Breadth First Search

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define N 100005
vector<int> graph[N];
vector<bool> vis;

vector<int> depth;
queue<int> q;

void bfs(int s,int G_size){
	depth.assign(G_size,0);
	vis.assign(G_size,0);
	while(!q.empty()) q.pop();
	q.push(s);
	depth[s]=1;
	vis[s]=true;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int j=0;j<graph[u].size();j++){
			int v=graph[u][j];
			if(!vis[v]){
				vis[v]=true;
				depth[v]=depth[u]+1;
				q.push(v);
			}
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
	
	bfs(1,7);
	for(int i=0;i<7;i++){
		cout<<i<<" at depth "<<depth[i]<<endl;
	}
}
