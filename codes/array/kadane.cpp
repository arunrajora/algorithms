
// Dynamic programming ( largest sum contiguous subarray / maximum subarray problem )
// Kadane's algorithm

#include<iostream>
using namespace std;

void kadane(int arr[],int N){
	int max_end=0;
	int dp[N];
	for(int i=0;i<N;i++){
		max_end+=arr[i];
		if(max_end<0) max_end=0;
		dp[i]=max_end;
//		cout<<dp[i]<<" ";
	}
//	cout<<endl;
}

void kadane_empty_set_not_allowed(int arr[],int N){
	int max_end=0;
	int dp[N];
	for(int i=0;i<N;i++){
		max_end+=arr[i];
		dp[i]=max_end;
		if(max_end<0) max_end=0;
//		cout<<dp[i]<<" ";
	}
//	cout<<endl;
}

int main(){
	int arr[]={-1,-2,-3,-4,-1,-2,-3};
	int N=7;
	kadane(arr,N);
	kadane_empty_set_not_allowed(arr,N);
}
