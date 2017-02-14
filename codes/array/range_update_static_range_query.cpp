
//Range Updates and then Range/point query
//1 based indexing

#include<iostream>
#include<vector>
using namespace std;

vector<int> arr;

void init(int N){ arr.assign(N+1,0);}

void calculate(){
	int pre_val;
	for(int i=1;i<arr.size();i++){
		pre_val+=arr[i];
		arr[i]=arr[i-1]+pre_val;
	}
}

void update(int a,int b,int x){
	 arr[a]+=x;
	 arr[b+1]-=x;
}

void update(int a,int x){
	update(a,a,x);
}

int query(int a,int b){
	return arr[b]-arr[a-1];
}

int query(int a){
	return query(a,a);
}

int main(){
	
	init(5);
	update(1,4,2);
	update(1,1,2);
	calculate();
	cout<<query(1)<<endl;
	cout<<query(2)<<endl;
	cout<<query(3)<<endl;
	cout<<query(4)<<endl;
	cout<<query(4,4)<<endl;
	cout<<query(1,4)<<endl;	
	return 0;
}
