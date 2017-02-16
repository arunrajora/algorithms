
// check a graph if it is bipartite
//directed graph

#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;

#define N 100005
vector<int> graph[N];

vector<int> colorArr;
queue<int> q;
bool isBipartite(int src,int nodes){
	colorArr.assign(nodes,-1);
	colorArr[src]=1;
	while(!q.empty()) q.pop();
	q.push(src);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=0;i<graph[u].size();i++){
			int v=graph[u][i];
			if(colorArr[v]==colorArr[u]){
				return false;
			}
			if(colorArr[v]==-1){
				colorArr[v]=1-colorArr[u];
				q.push(v);
			}
		}
	}
	return true;
}

int main(){
	graph[1].push_back(2);
	graph[1].push_back(4);
	graph[2].push_back(3);
	graph[5].push_back(6);
	graph[2].push_back(4);
	cout<<(isBipartite(1,6)?"True":"False")<<endl;
}
