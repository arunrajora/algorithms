
// Strongly connected components
// Kosaraju

#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

#define N 1005
vector<int> graph[N];
vector<bool> vis;
vector<vector<int>> ccomponents;

void rdfs(int u,vector<int>& val,vector<int> adj[]){
	vis[u]=true;
	for(int i=0;i<adj[u].size();i++){
		if(!vis[adj[u][i]]){
			rdfs(adj[u][i],val,adj);
		}
	}
	val.push_back(u);
}

void scc(int n){
	vector<int> nodesList;
	ccomponents.clear();
	vector<int> revGraph[n];
	vis.assign(n,false);
	for(int i=0;i<n;i++){
		if(!vis[i]){
			rdfs(i,nodesList,graph);
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<graph[i].size();j++){
			revGraph[graph[i][j]].push_back(i);
		}
	}
	reverse(nodesList.begin(),nodesList.end());
	vis.assign(n,false);
	for(int i=0;i<nodesList.size();i++){
		if(!vis[nodesList[i]]){
			vector<int> comp;
			rdfs(nodesList[i],comp,revGraph);
			ccomponents.push_back(comp);
		}
	}
}

int main(){
	graph[1].push_back(2);
	graph[2].push_back(1);
	graph[1].push_back(4);
	graph[4].push_back(2);
	graph[2].push_back(3);
	graph[5].push_back(6);
	graph[6].push_back(5);
	
	scc(7);
	for(int i=0;i<ccomponents.size();i++){
		cout<<"Component "<<i<<endl;
		for(int j=0;j<ccomponents[i].size();j++){
			cout<<"\t"<<ccomponents[i][j]<<endl;
		}
	}
}
