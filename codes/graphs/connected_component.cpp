
// Conected Components

#include<iostream>
#include<vector>
using namespace std;

#define N 100005
vector<int> graph[N];
bool vis[N];

vector<int> component;

void rdfs(int u,int c_no){
	cout<<" at "<<u<<endl;
	component[u]=c_no;
	vis[u]=true;
	for(int j=0;j<graph[u].size();j++){
		int v=graph[u][j];
		if(!vis[v]){
			rdfs(v,c_no);
		}
	}
}

int dfs(int G_size){
	component.assign(G_size,0);
	int count=0;
	for(int i=0;i<G_size;i++){
		if(!vis[i]){
			count++;
			rdfs(i,count);
		}
	}
	return count;
}

int main(){
	graph[1].push_back(2);
	graph[1].push_back(4);
	graph[2].push_back(1);
	graph[2].push_back(3);
	graph[3].push_back(2);
	graph[4].push_back(1);
	graph[5].push_back(6);
	graph[6].push_back(5);
	
	cout<<"Graph has "<<dfs(7)<<" components\n";
	for(int i=0;i<7;i++){
		cout<<component[i]<<" ";
	}
}
