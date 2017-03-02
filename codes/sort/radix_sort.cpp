
// Radix sort
//negative numbers not handled

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define INF 1000000000

void csort(vector<int> & arr,int base,int extractor){
	vector<int> carr;
	carr.assign(base,0);
	for(auto x:arr){
		carr[(x/extractor)%base]++;
	}
	for(int i=1;i<base;i++){
		carr[i]+=carr[i-1];
	}
	vector<int> result;
	result.assign(arr.size(),0);
	for(int i=arr.size()-1;i>=0;i--){
		result[carr[(arr[i]/extractor)%base]-1]=arr[i];
		carr[(arr[i]/extractor)%base]--;
	}
	arr=result;
}

void rsort(vector<int>& arr,int base){
	int mmax=-INF;
	for(auto x:arr){
		mmax=max(mmax,x);
	}
	for(int i=1;i<=mmax;i*=base){
		csort(arr,base,i);
	}
}

int main(){
	
	vector<int> arr;
	arr.push_back(4);
	arr.push_back(3);
	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(100);
	rsort(arr,10);
	for(int x:arr){
		cout<<x<<" ";
	}
	return 0;
}
