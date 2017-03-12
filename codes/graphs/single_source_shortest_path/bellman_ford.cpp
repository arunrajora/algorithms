
// single sorurce shortest path(sssp) bellman ford

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

#define N 100005
#define inf 100000000
//item->weight,node
vector<pair<int,int> > graph[N];
vector<int> dist;

void sssp(int s,int n){
	 dist.assign(n,inf);
	 dist[s]=0;
	 for(int i=0;i<n-1;i++){
	 	for(int u=0;u<n;u++){
	 		for(int j=0;j<graph[u].size();j++){
	 			int v=graph[u][j].second;
	 			int d=graph[u][j].first;
	 			dist[v]=min(dist[v],dist[u]+d);
			 }
		 }
	 }
}

int main(){
	graph[0].push_back(make_pair(10,1));
	graph[1].push_back(make_pair(10,0));
	graph[1].push_back(make_pair(10,2));
	graph[1].push_back(make_pair(10,4));
	graph[2].push_back(make_pair(10,1));
	graph[2].push_back(make_pair(10,3));
	graph[3].push_back(make_pair(10,2));
	graph[4].push_back(make_pair(10,1));
	graph[5].push_back(make_pair(10,6));
	graph[6].push_back(make_pair(10,5));
	sssp(0,7);
	for(int i=0;i<7;i++){
		cout<<i<<" "<<dist[i]<<endl;
	}
}
