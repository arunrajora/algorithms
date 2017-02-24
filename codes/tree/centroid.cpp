
// centroid of a tree
// subtree of centroid has size <=(N/2)

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

#define N 100005
vector<int> tree[N];

int rec_centroid(int u,int parent,int n){
	int count=1;
	bool isGoodCenter=true;
	for(int i=0;i<tree[u].size();i++){
		if(tree[u][i]==parent){
			continue;
		}
		int val=rec_centroid(tree[u][i],u,n);
		if(val>=0){
			return val;
		}
		isGoodCenter&=(-val)<=(n/2);
		count-=val;
	}
	isGoodCenter&=(n-count)<=(n/2);
	return isGoodCenter?u:-count;
}

int centroidOfTree(int n){
	return rec_centroid(0,-1,n);
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
	cout<<centroidOfTree(7);
}
