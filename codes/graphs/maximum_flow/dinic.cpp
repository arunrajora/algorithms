
// dinic
// maximum flow in a graph
// 0(V^2E) implementation

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

#define N 1005
#define INF 0x3f3f3f3f

struct edge{
	int source;
	int destination;
	int rev_pos;
	int capacity;
	int flow;
};
vector<edge> graph[N];
vector<int> ptr;
vector<int> dist;

void add_edge(int s,int d,int c){
	graph[s].push_back((edge){s,d,graph[d].size(),c,0});
	graph[d].push_back((edge){d,s,graph[s].size()-1,0,0});
}

int dbfs(int s,int t,int n){
	dist.assign(n,-1);
	dist[s]=0;
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=0;i<graph[u].size();i++){
			edge& e=graph[u][i];
			if(dist[e.destination]<0 && e.flow<e.capacity){
				dist[e.destination]=dist[u]+1;
				q.push(e.destination);
			}
		}
	}
	return dist[t]>=0;
}

int ddfs(int u,int t,int flow){
	if(u==t){
		return flow;
	}
	while(ptr[u]<graph[u].size()){
		edge &e=graph[u][ptr[u]];
		if(dist[e.destination]==dist[u]+1 && e.flow<e.capacity){
			int tflow=ddfs(e.destination,t,e.capacity-e.flow);
			if(tflow>0){
				e.flow+=tflow;
				graph[e.destination][e.rev_pos].flow-=tflow;
				return tflow;
			}
		}
		ptr[u]++;
	}
	return 0;
}

int max_flow(int s,int t,int n){
	int max_flow=0;
	while(dbfs(s,t,n)){
		ptr.assign(n,0);
		int tflow;
		do{
			tflow=ddfs(s,t,INF);
			max_flow+=tflow;
		}while(tflow!=0);
	}
	return max_flow;
}

int main(){
	add_edge(0,1,100);
	add_edge(0,5,1);
	add_edge(1,2,20);
	add_edge(1,4,10);
	add_edge(2,4,20);
	add_edge(2,3,10);
	add_edge(5,6,10);
	add_edge(6,4,1);
	cout<<max_flow(0,4,7)<<endl;
}
