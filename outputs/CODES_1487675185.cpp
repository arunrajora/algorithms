// __________________________

// .\codes\array\2dkadane.cpp

// Dynamic programming ( largest sum contiguous subarray / maximum subarray problem ) in a 2D matrix
// 2D Kadane's algorithm 

#include<iostream>
#include<cstring>
using namespace std;

int mat[100][100];
int tmp_array[110]; 

int kadane(int arr[], int n) {
    int sum = INT_MIN;
    int maxsum = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (sum < 0)
            sum = arr[i];
        else
            sum += arr[i];
        maxsum = max(maxsum, sum);
    }
    return maxsum;
}

int kadane_2d(int R,int C) {
    int maxsum = INT_MIN;
    for (int left = 0; left < C; left++) {
        memset(tmp_array, 0, sizeof(tmp_array));
        for (int right = left; right < C; right++) {
            for (int i = 0; i < R; ++i) {
                tmp_array[i] += mat[i][right];
            }
            maxsum = max(maxsum, kadane(tmp_array, R));
        }
    }
    return maxsum;
}

int main(){
	
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			mat[i][j]=2;
		}
	}
	cout<<kadane_2d(2,3);
	
	return 0;
}

// __________________________



// __________________________

// .\codes\array\kadane.cpp

// Dynamic programming ( largest sum contiguous subarray / maximum subarray problem )
// Kadane's algorithm

#include<iostream>
using namespace std;

void kadane(int arr[],int N){
	int max_end=0;
	int dp[N];
	for(int i=0;i<N;i++){
		max_end+=arr[i];
		if(max_end<0) max_end=0;
		dp[i]=max_end;
//		cout<<dp[i]<<" ";
	}
//	cout<<endl;
}

void kadane_empty_set_not_allowed(int arr[],int N){
	int max_end=0;
	int dp[N];
	for(int i=0;i<N;i++){
		max_end+=arr[i];
		dp[i]=max_end;
		if(max_end<0) max_end=0;
//		cout<<dp[i]<<" ";
	}
//	cout<<endl;
}

int main(){
	int arr[]={-1,-2,-3,-4,-1,-2,-3};
	int N=7;
	kadane(arr,N);
	kadane_empty_set_not_allowed(arr,N);
}

// __________________________



// __________________________

// .\codes\array\misc.cpp

// Misc programs for array manipulation

#include<iostream>
#include<cstring>
using namespace std;

void clearArray(int arr[],int N){
	memset(arr,0,N*sizeof(typeof(arr[0])));
}

