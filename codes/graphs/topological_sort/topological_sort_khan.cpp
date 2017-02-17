
// Topological sort ( Tarjan )
//topological sort with cycle detection

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

#define N 100005
vector<int> graph[N];
vector<bool> vis;

vector<int> ts,inedges;
queue<int> qu;

void calc_inedges(int n){
	inedges.assign(n,0);
	for(int i=0;i<n;i++){
		for(int j=0;j<graph[i].size();j++){
			inedges[graph[i][j]]++;
		}
	}
}

//True for cycles
bool tsort(int n){
	calc_inedges(n);
	ts.clear();
	while(!qu.empty())	qu.empty();
	
	vis.assign(n,0);
	for(int i=0;i<n;i++){
		if(!inedges[i]){
			vis[i]=true;
			qu.push(i);
		}
	}
	while(!qu.empty()){
		int u=qu.front();
		qu.pop();
		ts.push_back(u);
		for(int j=0;j<graph[u].size();j++){
			int v=graph[u][j];
			inedges[v]--;
			if(!inedges[v] && !vis[v]){
				vis[v]=true;
				qu.push(v);
			}
		}
	}
	return ts.size()!=n;
}

int main(){
	graph[1].push_back(2);
	graph[1].push_back(4);
	graph[2].push_back(3);
	graph[5].push_back(6);
	
	cout<<"Cycles: "<<(tsort(7)?"True":"False")<<endl;
	for(int i=0;i<7;i++){
		cout<<"at step "<<i<<" visit "<<ts[i]<<endl;
	}
}
