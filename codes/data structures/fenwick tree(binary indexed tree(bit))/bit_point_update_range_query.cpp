
// Fenwick Tree / Binary Indexed Tree
// Point update Range Query
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

int query(int b){
	int sum=0;
	while(b>0){
		sum+=ft[b];
		b-=b&(-b);
	}
	return sum;
}

int query(int a,int b){
	return query(b)-query(a-1);
}

int main(){
	init_ft(4);
	cout<<query(1,4)<<endl;
	update(1,4);
	update(2,4);
	update(3,4);
	cout<<query(1,4)<<endl;
	
	return 0;
}
