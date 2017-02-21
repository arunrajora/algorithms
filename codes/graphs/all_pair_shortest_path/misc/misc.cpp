
//detect cycle in a graph
//detect negative cycle in a graph
//find cheapest cycle in a graph

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

#define N 1005
#define inf 100000000

int graph[N][N];
int wt[N][N];
int dp[N][N];

cleardp(int r,int c,int val){for(int i=0;i<r;i++) for(int j=0;j<c;j++) dp[i][j]=val;}
cleargraph(int r,int c,int val){for(int i=0;i<r;i++) for(int j=0;j<c;j++) graph[i][j]=val;}
clearwt(int r,int c,int val){for(int i=0;i<r;i++) for(int j=0;j<c;j++) wt[i][j]=val;}

void apsp(int n){
	 cleardp(n,n,inf);
	 for(int i=0;i<n;i++){
	 	for(int j=0;j<n;j++){
	 		if(graph[i][j]){
	 			dp[i][j]=wt[i][j];
			 }
			 if(i==j){
			 	//diagonal is set to infinity 
			 	dp[i][j]=inf;
			 }
		 }
	 }
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
}

bool hasCycles(int n){
	apsp(n);
	for(int i=0;i<n;i++){
		if(dp[i][i]!=inf){
			return true;
		}
	}
	return false;
}

bool hasNegativeCycles(int n){
	apsp(n);
	for(int i=0;i<n;i++){
		if(dp[i][i]<0){
			return true;
		}
	}
	return false;
}

int cheapestCycle(int n){
	apsp(n);
	int cheapest_cycle=inf;
	for(int i=0;i<n;i++){
		if(dp[i][i]>0){
			cheapest_cycle=min(cheapest_cycle,dp[i][i]);
		}
	}
	return cheapest_cycle;
}


int main(){
	cleargraph(7,7,0);
	clearwt(7,7,0);
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
	
	wt[0][1]=10;
	wt[1][0]=10;
	wt[1][2]=10;
	wt[1][4]=10;
	wt[2][1]=10;
	wt[2][3]=10;
	wt[3][2]=10;
	wt[4][1]=10;
	wt[5][6]=10;
	wt[6][5]=10;

	cout<<hasCycles(7)<<endl;
	cout<<hasNegativeCycles(7)<<endl;
	cout<<cheapestCycle(7)<<endl;
	
}
