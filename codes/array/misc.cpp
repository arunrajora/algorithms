
// Misc programs for array manipulation

#include<iostream>
#include<cstring>
using namespace std;

void clearArray(int arr[],int N){
	memset(arr,0,N*sizeof(typeof(arr[0])));
}

int main(){
	int arr[]={-1,-2,-3,-4,-1,-2,-3};
	int N=7;
	
	clearArray(arr,N);
	for(int i=0;i<N;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	
	return 0;
}
