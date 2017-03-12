
// ith smallest number in an array.
// 1st smallest no. is smallest no., 2nd smallest no. is second-smallest no. and so on.

#include<iostream>
#include<vector>
#include<algorithm>
#include<random>
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

int rpartition(vector<int>& arr,int l,int r){
	int i=rand()%(r-l+1)+l;
	swap(arr[r],arr[i]);
	return partition(arr,l,r);
}

int qsort_rec(vector<int>& arr,int l,int r,int i){
	if(l==r){
		return arr[l];
	}
	if(l<r){
		int q=rpartition(arr,l,r);
		int k=q-l+1;
		if(i==k){
			return arr[q];
		}
		else if(i<k){
			return qsort_rec(arr,l,q-1,i);
		}
		else{
			return qsort_rec(arr,q+1,r,i-k);
		}
	}
}

int qsort(vector<int>& arr,int i){
	qsort_rec(arr,0,arr.size()-1,i);
}

int main(){
	vector<int> arr;
	arr.push_back(50);
	arr.push_back(40);
	arr.push_back(30);
	arr.push_back(10);
	arr.push_back(20);
	cout<<qsort(arr,1)<<endl;
	cout<<qsort(arr,2)<<endl;
	cout<<qsort(arr,3)<<endl;
	cout<<qsort(arr,4)<<endl;
	cout<<qsort(arr,5)<<endl;
	return 0;
}
