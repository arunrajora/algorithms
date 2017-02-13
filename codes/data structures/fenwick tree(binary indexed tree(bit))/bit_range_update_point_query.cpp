
// Fenwick Tree / Binary Indexed Tree
// Range update Point Query
// use size of array N+1

#include<iostream>
#include<vector>
using namespace std;

vector<int> ft;
int n;

void init_ft(int N){ ft.assign(N+1,0); n=N+1; }

void update(int p,int v){
	 while(p<=n){
	 	ft[p]+=v;
	 	p+=p&(-p);
	 }	
}

void update(int a,int b,int v){
	update(a,v);
	update(b+1,-v);
}

int query(int b){
	int sum=0;
	while(b>0){
		sum+=ft[b];
		b-=b&(-b);
	}
	return sum;
}

int main(){
	init_ft(4);
	cout<<query(1)<<endl;
	update(1,2,4);
	cout<<query(2)<<" "<<query(3)<<endl;
	
	return 0;
}
