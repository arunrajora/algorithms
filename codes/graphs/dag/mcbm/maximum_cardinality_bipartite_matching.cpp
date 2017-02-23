
// maximum cardinality bipartite matching
//o(VE) (not best)(see hopcroft karp)

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

#define N 100005
#define inf 100000000
//item->weight,node
//0..(n-1)->l (n..m-1)->r 
vector<int> graph[N];
vector<int> match,vis;

int augment(int l){
	if(vis[l]) return 0;
	vis[l]=1;
	for(int j=0;j<graph[l].size();j++){
		int r=graph[l][j];
		if(match[r]==-1 || augment(match[r])){
			match[r]=l;
			return 1;
		}
	}
	return 0;
}

int mcbm(int n,int m){
	int cardinality=0;
	match.assign(n+m,-1);
	for(int l=0;l<n;l++){
		vis.assign(n,0);
		cardinality+=augment(l);
	}
	return cardinality;
}

int main(){
	graph[0].push_back(4);
	graph[4].push_back(0);
	graph[1].push_back(4);
	graph[1].push_back(5);
	graph[4].push_back(1);
	graph[5].push_back(1);
	graph[2].push_back(4);
	graph[4].push_back(2);
	graph[3].push_back(4);
	graph[4].push_back(3);

	cout<<mcbm(4,3)<<endl;
}