int main(){
	int arr[]={-1,-2,-3,-4,-1,-2,-3};
	int N=7;
	
	clearArray(arr,N);
	for(int i=0;i<N;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	
	return 0;
}

// __________________________



// __________________________

// .\codes\array\range_update_static_range_query.cpp

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

// __________________________



// __________________________

// .\codes\bitwise tricks\bitwise_tricks.cpp
// Bitwise Tricks

#include<iostream>
using namespace std;

//swap two numbers
void swap(int& a,int& b){ a^=b;b^=a;a^=b; }

//check if i-th bit is set (i starts from 0)
bool isBitSet(int x,int i){ return x&(1<<i); }

//sets i-th bit to 1 (i starts from 0)
int setBit(int x,int i){ return x|(1<<i); }

//unset i-th bit to 0 (i starts from 0)
int unsetBit(int x,int i){ return x&~(1<<i); }

//check if a number is odd (true) or even (false)
bool oddOrEven(int x){ return x&1; }

//toggle i-th bit (i starts from 0
int toggleBit(int x,int i){ return x^(1<<i); }

//unset rightmost 1 Bit
int unsetRightmostOne(int x){ return x&(x-1); }

//set rightmost 0 Bit
int setRightmostZero(int x){ return x|(x+1); }

//isolate/extract rightmost 1 Bit
int rightmostOne(int x){ return x&(-x); }

//isolate/extract rightmost 0 Bit
int rightmostZero(int x){ return ~x&(x+1); }

//right propogate rightmost 1 Bit 0101000->0101111
//(Does not work for 0->gives all one)
int rightPropogateOnes(int x){ return x|(x-1); }

//right propogate rightmost 0 Bit 010111->010000
int rightPropogateZeros(int x){ return x&(x+1); }

//Left rotate d bits
int leftRotate(int x,int d,int bit_count){return (x<<d)|(x>>(bit_count-d));}

//Right rotate d bits
int rightRotate(int x,int d,int bit_count){return (x>>d)|(x<<(bit_count-d));}

//check for power of 2 (true for power of 2)
//alternatively can also chech for x&&(x&-x)==x
bool isPowerOfTwo(int x){ return x && !(x&(x-1)); }

//check for two numbers having opposite sign 
//0 acts like Positive
//alternatively
bool hasOppositeSigns(int a,int b){ return (a^b)<0; }

//min of 2 numbers
int mMin(int a,int b){ return b^((a^b)&-(a<b)); }

//max of 2 numbers
int mMax(int a,int b){ return a^((a^b)&-(a<b)); }

//count of set bits (count of ones)
int countOnes(int x){
	int c=0;
	while(x) c++,x&=x-1;
	return c;
}

//n mod a power of two
// d= 1<<s
int modPowerOfTwo(int x,int d){ return x&(d-1); }

//n continuous set bits
int continuousSetBits(int x){ return (1<<x)-1; }

//trailing zero count
int trailingZeroCount(int x){ return x?__builtin_ctz(x):0; }

//get next Permutation with same number of set bits
unsigned int nextBitPermutation(unsigned int x){
	unsigned int t=x|(x-1);
	return (t+1)|(((~t&-~t)-1)>>(__builtin_ctz(x)+1));
}

//ALTERNATE VERSION- get next Permutation with same number of set bits
unsigned int nextPermutation1(unsigned int x){
	unsigned int t = (x|(x-1))+1;
	return t|((((t&-t)/(x&-x))>>1)-1);
}

int main(){
	
	int a=2,b=3;
	swap(a,b);
	cout<<a<<" "<<b<<endl;
	
	a=2;
	cout<<isBitSet(2,0)<<" "<<isBitSet(2,1)<<endl;
	
	cout<<setBit(2,0)<<endl;
	
	cout<<unsetBit(3,1)<<endl;
	
	cout<<oddOrEven(2)<<" "<<oddOrEven(3)<<endl;
	
	cout<<toggleBit(3,0)<<" "<<toggleBit(3,1)<<endl;
	
	cout<<unsetRightmostOne(6)<<" "<<setRightmostZero(2)<<endl;
	
	cout<<rightmostOne(6)<<" "<<rightmostZero(3)<<endl;
	
	cout<<rightPropogateZeros(3)<<" "<<rightPropogateOnes(6)<<endl;
	
	cout<<leftRotate(1,2,6)<<" "<<rightRotate(1,2,6)<<endl;
	
	cout<<isPowerOfTwo(0)<<" "<<isPowerOfTwo(2)<<" "<<isPowerOfTwo(3)<<endl;
	
	cout<<hasOppositeSigns(-1,1)<<" "<<hasOppositeSigns(1,1)<<" "<<hasOppositeSigns(0,2)<<" "<<hasOppositeSigns(0,-2)<<endl;
	
	cout<<mMin(2,3)<<" "<<mMin(2,2)<<endl;
	
	cout<<mMax(2,3)<<" "<<mMax(2,2)<<endl;
	
	cout<<countOnes(3)<<" "<<countOnes(0)<<" "<<countOnes(8)<<endl;
	
	cout<<modPowerOfTwo(16,8)<<endl;
	
	cout<<continuousSetBits(3)<<endl;
	
	cout<<nextBitPermutation(3)<<endl;
	
	cout<<nextPermutation1(3)<<endl;
}

// __________________________



// __________________________

// .\codes\bitwise tricks\gray_code.cpp

// Gray code to binary and binary to gray code conversion

#include<iostream>
using namespace std;

int grayToBinary(int x){
	x^=x>>16;
	x^=x>>8;
	x^=x>>4;
	x^=x>>2;
	x^=x>>1;
	return x;
}

int binaryToGray(int x){ return x^(x>>1); }

int main(){
	cout<<grayToBinary(7)<<endl;
	cout<<binaryToGray(5)<<endl;
	return 0;	
}

// __________________________



// __________________________

// .\codes\data structures\fenwick tree(binary indexed tree(bit))\2d_bit.cpp
// 2-D Fenwick Tree / Binary Indexed Tree
// Point update Range Query or Range update Point Query
// use size of array N+1

#include<iostream>
#include<vector>
using namespace std;

#define N_X 1001
#define N_Y 1001
int ft[N_X][N_Y];

void updatey(int x,int y,int v){
	while(y<=N_Y){
		ft[x][y]+=v;
		y+=y&(-y);
	}	
}

void update(int x,int y,int v){
	 while(x<=N_X){
	 	updatey(x,y,v);
	 	x+=x&(-x);
	 }	
}

int update(int r1,int c1,int r2,int c2,int v){
	update(r1,c1,v);
	update(r1,c2+1,-v);
	update(r2,c1+1,-v);
	update(r2+1,c2+1,v);
}

int query(int x,int y){
	int sum=0;
	while(x){
		int y1=y;
		while(y1){
			sum+=ft[x][y];
			y1-=y1&(-y1);
		}
		x-=x&(-x);
	}
	return sum;
}


int query(int r1,int c1,int r2,int c2){
	return query(r2,c2)-query(r2,c1-1)-query(r1-1,c2)+query(r1-1,c1-1);
}

int main(){

	update(1,1,4,4,5);
	update(2,2,2,2,3);
	cout<<query(2,2)<<endl;
	cout<<query(5,5)<<endl;

//	update(1,1,4);
//	update(2,2,4);
//	cout<<query(1,1,2,2)<<endl;
//	cout<<query(1,1,4,4)<<endl;
//	cout<<query(3,3,5,5)<<endl;
//	
	return 0;
}

// __________________________



// __________________________

// .\codes\data structures\fenwick tree(binary indexed tree(bit))\bit_point_update_range_query.cpp

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

// __________________________



// __________________________

// .\codes\data structures\fenwick tree(binary indexed tree(bit))\bit_range_update_point_query.cpp

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

// __________________________



// __________________________

// .\codes\data structures\fenwick tree(binary indexed tree(bit))\bit_range_update_range_query.cpp

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

// __________________________



// __________________________

// .\codes\data structures\graph\graph_list_init_unweighted.cpp

// Graph starting code
// Adjacency List

#include<iostream>
#include<vector>
using namespace std;

vector<int> graph[1000005];

void clear(int N=100000){
	for(int i=0;i<N;i++){
		graph[i].clear();
	}
}

void add_directed(int x,int y){
	graph[x].push_back(y);
}

void add_undirected(int x,int y){
	graph[x].push_back(y);
	graph[y].push_back(x);
}

int main(){
	
}

// __________________________



// __________________________

// .\codes\data structures\graph\graph_list_init_weighted.cpp

// Graph starting code
// Adjacency List weighted

#include<iostream>
#include<vector>
#include<set>
using namespace std;

vector<pair<int,int>> graph[1000005];

void clear(int N=100000){
	for(int i=0;i<N;i++){
		graph[i].clear();
	}
}

void add_directed(int x,int y,int wt){
	graph[x].push_back(make_pair(wt,y));
}

void add_undirected(int x,int y){
	graph[x].push_back(make_pair(wt,y));
	graph[y].push_back(make_pair(wt,x));
}

int main(){
	
}

// __________________________



// __________________________

// .\codes\data structures\graph\graph_matrix_init_unweighted.cpp

// Graph starting code
// Adjacency Matrix

#include<iostream>
#include<vector>
using namespace std;

int graph[1005][1005];

void clear(int N=1005){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			graph[i][j]=0;
		}
	}
}

void add_directed(int x,int y){
	graph[x][y]=1;
}

void add_undirected(int x,int y){
	graph[x][y]=1;
	graph[y][x]=1;
}

int main(){
	
}

// __________________________



// __________________________

// .\codes\data structures\graph\graph_matrix_init_weighted.cpp

// Graph starting code
// Adjacency Matrix weighted

#include<iostream>
#include<vector>
using namespace std;

int graph[1005][1005];

void clear(int N=1005){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			graph[i][j]=0;
		}
	}
}

void add_directed(int x,int y,int wt){
	graph[x][y]=wt;
}

void add_undirected(int x,int y,int wt){
	graph[x][y]=wt;
	graph[y][x]=wt;
}

int main(){
	
}

// __________________________



// __________________________

// .\codes\data structures\segment_tree.cpp
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

// __________________________



// __________________________

// .\codes\data structures\set_union.cpp

// Disjoint set union

#include<iostream>
#include<vector>
using namespace std;

