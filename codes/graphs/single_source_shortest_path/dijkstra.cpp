
// single sorurce shortest path(sssp) dijkstra

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
	 priority_queue<pair<int,int>> pq;
	 pq.push(make_pair(0,s));
	 while(!pq.empty()){
	 	pair<int,int> front=pq.top();
	 	pq.pop();
	 	int d=-front.first,u=front.second;
	 	if(d>dist[u]) continue;
	 	for(int j=0;j<graph[u].size();j++){
	 		int v=graph[u][j].second;
	 		if(dist[u]+graph[u][j].first<dist[v]){
	 			dist[v]=dist[u]+graph[u][j].first;
	 			pq.push(make_pair(-dist[v],v));
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
