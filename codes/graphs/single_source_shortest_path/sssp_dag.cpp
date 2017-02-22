
// single sorurce shortest path(sssp) on a dag

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

void rdfs(int s){
	for(int i=0;i<graph[s].size();i++){
		pair<int,int> u=graph[s][i];
		dist[u.second]=min(dist[u.second],dist[s]+u.first);
		rdfs(u.second);
	}
}

void sssp(int s,int n){
	dist.assign(n,inf);
	dist[s]=0;
	rdfs(s);
}

int main(){
	graph[0].push_back(make_pair(10,1));
	graph[1].push_back(make_pair(10,2));
	graph[1].push_back(make_pair(10,4));
	graph[3].push_back(make_pair(10,2));
	graph[5].push_back(make_pair(10,6));
	sssp(0,7);
	for(int i=0;i<7;i++){
		cout<<i<<" "<<dist[i]<<endl;
	}
}