vector<int> p,rankArr;
int countSets;
void initialize(int N) { countSets=N;rankArr.assign(N,0);p.assign(N,0); for(int i=0;i<N;i++) p[i]=i; }

int findSet(int i){ return p[i]==i?i:(p[i]=findSet(p[i])); }

bool isSameSet(int i,int j){ return findSet(i)==findSet(j); }

void unionSet(int i,int j){
	if(!isSameSet(i,j)){
		countSets--;
		int x=findSet(i),y=findSet(j);
		if(rankArr[x]>rankArr[y]) p[y]=x;
		else{
			p[x]=y;
			if(rankArr[x]==rankArr[y]) rankArr[y]++;
		}
	}
}

int main(){
	initialize(4);
	cout<<findSet(1)<<" "<<findSet(2)<<endl;
	cout<<isSameSet(1,2)<<endl;
	unionSet(1,2);
	cout<<findSet(1)<<" "<<findSet(2)<<endl;
	cout<<isSameSet(1,2)<<endl;
	cout<<countSets<<endl;
	return 0;
}

// __________________________



// __________________________

// .\codes\date\day_from_date.cpp

//Calculate day from date

#include<iostream>
#include<string>
using namespace std;

string days[7]={"sunday","monday","tuesday","wednesday","thursday","friday","saturday"};

string dayFromDate(int d,int m,int y){
	y-=m<3;
	//0xD50E9994 => 0,3,2,5,0,3,5,1,4,6,2,4
	return days[(y+y/4-y/100+y/400+d+((((unsigned long long)0xD50E9994)>>((12-m)*3))&0x7))%7];
}

int main(){
	cout<<dayFromDate(5,2,2017);//sunday
	return 0;
}

// __________________________



// __________________________

// .\codes\graphs\all_pair_shortest_path\misc\diameter.cpp

//diameter of a graph

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

#define N 1005
#define inf 100000000

int graph[N][N];
int wt[N][N];
int dp[N][N];

cleardp(int r,int c,int val){for(int i=0;i<r;i++) for(int j=0;j<c;j++) dp[i][j]=val;}
cleargraph(int r,int c,int val){for(int i=0;i<r;i++) for(int j=0;j<c;j++) graph[i][j]=val;}
clearwt(int r,int c,int val){for(int i=0;i<r;i++) for(int j=0;j<c;j++) wt[i][j]=val;}

int diameter(int n){
	cleardp(n,n,inf);
	for(int i=0;i<n;i++){
	 	for(int j=0;j<n;j++){
	 		if(graph[i][j]){
	 			dp[i][j]=wt[i][j];
			}
			 else if(i==j){
			 	dp[i][j]=0;
			}
		}
 	}
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	int diam=0;
	for(int i=0;i<n;i++){
	 	for(int j=0;j<n;j++){
	 		if(dp[i][j]!=inf){
	 			diam=max(diam,dp[i][j]);
			}
		}
	}
	return diam;
}



int main(){
	cleargraph(7,7,0);
	clearwt(7,7,0);
	graph[0][1]=1;
	graph[1][0]=1;
	graph[1][2]=1;
	graph[1][4]=1;
	graph[2][1]=1;
	graph[2][3]=1;
	graph[3][2]=1;
	graph[4][1]=1;
	graph[5][6]=1;
	graph[6][5]=1;
	
	wt[0][1]=10;
	wt[1][0]=10;
	wt[1][2]=10;
	wt[1][4]=10;
	wt[2][1]=10;
	wt[2][3]=10;
	wt[3][2]=10;
	wt[4][1]=10;
	wt[5][6]=10;
	wt[6][5]=10;

	cout<<diameter(7);

}

// __________________________



// __________________________

// .\codes\graphs\all_pair_shortest_path\misc\minimax.cpp

//minimax
//minimum maximum weight from all paths from i to j

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

#define N 1005
#define inf 100000000

int graph[N][N];
int wt[N][N];
int dp[N][N];

cleardp(int r,int c,int val){for(int i=0;i<r;i++) for(int j=0;j<c;j++) dp[i][j]=val;}
cleargraph(int r,int c,int val){for(int i=0;i<r;i++) for(int j=0;j<c;j++) graph[i][j]=val;}
clearwt(int r,int c,int val){for(int i=0;i<r;i++) for(int j=0;j<c;j++) wt[i][j]=val;}

void apsp(int n){
	 cleardp(n,n,inf);
	 for(int i=0;i<n;i++){
	 	for(int j=0;j<n;j++){
	 		if(graph[i][j]){
	 			dp[i][j]=wt[i][j];
			 }
			 else if(i==j){
			 	dp[i][j]=0;
			 }
		 }
	 }
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				dp[i][j]=min(dp[i][j],max(dp[i][k],dp[k][j]));
			}
		}
	}
}



