
//transitive closure of a graph
//detect if two nodes are directly or indirectly connected.

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

#define N 1005
#define inf 100000000

int graph[N][N];
int dp[N][N];

cleardp(int r,int c,int val){for(int i=0;i<r;i++) for(int j=0;j<c;j++) dp[i][j]=val;}
cleargraph(int r,int c,int val){for(int i=0;i<r;i++) for(int j=0;j<c;j++) graph[i][j]=val;}

void tclosure(int n){
	 cleardp(n,n,0);
	 for(int i=0;i<n;i++){
	 	for(int j=0;j<n;j++){
	 		dp[i][j]=graph[i][j] || i==j;
		 }
	 }
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				dp[i][j]|=(dp[i][k]&dp[k][j]);
			}
		}
	}
}



int main(){
	cleargraph(7,7,0);
	graph[0][1]=1;
	graph[1][0]=1;
	graph[1][2]=1;
	graph[1][4]=1;
	graph[2][1]=1;
	graph[2][3]=1;
	graph[3][2]=1;
	graph[4][1]=1;
	graph[5][6]=1;
	graph[6][5]=1;
	
	tclosure(7);
	
	for(int i=0;i<7;i++){
		for(int j=0;j<7;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
}
