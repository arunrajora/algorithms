
// sparse table (range minimum query or least common ancestor)
// build - 0(NlgN) , query 0(1)

#include<iostream>
#include<vector>
using namespace std;

#define LN 1000

vector<int> table;
vector<int> dp[LN];

void build(int arr[],int n){	
	table.resize(n+1);
	for(int i=2;i<=n;i++){
		table[i]=table[i>>1]+1;
	}
	for(int i=0;i<n;i++){
		dp[i].resize(table[n]+1);
		dp[i][0]=i;
	}
	for(int k=1;(1<<k)<n;k++){
		for(int i=0;i+(1<<k)<=n;i++){
			int x=dp[i][k-1];
			int y=dp[i+(1<<(k-1))][k-1];
			dp[i][k]=arr[x]<=arr[y]?x:y;
		}
	}
}

//returns minimum element
int query(int arr[],int l,int r){
	int k=table[r-l+1];
	int x=dp[l][k];
	int y=dp[r-(1<<k)+1][k];
	return arr[x]<=arr[y]?arr[x]:arr[y];
}

int main(){
	int arr[]={-20000,10,-100,50,30};
	build(arr,5);
	cout<<query(arr,0,4)<<endl;
}