int main(){
	cleargraph(7,7,0);
	clearwt(7,7,0);
	graph[0][1]=1;
	graph[1][0]=1;
	graph[1][2]=1;
	graph[1][4]=1;
	graph[2][1]=1;
	graph[2][3]=1;
	graph[3][2]=1;
	graph[4][1]=1;
	graph[5][6]=1;
	graph[6][5]=1;
	
	wt[0][1]=10;
	wt[1][0]=10;
	wt[1][2]=10;
	wt[1][4]=10;
	wt[2][1]=10;
	wt[2][3]=10;
	wt[3][2]=10;
	wt[4][1]=10;
	wt[5][6]=10;
	wt[6][5]=10;

	apsp(7);
	for(int i=0;i<7;i++){
		for(int j=0;j<7;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
}

// __________________________



// __________________________

// .\codes\graphs\all_pair_shortest_path\misc\misc.cpp

//detect cycle in a graph
//detect negative cycle in a graph
//find cheapest cycle in a graph

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

#define N 1005
#define inf 100000000

int graph[N][N];
int wt[N][N];
int dp[N][N];

cleardp(int r,int c,int val){for(int i=0;i<r;i++) for(int j=0;j<c;j++) dp[i][j]=val;}
cleargraph(int r,int c,int val){for(int i=0;i<r;i++) for(int j=0;j<c;j++) graph[i][j]=val;}
clearwt(int r,int c,int val){for(int i=0;i<r;i++) for(int j=0;j<c;j++) wt[i][j]=val;}

void apsp(int n){
	 cleardp(n,n,inf);
	 for(int i=0;i<n;i++){
	 	for(int j=0;j<n;j++){
	 		if(graph[i][j]){
	 			dp[i][j]=wt[i][j];
			 }
			 if(i==j){
			 	//diagonal is set to infinity 
			 	dp[i][j]=inf;
			 }
		 }
	 }
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
}

bool hasCycles(int n){
	apsp(n);
	for(int i=0;i<n;i++){
		if(dp[i][i]!=inf){
			return true;
		}
	}
	return false;
}

bool hasNegativeCycles(int n){
	apsp(n);
	for(int i=0;i<n;i++){
		if(dp[i][i]<0){
			return true;
		}
	}
	return false;
}

int cheapestCycle(int n){
	apsp(n);
	int cheapest_cycle=inf;
	for(int i=0;i<n;i++){
		if(dp[i][i]>0){
			cheapest_cycle=min(cheapest_cycle,dp[i][i]);
		}
	}
	return cheapest_cycle;
}


int main(){
	cleargraph(7,7,0);
	clearwt(7,7,0);
	graph[0][1]=1;
	graph[1][0]=1;
	graph[1][2]=1;
	graph[1][4]=1;
	graph[2][1]=1;
	graph[2][3]=1;
	graph[3][2]=1;
	graph[4][1]=1;
	graph[5][6]=1;
	graph[6][5]=1;
	
	wt[0][1]=10;
	wt[1][0]=10;
	wt[1][2]=10;
	wt[1][4]=10;
	wt[2][1]=10;
	wt[2][3]=10;
	wt[3][2]=10;
	wt[4][1]=10;
	wt[5][6]=10;
	wt[6][5]=10;

	cout<<hasCycles(7)<<endl;
	cout<<hasNegativeCycles(7)<<endl;
	cout<<cheapestCycle(7)<<endl;
	
}

// __________________________



// __________________________

// .\codes\graphs\all_pair_shortest_path\misc\transitive_closure.cpp

//transitive closure of a graph
//detect if two nodes are directly or indirectly connected.

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

#define N 1005
#define inf 100000000

int graph[N][N];
int dp[N][N];

cleardp(int r,int c,int val){for(int i=0;i<r;i++) for(int j=0;j<c;j++) dp[i][j]=val;}
cleargraph(int r,int c,int val){for(int i=0;i<r;i++) for(int j=0;j<c;j++) graph[i][j]=val;}

void tclosure(int n){
	 cleardp(n,n,0);
	 for(int i=0;i<n;i++){
	 	for(int j=0;j<n;j++){
	 		dp[i][j]=graph[i][j] || i==j;
		 }
	 }
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				dp[i][j]|=(dp[i][k]&dp[k][j]);
			}
		}
	}
}



int main(){
	cleargraph(7,7,0);
	graph[0][1]=1;
	graph[1][0]=1;
	graph[1][2]=1;
	graph[1][4]=1;
	graph[2][1]=1;
	graph[2][3]=1;
	graph[3][2]=1;
	graph[4][1]=1;
	graph[5][6]=1;
	graph[6][5]=1;
	
	tclosure(7);
	
	for(int i=0;i<7;i++){
		for(int j=0;j<7;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
}

// __________________________



// __________________________

// .\codes\graphs\all_pair_shortest_path\floyd_warshall.cpp

//all pair shortest path
// floyd warshall

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

#define N 1005
#define inf 100000000

int graph[N][N];
int wt[N][N];
int dp[N][N];
int parent[N][N];

cleardp(int r,int c,int val){for(int i=0;i<r;i++) for(int j=0;j<c;j++) dp[i][j]=val;}
cleargraph(int r,int c,int val){for(int i=0;i<r;i++) for(int j=0;j<c;j++) graph[i][j]=val;}
clearwt(int r,int c,int val){for(int i=0;i<r;i++) for(int j=0;j<c;j++) wt[i][j]=val;}
clearparent(int r,int c,int val){for(int i=0;i<r;i++) for(int j=0;j<c;j++) parent[i][j]=val;}

void apsp(int n){
	 cleardp(n,n,inf);
	 clearparent(n,n,-1);
	 for(int i=0;i<n;i++){
	 	for(int j=0;j<n;j++){
	 		if(graph[i][j]){
	 			dp[i][j]=wt[i][j];
	 				parent[i][j]=i;
			 }
			 else if(i==j){
			 	dp[i][j]=0;
			 	parent[i][j]=i;
			 }
		 }
	 }
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(dp[i][k]+dp[k][j]<dp[i][j]){
					dp[i][j]=dp[i][k]+dp[k][j];
					parent[i][j]=parent[k][j];
				}
			}
		}
	}
}

void path(int i,int j){
	if(i==j){
		cout<<"goto "<<i<<endl;
	}
	else if(parent[i][j]==-1){
		cout<<"No path"<<endl;
	}
	else{
		path(i,parent[i][j]);
		cout<<"goto "<<j<<endl;
	}
}

int main(){
	cleargraph(7,7,0);
	clearwt(7,7,0);
	graph[0][1]=1;
	graph[1][0]=1;
	graph[1][2]=1;
	graph[1][4]=1;
	graph[2][1]=1;
	graph[2][3]=1;
	graph[3][2]=1;
	graph[4][1]=1;
	graph[5][6]=1;
	graph[6][5]=1;
	
	wt[0][1]=10;
	wt[1][0]=10;
	wt[1][2]=10;
	wt[1][4]=10;
	wt[2][1]=10;
	wt[2][3]=10;
	wt[3][2]=10;
	wt[4][1]=10;
	wt[5][6]=10;
	wt[6][5]=10;

	apsp(7);
	for(int i=0;i<7;i++){
		for(int j=0;j<7;j++){
			cout<<dp[i][j]<<","<<parent[i][j]<<" ";
		}
		cout<<endl;
	}
	path(0,4);
}

// __________________________



// __________________________

// .\codes\graphs\misc\articulation_point_bridges.cpp

// Articulation point and bridges

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

#define N 100005
vector<int> graph[N];

vector<int> d_num,d_low,parent;
int timeCounter,rootChildCount,droot;

vector<bool> artiVertex;

void apbDfs(int u){
	d_low[u]=d_num[u]=(++timeCounter);
	for(int j=0;j<graph[u].size();j++){
		int v=graph[u][j];
		if(!d_num[v]){
			parent[v]=u;
			rootChildCount+=(u==droot);
			apbDfs(v);
			if(d_low[v]>=d_num[u]){
				artiVertex[u]=true;
			}
			if(d_low[v]>d_num[u]){
				//ARTICULATION BRIDGE u -> v
			}
			d_low[u]=min(d_low[u],d_num[v]);
		}
		else if(v!=parent[u]){
			 d_low[u]=min(d_low[u],d_num[v]);	
		}
	}
}

