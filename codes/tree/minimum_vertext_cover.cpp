
// minimum vertex cover of a tree

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

#define N 100005
//item->weight,node
vector<int> tree[N];
int dp[N][2];
int tree_root;
int mvc_rec(int v,int flag,int parent){
	int ans=0;
	cout<<"at "<<v<<" "<<flag<<endl;
	if(dp[v][flag]!=-1){
		return dp[v][flag];
	}
	else if((tree_root!=v && tree[v].size()==1) || (tree_root==v && tree[v].size()==0)){
		ans=flag;
	}
	else if(!flag){
		for(int j=0;j<tree[v].size();j++){
			if(tree[v][j]==parent) continue;
			ans+=mvc_rec(tree[v][j],1,v);
		}
	}
	else{
		ans=1;
		for(int j=0;j<tree[v].size();j++){
			if(tree[v][j]==parent) continue;
			ans+=min(mvc_rec(tree[v][j],1,v),mvc_rec(tree[v][j],0,v));
		}
	}
	return dp[v][flag]=ans;
}

int mvc(int s,int n){
	for(int i=0;i<n;i++){
		dp[i][0]=dp[i][1]=-1;
	}
	tree_root=s;
	return min(mvc_rec(s,0,-1),mvc_rec(s,1,-1));
}

int main(){
	tree[0].push_back(1);
	tree[1].push_back(0);
	tree[1].push_back(2);
	tree[1].push_back(4);
	tree[2].push_back(1);
	tree[2].push_back(3);
	tree[3].push_back(2);
	tree[4].push_back(1);
	cout<<mvc(0,5);
}
