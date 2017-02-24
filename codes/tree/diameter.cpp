
// diameter of a tree

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

#define N 100005
vector<int> tree[N];

pair<int,int> dfs(int u,int p,int d){
	pair<int,int> res=make_pair(d,u);
	for(int j=0;j<tree[u].size();j++){
		if(tree[u][j]!=p){
			res=max(res,dfs(tree[u][j],u,d+1));
		}
	}
	return res;
}

int diameter(){
	return dfs(dfs(0,-1,0).second,-1,0).first;
}

int main(){
	tree[0].push_back(1);
	tree[1].push_back(0);
	tree[1].push_back(2);
	tree[1].push_back(4);
	tree[2].push_back(1);
	tree[2].push_back(3);
	tree[3].push_back(2);
	tree[3].push_back(5);
	tree[4].push_back(1);
	tree[5].push_back(3);
	tree[5].push_back(6);
	tree[6].push_back(5);
	cout<<diameter();
}