void apb(int n){
	timeCounter=0;
	artiVertex.assign(n,0);
	d_low.assign(n,0);
	d_num.assign(n,0);
	parent.assign(n,-1);
	for(int i=0;i<n;i++){
		if(!d_num[i]){
			droot=i;
			rootChildCount=0;
			apbDfs(i);
			artiVertex[i]=rootChildCount>1;
		}
	}
}

int main(){
	graph[1].push_back(2);
	graph[1].push_back(4);
	graph[2].push_back(3);
	graph[5].push_back(6);
	
	apb(7);
	for(int i=0;i<7;i++){
		cout<<i<<" is ? "<<artiVertex[i]<<endl;
	}
}

// __________________________



// __________________________

// .\codes\graphs\misc\bipartite_check.cpp

// check a graph if it is bipartite
//directed graph

#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;

#define N 100005
vector<int> graph[N];

vector<int> colorArr;
queue<int> q;
bool isBipartite(int src,int nodes){
	colorArr.assign(nodes,-1);
	colorArr[src]=1;
	while(!q.empty()) q.pop();
	q.push(src);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=0;i<graph[u].size();i++){
			int v=graph[u][i];
			if(colorArr[v]==colorArr[u]){
				return false;
			}
			if(colorArr[v]==-1){
				colorArr[v]=1-colorArr[u];
				q.push(v);
			}
		}
	}
	return true;
}

int main(){
	graph[1].push_back(2);
	graph[1].push_back(4);
	graph[2].push_back(3);
	graph[5].push_back(6);
	graph[2].push_back(4);
	cout<<(isBipartite(1,6)?"True":"False")<<endl;
}

// __________________________



// __________________________

// .\codes\graphs\misc\connected_component.cpp

// Conected Components

#include<iostream>
#include<vector>
using namespace std;

#define N 100005
vector<int> graph[N];
bool vis[N];

vector<int> component;

void rdfs(int u,int c_no){
	cout<<" at "<<u<<endl;
	component[u]=c_no;
	vis[u]=true;
	for(int j=0;j<graph[u].size();j++){
		int v=graph[u][j];
		if(!vis[v]){
			rdfs(v,c_no);
		}
	}
}

int dfs(int G_size){
	component.assign(G_size,0);
	int count=0;
	for(int i=0;i<G_size;i++){
		if(!vis[i]){
			count++;
			rdfs(i,count);
		}
	}
	return count;
}

int main(){
	graph[1].push_back(2);
	graph[1].push_back(4);
	graph[2].push_back(1);
	graph[2].push_back(3);
	graph[3].push_back(2);
	graph[4].push_back(1);
	graph[5].push_back(6);
	graph[6].push_back(5);
	
	cout<<"Graph has "<<dfs(7)<<" components\n";
	for(int i=0;i<7;i++){
		cout<<component[i]<<" ";
	}
}

// __________________________



// __________________________

// .\codes\graphs\misc\dag_check.cpp

// Directed Acyclic Graph Check

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define N 100005
vector<int> graph[N];
vector<bool> vis;

vector<int> ts,inedges;
queue<int> qu;

void calc_inedges(int n){
	inedges.assign(n,0);
	for(int i=0;i<n;i++){
		for(int j=0;j<graph[i].size();j++){
			inedges[graph[i][j]]++;
		}
	}
}

//True for cycles
bool has_cycles(int n){
	calc_inedges(n);
	ts.clear();
	while(!qu.empty())	qu.empty();
	
	vis.assign(n,0);
	for(int i=0;i<n;i++){
		if(!inedges[i]){
			vis[i]=true;
			qu.push(i);
		}
	}
	while(!qu.empty()){
		int u=qu.front();
		qu.pop();
		ts.push_back(u);
		for(int j=0;j<graph[u].size();j++){
			int v=graph[u][j];
			inedges[v]--;
			if(!inedges[v] && !vis[v]){
				vis[v]=true;
				qu.push(v);
			}
		}
	}
	return ts.size()!=n;
}

int main(){
	graph[1].push_back(2);
	graph[1].push_back(4);
	graph[2].push_back(3);
	graph[5].push_back(6);
	
	cout<<"DAG: "<<(!has_cycles(7)?"True":"False")<<endl;

}

// __________________________



// __________________________

// .\codes\graphs\misc\edge_type.cpp

// Type of edge in graph

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define N 100005
enum edgeType{ unvisited , exploring , visited };

vector<int> graph[N];
vector<edgeType> vis;
vector<int> parent;

void dfs_check(int u){
	vis[u]=exploring;
	for(int j=0;j<graph[u].size();j++){
		int v=graph[u][j];
		if(vis[v]==unvisited){
			//TREE EDGE u->v
			parent[v]=u;
			dfs_check(v);
		}
		else if(vis[v]==exploring){
			if(v==parent[u]){
				//BACK EDGE
			}
			else{
				//CYCLE EDGE
			}
		}
		else if(vis[v]==visited){
			//FORWARD/CROSS EDGE
		}
	}
	vis[u]=visited;
}

void edge_type(int n){
	vis.assign(n,unvisited);
	parent.assign(n,-1);
	int num_comp=0;
	for(int i=0;i<n;i++){
		num_comp++;
		dfs_check(i);
	}
}

int main(){
	graph[1].push_back(2);
	graph[1].push_back(4);
	graph[2].push_back(3);
	graph[5].push_back(6);
	
	edge_type(7);
	for(int i=0;i<7;i++){
		cout<<"parent of "<<i<<" is- "<<parent[i]<<endl;
	}
}

// __________________________



// __________________________

// .\codes\graphs\misc\flood_fill.cpp

// Flood fill on 2d Matrix
// replace a character with other character in a continuous area.
#include<iostream>
#include<vector>
using namespace std;

char grid[1001][1001]={{'+','-','-','-'},
	       {'+','+','+','-'},
		   {'+','-','+','+'},
		   {'+','+','+','-'}};
int R,C;

int dr[8]={1,1,0,-1,-1,-1,0,1};
int dc[8]={0,1,1,1,0,-1,-1,-1};

