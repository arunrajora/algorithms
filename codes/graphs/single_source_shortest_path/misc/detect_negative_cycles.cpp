
// detect negative cycles

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

void bellman_ford(int s,int n){
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

//return true for negative cycle
bool isNegCycle(int n){
	bellman_ford(0,n);
	bool negCycle=false;
	for(int u=0;u<n;u++){
		for(int v=0;v<graph[u].size();v++){
			if(dist[graph[u][v].second]>dist[u]+graph[u][v].first){
				negCycle=true;
				break;
			}
		}
		if(negCycle) break;
	}
	return negCycle;
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
	cout<<(isNegCycle(7)?"Negative Cycles":"No negative cycles");
}
