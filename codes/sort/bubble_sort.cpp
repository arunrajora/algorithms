
// Bubble sort

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void bsort(vector<int> & arr){
	for(int i=0;i<arr.size()-1;i++){
		int swaps=0;
		for(int j=0;j<arr.size()-i-1;j++){
			if(arr[j]>arr[j+1]){
				swap(arr[j],arr[j+1]);
				swaps++;
			}
		}
		if(!swaps) break;
	}
}

int main(){
	
	vector<int> arr;
	arr.push_back(5);
	arr.push_back(4);
	arr.push_back(3);
	arr.push_back(1);
	arr.push_back(2);
	bsort(arr);
	for(int x:arr){
		cout<<x<<" ";
	}
	return 0;
}