int floodfillrec(int r,int c,char c1,char c2){
	if(r<0 || r>=R || c<0 || c>=C) return 0;
	if(grid[r][c]!=c1) return 0;
	int ans=1;
	grid[r][c]=c2;
	for(int d=0;d<8;d++){
		ans+=floodfillrec(r+dr[d],c+dc[d],c1,c2);
	}
	return ans;
}

void floodfill(char c1,char c2){
	int region_count=0;
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			if(grid[i][j]==c1){
				int blocks=floodfillrec(i,j,c1,c2);
				region_count++;
				cout<<region_count<<" has "<<blocks<<" blocks."<<endl;
			}
		}
	}
}

int main(){
	R=4,C=4;
	
	floodfill('-','*');
	
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			cout<<grid[i][j];
		}cout<<endl;
	}
}

// __________________________



// __________________________

// .\codes\graphs\mst\minimum_spanning_forest.cpp

// minimum spanning forest kruskal

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<pair<int,pair<int,int> > > edges;

vector<int> p,rankArr;
int countSets;
void initialize(int N) { countSets=N;rankArr.assign(N,0);p.assign(N,0); for(int i=0;i<N;i++) p[i]=i; }

int findSet(int i){ return p[i]==i?i:(p[i]=findSet(p[i])); }

bool isSameSet(int i,int j){ return findSet(i)==findSet(j); }

void unionSet(int i,int j){
	if(!isSameSet(i,j)){
		countSets--;
		int x=findSet(i),y=findSet(j);
		if(rankArr[x]>rankArr[y]) p[y]=x;
		else{
			p[x]=y;
			if(rankArr[x]==rankArr[y]) rankArr[y]++;
		}
	}
}

int mst(int forestSize){
	initialize(edges.size());
	sort(edges.begin(),edges.end());
	int mst_cost=0;
	for(int i=0;i<edges.size() && countSets>forestSize;i++){
		pair<int,pair<int,int> > front=edges[i];
		if(!isSameSet(front.second.first,front.second.second)){
			mst_cost+=front.first;
			unionSet(front.second.first,front.second.second);
		}
	}
	return mst_cost;
}

int main(){
	edges.push_back(make_pair(4,make_pair(1,0)));
	edges.push_back(make_pair(2,make_pair(1,2)));
	edges.push_back(make_pair(6,make_pair(0,3)));
	edges.push_back(make_pair(4,make_pair(0,2)));
	edges.push_back(make_pair(6,make_pair(0,4)));
	edges.push_back(make_pair(8,make_pair(2,3)));
	edges.push_back(make_pair(9,make_pair(3,4)));
	cout<<mst(2);
}

// __________________________



// __________________________

// .\codes\graphs\mst\mst_kruskal.cpp

// minimum spanning tree (mst) kruskal

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<pair<int,pair<int,int> > > edges;

vector<int> p,rankArr;

void initialize(int N) { rankArr.assign(N,0);p.assign(N,0); for(int i=0;i<N;i++) p[i]=i; }

int findSet(int i){ return p[i]==i?i:(p[i]=findSet(p[i])); }

bool isSameSet(int i,int j){ return findSet(i)==findSet(j); }

void unionSet(int i,int j){
	if(!isSameSet(i,j)){
		int x=findSet(i),y=findSet(j);
		if(rankArr[x]>rankArr[y]) p[y]=x;
		else{
			p[x]=y;
			if(rankArr[x]==rankArr[y]) rankArr[y]++;
		}
	}
}


int mst(){
	initialize(edges.size());
	sort(edges.begin(),edges.end());
	int mst_cost=0;
	for(int i=0;i<edges.size();i++){
		pair<int,pair<int,int> > front=edges[i];
		if(!isSameSet(front.second.first,front.second.second)){
			mst_cost+=front.first;
			unionSet(front.second.first,front.second.second);
		}
	}
	return mst_cost;
}

int main(){
	edges.push_back(make_pair(4,make_pair(1,0)));
	edges.push_back(make_pair(2,make_pair(1,2)));
	edges.push_back(make_pair(6,make_pair(0,3)));
	edges.push_back(make_pair(4,make_pair(0,2)));
	edges.push_back(make_pair(6,make_pair(0,4)));
	edges.push_back(make_pair(8,make_pair(2,3)));
	edges.push_back(make_pair(9,make_pair(3,4)));
	cout<<mst();
}

// __________________________



// __________________________

// .\codes\graphs\mst\mst_prim.cpp

// minimum spanning tree (mst) prim

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

#define N 100005
//item->weight,node
vector<pair<int,int> > graph[N];

int mst(int n){
	vector<int> taken;
	priority_queue<pair<int,int> > pq;
	taken.assign(n,0);
	pq.push(make_pair(0,0));
	int mst_cost=0;
	while(!pq.empty()){
		pair<int,int> front=pq.top();
		pq.pop();
		int u=-front.second,w=-front.first;
		if(!taken[u]){
			mst_cost+=w;
			taken[u]=1;
			for(int j=0;j<graph[u].size();j++){
				if(!taken[graph[u][j].second]) {
					pq.push(make_pair(-graph[u][j].first,-graph[u][j].second));
				}
			}
		}
	}
	return mst_cost;
}

int main(){
	graph[0].push_back(make_pair(10,1));
	graph[1].push_back(make_pair(10,0));
	graph[1].push_back(make_pair(10,2));
	graph[1].push_back(make_pair(10,4));
	graph[2].push_back(make_pair(10,1));
	graph[2].push_back(make_pair(10,3));
	graph[3].push_back(make_pair(10,2));
	graph[4].push_back(make_pair(10,1));
	graph[5].push_back(make_pair(10,6));
	graph[6].push_back(make_pair(10,5));
	cout<<mst(7);
}

// __________________________



// __________________________

// .\codes\graphs\single_source_shortest_path\misc\detect_negative_cycles.cpp

// detect negative cycles

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

#define N 100005
#define inf 100000000
//item->weight,node
vector<pair<int,int> > graph[N];
vector<int> dist;

void bellman_ford(int s,int n){
	 dist.assign(n,inf);
	 dist[s]=0;
	 for(int i=0;i<n-1;i++){
	 	for(int u=0;u<n;u++){
	 		for(int j=0;j<graph[u].size();j++){
	 			int v=graph[u][j].second;
	 			int d=graph[u][j].first;
	 			dist[v]=min(dist[v],dist[u]+d);
			 }
		 }
	 }
}

