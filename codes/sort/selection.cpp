
// Selection sort

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void ssort(vector<int> & arr){
	for(int i=0;i<arr.size()-1;i++){
		int spos=i;
		for(int j=i+1;j<arr.size();j++){
			if(arr[spos]>arr[j]){
				spos=j;
			}
		}
		if(spos!=i){
			swap(arr[i],arr[spos]);
		}
	}
}

int main(){
	
	vector<int> arr;
	arr.push_back(5);
	arr.push_back(4);
	arr.push_back(3);
	arr.push_back(1);
	arr.push_back(2);
	ssort(arr);
	for(int x:arr){
		cout<<x<<" ";
	}
	return 0;
}
