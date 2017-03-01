
// Heap sort

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int left(int x){ return 2*x+1; }

int right(int x){ return 2*x+2; }

int heap_size;

void max_heapify(vector<int>& arr,int i){
	int l=left(i);
	int r=right(i);
	int largest=i;
	if(l<heap_size && arr[l]>arr[i]){
		largest=l;
	}
	if(r<heap_size && arr[r]>arr[largest]){
		largest=r;
	}
	if(largest!=i){
		swap(arr[i],arr[largest]);
		max_heapify(arr,largest);
	}
}

void build(vector<int>& arr){
	heap_size=arr.size();
	for(int i=arr.size()/2-1;i>=0;i--){
		max_heapify(arr,i);
	}
}

void hsort(vector<int>& arr){
	build(arr);
	for(int i=arr.size()-1;i>0;i--){
		swap(arr[0],arr[i]);
		heap_size--;
		max_heapify(arr,0);
	}
}

int main(){
	
	vector<int> arr;
	arr.push_back(5);
	arr.push_back(4);
	arr.push_back(3);
	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(2);
	arr.push_back(2);
	arr.push_back(2);
	hsort(arr);
	for(int x:arr){
		cout<<x<<" ";
	}
	return 0;
}
