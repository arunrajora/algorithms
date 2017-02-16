
// Strongly connected components

#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

#define N 100005
vector<int> graph[N];
vector<bool> vis;
vector<int> d_num,d_low;
stack<int> st;
int timeCounter;

vector<vector<int>> ccomponents;

//d_num==d_low is the root
void scc_dfs(int u){
	vis[u]=true;
	d_low[u]=d_num[u]=(++timeCounter);
	st.push(u);
	for(int j=0;j<graph[u].size();j++){
		int v=graph[u][j];
		if(!d_num[v]){
			scc_dfs(v);
		}
		if(vis[v]){
			d_low[u]=min(d_low[u],d_low[v]);
		}
	}
	if(d_low[u]==d_num[u]){
		ccomponents.push_back(vector<int>());
		while(1){
			int v=st.top();
			st.pop();
			vis[v]=0;
			ccomponents[ccomponents.size()-1].push_back(v);
			if(u==v){
				break;
			}
		}
	}
	
}

void apb(int n){
	timeCounter=0;
	vis.assign(n,0);
	d_low.assign(n,0);
	d_num.assign(n,0);
	for(int i=0;i<n;i++){
		if(!d_num[i]){
			scc_dfs(i);
		}
	}
}

int main(){
	graph[1].push_back(2);
	graph[2].push_back(1);
	graph[1].push_back(4);
	graph[4].push_back(2);
	graph[2].push_back(3);
	graph[5].push_back(6);
	graph[6].push_back(5);
	
	apb(7);
	for(int i=0;i<ccomponents.size();i++){
		cout<<"Component "<<i<<endl;
		for(int j=0;j<ccomponents[i].size();j++){
			cout<<"\t"<<ccomponents[i][j]<<" "<<(d_num[ccomponents[i][j]]==d_low[ccomponents[i][j]])<<endl;
		}
	}
}
