
// Merge sort

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int merge_array(vector<int>& arr,int l,int mid,int r){
	vector<int> larr;
	vector<int> rarr;
	for(int i=l;i<=r;i++){
		if(i<=mid){
			larr.push_back(arr[i]);
		}
		else{
			rarr.push_back(arr[i]);
		}
	}
	int n=0,m=0,i=l;
	while(n<larr.size() && m<rarr.size()){
		if(larr[n]<rarr[m]){
			arr[i]=larr[n];
			i++;
			n++;
		}
		else{
			arr[i]=rarr[m];
			i++;
			m++;
		}
	}
	while(n<larr.size()){
		arr[i]=larr[n];
		i++;
		n++;
	}
	while(m<rarr.size()){
		arr[i]=rarr[m];
		i++;
		m++;
	}
}

void msort_rec(vector<int>& arr,int l,int r){
	if(l<r){
		int mid=(l+r)/2;
		msort_rec(arr,l,mid);
		msort_rec(arr,mid+1,r);
		merge_array(arr,l,mid,r);
	}
}

void msort(vector<int>& arr){
	msort_rec(arr,0,arr.size()-1);
}

int main(){
	
	vector<int> arr;
	arr.push_back(5);
	arr.push_back(4);
	arr.push_back(3);
	arr.push_back(1);
	arr.push_back(2);
	msort(arr);
	for(int x:arr){
		cout<<x<<" ";
	}
	return 0;
}
