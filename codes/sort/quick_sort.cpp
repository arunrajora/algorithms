
// Quick sort

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int partition(vector<int>& arr,int l,int r){
	int x=arr[r];
	int i=l-1;
	for(int j=l;j<r;j++){
		if(arr[j]<=x){
			i++;
			swap(arr[i],arr[j]);
		}
	}
	swap(arr[i+1],arr[r]);
	return i+1;
}

void qsort_rec(vector<int>& arr,int l,int r){
	if(l<r){
		int q=partition(arr,l,r);
		qsort_rec(arr,l,q-1);
		qsort_rec(arr,q,r);
	}
}

void qsort(vector<int>& arr){
	qsort_rec(arr,0,arr.size()-1);
}

int main(){
	
	vector<int> arr;
	arr.push_back(5);
	arr.push_back(4);
	arr.push_back(3);
	arr.push_back(1);
	arr.push_back(2);
	qsort(arr);
	for(int x:arr){
		cout<<x<<" ";
	}
	return 0;
}
