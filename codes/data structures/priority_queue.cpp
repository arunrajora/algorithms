
// Priority Queue

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define INF 100000000

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

void increase_key(vector<int>& arr,int i,int key){
	if(key<arr[i]){
		cout<<"key is smaller than current key."<<endl;
	}
	arr[i]=key;
	while(i>0 && arr[i/2]<arr[i]){
		swap(arr[i],arr[i/2]);
		i/=2;
	}
}

void insert_val(vector<int>& arr,int key){
	heap_size++;
	arr[heap_size-1]=-INF;
	increase_key(arr,heap_size-1,key);
}

int extract_max(vector<int>& arr){
	if(heap_size<1){
		cout<<" heap underflow"<<endl;
	}
	int mmax=arr[0];
	arr[0]=arr[heap_size-1];
	heap_size--;
	max_heapify(arr,0);
	return mmax;
}

int heap_max(vector<int>& arr){
	return arr[0];
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
	build(arr);
	for(int x:arr){
		cout<<x<<" ";
	}
	cout<<endl;
	insert_val(arr,100);
	cout<<extract_max(arr)<<endl;
	cout<<extract_max(arr)<<endl;
	cout<<extract_max(arr)<<endl;
	return 0;
}
