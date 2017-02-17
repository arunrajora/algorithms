
// Articulation point and bridges

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

#define N 100005
vector<int> graph[N];

vector<int> d_num,d_low,parent;
int timeCounter,rootChildCount,droot;

vector<bool> artiVertex;

void apbDfs(int u){
	d_low[u]=d_num[u]=(++timeCounter);
	for(int j=0;j<graph[u].size();j++){
		int v=graph[u][j];
		if(!d_num[v]){
			parent[v]=u;
			rootChildCount+=(u==droot);
			apbDfs(v);
			if(d_low[v]>=d_num[u]){
				artiVertex[u]=true;
			}
			if(d_low[v]>d_num[u]){
				//ARTICULATION BRIDGE u -> v
			}
			d_low[u]=min(d_low[u],d_num[v]);
		}
		else if(v!=parent[u]){
			 d_low[u]=min(d_low[u],d_num[v]);	
		}
	}
}

void apb(int n){
	timeCounter=0;
	artiVertex.assign(n,0);
	d_low.assign(n,0);
	d_num.assign(n,0);
	parent.assign(n,-1);
	for(int i=0;i<n;i++){
		if(!d_num[i]){
			droot=i;
			rootChildCount=0;
			apbDfs(i);
			artiVertex[i]=rootChildCount>1;
		}
	}
}

int main(){
	graph[1].push_back(2);
	graph[1].push_back(4);
	graph[2].push_back(3);
	graph[5].push_back(6);
	
	apb(7);
	for(int i=0;i<7;i++){
		cout<<i<<" is ? "<<artiVertex[i]<<endl;
	}
}
