
// Edmonds Karp
// maximum flow in a graph
// 0(V^3E) implementation

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

#define N 1005
#define INF 100000000

int graph[N][N];
int res[N][N];
vector<int> parent;
cleargraph(int r,int c,int val){for(int i=0;i<r;i++) for(int j=0;j<c;j++) graph[i][j]=val;}

void augment( int v,int s,int minEdge,int& f){
	if(v==s){
		f=minEdge;
	}
	else if(parent[v]!=-1){
		augment(parent[v],s,min(minEdge,res[parent[v]][v]),f);
		res[parent[v]][v]-=f;
		res[v][parent[v]]+=f;
	}
}

int max_flow(int s,int t,int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			res[i][j]=graph[i][j];
		}
	}
	int mf=0;
	while(true){
		int f=0;
		vector<int> dist(n,INF);
		dist[s]=0;
		queue<int> q;
		q.push(s);
		parent.assign(n,-1);
		while(!q.empty()){
			int u=q.front();
			q.pop();
			if(u==t) break;
			for(int v=0;v<n;v++){
				if(res[u][v]>0 && dist[v]==INF){
					dist[v]=dist[u]+1;
					q.push(v);
					parent[v]=u;
				}
			}
		}
		augment(t,s,INF,f);
		if(f==0) break;
		mf+=f;
	}
	return mf;
}

int main(){
	
	cleargraph(7,7,0);
	graph[0][1]=100;
	graph[0][5]=1;
	graph[1][2]=20;
	graph[1][4]=10;
	graph[2][4]=20;
	graph[2][3]=10;
	graph[5][6]=10;
	graph[6][4]=1;

	cout<<max_flow(0,4,7)<<endl;
}
