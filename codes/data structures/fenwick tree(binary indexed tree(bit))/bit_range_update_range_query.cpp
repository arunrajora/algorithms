
// Fenwick Tree / Binary Indexed Tree
// Range update Range Query
// use size of array N+1

#include<iostream>
#include<vector>
using namespace std;

vector<int> ft1;
vector<int> ft2;
int n;

void init_ft(int N){ 
	ft1.assign(N+1,0);
 	ft2.assign(N+1,0);
	n=N+1; 
}

void update(vector<int>& ft,int p,int v){
	 while(p<=n){
	 	ft[p]+=v;
	 	p+=p&(-p);
	 }	
}

void update(int a,int b,int v){
	update(ft1,a,v);
	update(ft1,b+1,-v);
	update(ft2,a,v*(a-1));
	update(ft2,b+1,-v*b);
}

int query(vector<int> ft,int b){
	int sum=0;
	while(b>0){
		sum+=ft[b];
		b-=b&(-b);
	}
	return sum;
}

int query(int b){ return query(ft1,b)*b-query(ft2,b); }

int query(int a,int b){ return query(b)-query(a-1); }

int main(){
	init_ft(4);
	cout<<query(1,4)<<endl;
	update(1,4,4);
	cout<<query(1,4)<<" "<<query(4,4)<<endl;
	
	return 0;
}
