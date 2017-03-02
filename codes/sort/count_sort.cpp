
// Count sort

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define INF 1000000000

void csort(vector<int> & arr){
	if(arr.size()==0){
		return ;
	}
	int mmax=-INF;
	int mmin=INF;
	for(auto x:arr){
		mmin=min(mmin,x);
		mmax=max(mmax,x);
	}
	vector<int> carr;
	carr.assign(mmax-mmin+1,0);
	for(auto x:arr){
		carr[x-mmin]++;
	}
	for(int i=1;i<mmax-mmin+1;i++){
		carr[i]+=carr[i-1];
	}
	vector<int> result;
	result.assign(arr.size(),0);
	for(int i=arr.size()-1;i>=0;i--){
		result[carr[arr[i]-mmin]-1]=arr[i];
		carr[arr[i]-mmin]--;
	}
	arr=result;
}

int main(){
	
	vector<int> arr;
	arr.push_back(4);
	arr.push_back(3);
	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(-100);
	csort(arr);
	for(int x:arr){
		cout<<x<<" ";
	}
	return 0;
}
