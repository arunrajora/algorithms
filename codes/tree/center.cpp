
// center of a tree
//reterns one or two vertices

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

#define N 100005
//item->weight,node
vector<int> tree[N];

vector<int> centerOfTree(int n){
	vector<int> leaves,deg;
	for(int i=0;i<n;i++){
		deg.push_back(tree[i].size());
		if(deg[i]<=1){
			leaves.push_back(i);
		}
	}
	int deleted=leaves.size();
	while(deleted<n){
		vector<int> temp_leaves;
		for(int i=0;i<leaves.size();i++){
			int u=leaves[i];
			for(int j=0;j<tree[u].size();j++){
				int v=tree[u][j];
				deg[v]--;
				if(deg[v]==1){
					temp_leaves.push_back(v);
				}
			}
		}
		leaves=temp_leaves;
		deleted+=leaves.size();
	}
	return leaves;
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
	vector<int> center=centerOfTree(7);
	for(int i=0;i<center.size();i++){
		cout<<center[i]<<" ";
	}
}
