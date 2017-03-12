
//minimum and maximum position in an array
//with minimum number of comparisons

#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

typedef pair<int,int> pii;

template<class T>
pii minAndMax(vector<T> arr){
	int minpos=0,maxpos=0;
	for(int i=0;i<arr.size()-1;i+=2){
		int tminpos=i;
		int tmaxpos=i+1;
		if(arr[i]>arr[i+1]){
			tminpos=i+1;
			tmaxpos=i;
		}
		if(arr[tminpos]<arr[minpos]){
			minpos=tminpos;
		}
		if(arr[tmaxpos]>arr[maxpos]){
			maxpos=tmaxpos;
		}
	}
	if(arr.size()&1){
		if(arr[arr.size()-1]<arr[minpos]){
			minpos=arr.size()-1;
		}
		if(arr[arr.size()-1]>arr[maxpos]){
			maxpos=arr.size()-1;
		}
	}
	return make_pair(minpos,maxpos);
}


int main(){
	vector<int> arr;
	arr.push_back(5);
	arr.push_back(4);
	arr.push_back(3);
	arr.push_back(2);
	arr.push_back(1);
	pii ans=minAndMax(arr);
	cout<<arr[ans.first]<<" "<<arr[ans.second]<<endl;
	return 0;
}
