
// Edmonds Karp
// maximum flow in a graph
// 0(min(VE^2),E*|f|) implementation

#include<iostream>
#include<vector>
#include<algorithm>
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

void add_edge(int s,int d,int c){
	graph[s].push_back((edge){s,d,graph[d].size(),c,0});
	graph[d].push_back((edge){d,s,graph[s].size()-1,0,0});
}

int max_flow(int s,int t,int n){
	int max_flow=0;
	vector<int> q;
	while(1){
		q.push_back(s);
		vector<edge*> pred;
		pred.assign(n,NULL);
		for(int i=0;i<q.size() && !pred[t];i++){
			int u=q[i];
			for(int j=0;j<graph[u].size();j++){
				edge* e=&graph[u][j];
				if(!pred[e->destination] && e->capacity > e->flow){
					pred[e->destination]=e;
					q.push_back(e->destination);
				}
			}
		}
		if(!pred[t]) break;
		int temp_flow=INF;
		for(int u=t;u!=s;u=pred[u]->source){
			temp_flow=min(temp_flow,pred[u]->capacity -pred[u]->flow);
		}
		for(int u=t;u!=s;u=pred[u]->source){
			pred[u]->flow+=temp_flow;
			graph[pred[u]->destination][pred[u]->rev_pos].flow-=temp_flow;
		}
		max_flow+=temp_flow;
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