//return true for negative cycle
bool isNegCycle(int n){
	bellman_ford(0,n);
	bool negCycle=false;
	for(int u=0;u<n;u++){
		for(int v=0;v<graph[u].size();v++){
			if(dist[graph[u][v].second]>dist[u]+graph[u][v].first){
				negCycle=true;
				break;
			}
		}
		if(negCycle) break;
	}
	return negCycle;
}

int main(){
	graph[0].push_back(make_pair(10,1));
	graph[1].push_back(make_pair(10,0));
	graph[1].push_back(make_pair(10,2));
	graph[1].push_back(make_pair(10,4));
	graph[2].push_back(make_pair(10,1));
	graph[2].push_back(make_pair(10,3));
	graph[3].push_back(make_pair(10,2));
	graph[4].push_back(make_pair(10,1));
	graph[5].push_back(make_pair(10,6));
	graph[6].push_back(make_pair(10,5));
	cout<<(isNegCycle(7)?"Negative Cycles":"No negative cycles");
}

// __________________________



// __________________________

// .\codes\graphs\single_source_shortest_path\bellman_ford.cpp

// single sorurce shortest path(sssp) dijkstra

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

#define N 100005
#define inf 100000000
//item->weight,node
vector<pair<int,int> > graph[N];
vector<int> dist;

void sssp(int s,int n){
	 dist.assign(n,inf);
	 dist[s]=0;
	 for(int i=0;i<n-1;i++){
	 	for(int u=0;u<n;u++){
	 		for(int j=0;j<graph[u].size();j++){
	 			int v=graph[u][j].second;
	 			int d=graph[u][j].first;
	 			dist[v]=min(dist[v],dist[u]+d);
			 }
		 }
	 }
}

int main(){
	graph[0].push_back(make_pair(10,1));
	graph[1].push_back(make_pair(10,0));
	graph[1].push_back(make_pair(10,2));
	graph[1].push_back(make_pair(10,4));
	graph[2].push_back(make_pair(10,1));
	graph[2].push_back(make_pair(10,3));
	graph[3].push_back(make_pair(10,2));
	graph[4].push_back(make_pair(10,1));
	graph[5].push_back(make_pair(10,6));
	graph[6].push_back(make_pair(10,5));
	sssp(0,7);
	for(int i=0;i<7;i++){
		cout<<i<<" "<<dist[i]<<endl;
	}
}

// __________________________



// __________________________

// .\codes\graphs\single_source_shortest_path\dijkstra.cpp

// single sorurce shortest path(sssp) dijkstra

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

#define N 100005
#define inf 100000000
//item->weight,node
vector<pair<int,int> > graph[N];
vector<int> dist;

void sssp(int s,int n){
	 dist.assign(n,inf);
	 dist[s]=0;
	 priority_queue<pair<int,int>> pq;
	 pq.push(make_pair(0,s));
	 while(!pq.empty()){
	 	pair<int,int> front=pq.top();
	 	pq.pop();
	 	int d=-front.first,u=front.second;
	 	if(d>dist[u]) continue;
	 	for(int j=0;j<graph[u].size();j++){
	 		int v=graph[u][j].second;
	 		if(dist[u]+graph[u][j].first<dist[v]){
	 			dist[v]=dist[u]+graph[u][j].first;
	 			pq.push(make_pair(-dist[v],v));
			 }
		 }
	 }
}

int main(){
	graph[0].push_back(make_pair(10,1));
	graph[1].push_back(make_pair(10,0));
	graph[1].push_back(make_pair(10,2));
	graph[1].push_back(make_pair(10,4));
	graph[2].push_back(make_pair(10,1));
	graph[2].push_back(make_pair(10,3));
	graph[3].push_back(make_pair(10,2));
	graph[4].push_back(make_pair(10,1));
	graph[5].push_back(make_pair(10,6));
	graph[6].push_back(make_pair(10,5));
	sssp(0,7);
	for(int i=0;i<7;i++){
		cout<<i<<" "<<dist[i]<<endl;
	}
}

// __________________________



// __________________________

// .\codes\graphs\strongly_connected_component\strongly_connected_components.cpp

// Strongly connected components

#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

#define N 100005
vector<int> graph[N];
vector<bool> vis;
vector<int> d_num,d_low;
stack<int> st;
int timeCounter;

vector<vector<int>> ccomponents;

//d_num==d_low is the root
void scc_dfs(int u){
	vis[u]=true;
	d_low[u]=d_num[u]=(++timeCounter);
	st.push(u);
	for(int j=0;j<graph[u].size();j++){
		int v=graph[u][j];
		if(!d_num[v]){
			scc_dfs(v);
		}
		if(vis[v]){
			d_low[u]=min(d_low[u],d_low[v]);
		}
	}
	if(d_low[u]==d_num[u]){
		ccomponents.push_back(vector<int>());
		while(1){
			int v=st.top();
			st.pop();
			vis[v]=0;
			ccomponents[ccomponents.size()-1].push_back(v);
			if(u==v){
				break;
			}
		}
	}
	
}

void apb(int n){
	timeCounter=0;
	vis.assign(n,0);
	d_low.assign(n,0);
	d_num.assign(n,0);
	for(int i=0;i<n;i++){
		if(!d_num[i]){
			scc_dfs(i);
		}
	}
}

int main(){
	graph[1].push_back(2);
	graph[2].push_back(1);
	graph[1].push_back(4);
	graph[4].push_back(2);
	graph[2].push_back(3);
	graph[5].push_back(6);
	graph[6].push_back(5);
	
	apb(7);
	for(int i=0;i<ccomponents.size();i++){
		cout<<"Component "<<i<<endl;
		for(int j=0;j<ccomponents[i].size();j++){
			cout<<"\t"<<ccomponents[i][j]<<" "<<(d_num[ccomponents[i][j]]==d_low[ccomponents[i][j]])<<endl;
		}
	}
}

// __________________________



// __________________________

// .\codes\graphs\topological_sort\topological_sort_khan.cpp

// Topological sort ( Tarjan )
//topological sort with cycle detection

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

#define N 100005
vector<int> graph[N];
vector<bool> vis;

vector<int> ts,inedges;
queue<int> qu;

void calc_inedges(int n){
	inedges.assign(n,0);
	for(int i=0;i<n;i++){
		for(int j=0;j<graph[i].size();j++){
			inedges[graph[i][j]]++;
		}
	}
}

