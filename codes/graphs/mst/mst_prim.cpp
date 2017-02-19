
// minimum spanning tree (mst) prim

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

#define N 100005
//item->weight,node
vector<pair<int,int> > graph[N];

int mst(int n){
	vector<int> taken;
	priority_queue<pair<int,int> > pq;
	taken.assign(n,0);
	pq.push(make_pair(0,0));
	int mst_cost=0;
	while(!pq.empty()){
		pair<int,int> front=pq.top();
		pq.pop();
		int u=-front.second,w=-front.first;
		if(!taken[u]){
			mst_cost+=w;
			taken[u]=1;
			for(int j=0;j<graph[u].size();j++){
				if(!taken[graph[u][j].second]) {
					pq.push(make_pair(-graph[u][j].first,-graph[u][j].second));
				}
			}
		}
	}
	return mst_cost;
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
	cout<<mst(7);
}
