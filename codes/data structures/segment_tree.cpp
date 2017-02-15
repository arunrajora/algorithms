// Segment tree with lazy propogation (max in range query)

#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

#define inf 0x7fffffff

int N;
int arr[1000005];
int st[1000005];
int lazy[1000005];

void calc_node(int node){
	st[node] = max(st[node*2], st[node*2+1]);	
}

void calc_single_node_with_lazy(int node,int l,int r,int value){
	st[node] += value;
	if(l != r) {
		lazy[node*2] += value;
		lazy[node*2+1] += value;
	}
}
int calc_node_from_left_right(int lval,int rval){
	return max(lval, rval);
}

void lazyUpdate(int node, int l, int r){
	if(lazy[node] != 0) {
		st[node] += lazy[node];
		if(l != r) {
			lazy[node*2] += lazy[node];
    		lazy[node*2+1] += lazy[node];
		}
   		lazy[node] = 0;
  	}
}

void build(int node, int l, int r) {
  	if(l == r) {
    	st[node] = arr[l];
	}
	else if(l<r){
		build(node*2, l, (l+r)/2);
		build(node*2+1, (l+r)/2+1, r);
		calc_node(node);
	}
}

void update(int node, int l, int r, int i, int j, int value) {
  
  	lazyUpdate(node,l,r);
	if(l > r || l > j || r < i)
		return;
  	if(l >= i && r <= j) {
    	 calc_single_node_with_lazy(node,l,r,value);
	}
	else{
		update(node*2, l, (l+r)/2, i, j, value);
		update(node*2+1, (l+r)/2+1, r, i, j, value);
		calc_node(node);
	}

}

int query(int node, int l, int r, int i, int j) {
	
	if(l > r || l > j || r < i) {
		return -inf;
	}
	lazyUpdate(node,l,r);
	if(l >= i && r <= j)
		return st[node];
	int lval = query(node*2, l, (l+r)/2, i, j);
	int rval = query(node*2+1, (l+r)/2+1, r, i, j);
	return calc_node_from_left_right(lval,rval);
}

int main() {
	N=20;
	for(int i = 0; i < N; i++) {
		arr[i] = i*i;
	}
	build(1, 0, N-1);
	memset(lazy, 0, sizeof lazy);
	update(1, 0, N-1, 0, 6, 5);
	update(1, 0, N-1, 7, 10, 12);
	update(1, 0, N-1, 10, N-1, 100);
	cout << query(1, 0, N-1, 0, N-1) << endl;
}