//True for cycles
bool tsort(int n){
	calc_inedges(n);
	ts.clear();
	while(!qu.empty())	qu.empty();
	
	vis.assign(n,0);
	for(int i=0;i<n;i++){
		if(!inedges[i]){
			vis[i]=true;
			qu.push(i);
		}
	}
	while(!qu.empty()){
		int u=qu.front();
		qu.pop();
		ts.push_back(u);
		for(int j=0;j<graph[u].size();j++){
			int v=graph[u][j];
			inedges[v]--;
			if(!inedges[v] && !vis[v]){
				vis[v]=true;
				qu.push(v);
			}
		}
	}
	return ts.size()!=n;
}

int main(){
	graph[1].push_back(2);
	graph[1].push_back(4);
	graph[2].push_back(3);
	graph[5].push_back(6);
	
	cout<<"Cycles: "<<(tsort(7)?"True":"False")<<endl;
	for(int i=0;i<7;i++){
		cout<<"at step "<<i<<" visit "<<ts[i]<<endl;
	}
}

// __________________________



// __________________________

// .\codes\graphs\topological_sort\topological_sort_tarjan.cpp

// Topological sort ( Tarjan )

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

#define N 100005
vector<int> graph[N];
vector<bool> vis;

vector<int> ts;

void dfs_ts(int u){
	
	 vis[u]=true;
	 for(int j=0;j<graph[u].size();j++){
	 	int v=graph[u][j];
	 	if(!vis[v]){
	 		dfs_ts(v);
		 }
	 }
	 ts.push_back(u);
}

void tsort(int n){
	ts.clear();
	vis.assign(n,0);
	for(int i=0;i<n;i++){
		if(!vis[i]){
			dfs_ts(i);
		}
	}
	reverse(ts.begin(),ts.end());
}

int main(){
	graph[1].push_back(2);
	graph[1].push_back(4);
	graph[2].push_back(3);
	graph[5].push_back(6);
	
	tsort(7);
	for(int i=0;i<7;i++){
		cout<<"at step "<<i<<" visit "<<ts[i]<<endl;
	}
}

// __________________________



// __________________________

// .\codes\graphs\traversal\bfs.cpp

// Breadth First Search

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define N 100005
vector<int> graph[N];
vector<bool> vis;

vector<int> depth;
queue<int> q;

void bfs(int s,int G_size){
	depth.assign(G_size,0);
	vis.assign(G_size,0);
	while(!q.empty()) q.pop();
	q.push(s);
	depth[s]=1;
	vis[s]=true;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int j=0;j<graph[u].size();j++){
			int v=graph[u][j];
			if(!vis[v]){
				vis[v]=true;
				depth[v]=depth[u]+1;
				q.push(v);
			}
		}
	}
}

int main(){
	graph[1].push_back(2);
	graph[1].push_back(4);
	graph[2].push_back(1);
	graph[2].push_back(3);
	graph[3].push_back(2);
	graph[4].push_back(1);
	graph[5].push_back(6);
	graph[6].push_back(5);
	
	bfs(1,7);
	for(int i=0;i<7;i++){
		cout<<i<<" at depth "<<depth[i]<<endl;
	}
}

// __________________________



// __________________________

// .\codes\graphs\traversal\dfs.cpp

// Depth First Search

#include<iostream>
#include<vector>
using namespace std;

#define N 100005
vector<int> graph[N];
bool vis[N];

void rdfs(int u){
	cout<<" at "<<u<<endl;
	
	vis[u]=true;
	for(int j=0;j<graph[u].size();j++){
		int v=graph[u][j];
		if(!vis[v]){
			rdfs(v);
		}
	}
}

void dfs(int G_size){
	for(int i=0;i<G_size;i++){
		if(!vis[i]){
			rdfs(i);
		}
	}
}

int main(){
	graph[1].push_back(2);
	graph[1].push_back(4);
	graph[2].push_back(1);
	graph[2].push_back(3);
	graph[3].push_back(2);
	graph[4].push_back(1);
	graph[5].push_back(6);
	graph[6].push_back(5);
	
	dfs(7);
}

// __________________________



// __________________________

// .\codes\maths\all_factors.cpp

// all factors / all divisors of a number
//including 1

#include<iostream>
#include<vector>
using namespace std;

vector<int> factors(int x){
	vector<int> result;
	for(int i=1;i*i<=x;i++){
		if(x%i==0){
			result.push_back(i);
			if(x/i!=i)	result.push_back(x/i);
		}
	}
	return result;
}

int main(){
	for(int x:factors(130)){
		cout<<x<<" ";
	}
}

// __________________________



// __________________________

// .\codes\maths\hcf.cpp

// HCF (Highest Common Factor)

#include<iostream>
using namespace std;

int hcf(int a,int b){ return b?hcf(b,a%b):a; }

int main(){
	cout<<hcf(9,12);
}

// __________________________



// __________________________

// .\codes\maths\lcm.cpp

// LCM (Least Common Multiple)

#include<iostream>
using namespace std;

int hcf(int a,int b){ return b?hcf(b,a%b):a; }

int lcm(int a,int b){return a*b/hcf(a,b);}

int main(){
	cout<<lcm(9,12);
}

// __________________________



// __________________________

// .\codes\maths\prime_factors.cpp

// prime factors / prime divisors of a number
//also returns count 

#include<iostream>
#include<vector>
#include<set>
using namespace std;

vector<pair<int,int> > primeFactors(int x){
	vector<pair<int,int> > result;
	for(int i=2;i*i<=x;i++){
		if(x%i==0){
			int count=0;
			while(x%i==0) x/=i,count++;
			result.push_back(make_pair(i,count));
		}
	}
	if(x!=1){
		result.push_back(make_pair(x,1));
	}
	return result;
}

int main(){
	for(auto x:primeFactors(3)){
		cout<<x.second<<" times "<<x.first<<endl;
	}
}

// __________________________



// __________________________

// .\codes\maths\seive_of_eratosthenes.cpp

// check if a number is a prime or not
// Seive of eratosthenes

#include<iostream>
#include<cstring>
using namespace std;

#define N_PRIME 1000000
bool primes[N_PRIME+1];

void seive(){
	memset(primes,true,N_PRIME*sizeof(typeof(primes[0])));
	primes[0]=primes[1]=false;
	for(int i=2;i*i<=N_PRIME;i++){
		if(primes[i]){
			for(int j=i*2;j<=N_PRIME;j+=i){
				primes[j]=false;
			}
		}
	}
}

int main(){
	seive();
	cout<<primes[2]<<" "<<primes[11]<<endl;
	cout<<primes[1]<<" "<<primes[100]<<endl;
}

// __________________________



