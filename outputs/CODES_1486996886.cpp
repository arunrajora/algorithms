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

// .\codes\data structures\graph_init.cpp

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

// .\codes\data structures\segment_tree.cpp

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

// .\codes\data structures\set_union.cpp

// Disjoint set union

#include<iostream>
#include<vector>
using namespace std;

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

int main(){
	initialize(4);
	cout<<findSet(1)<<" "<<findSet(2)<<endl;
	cout<<isSameSet(1,2)<<endl;
	unionSet(1,2);
	cout<<findSet(1)<<" "<<findSet(2)<<endl;
	cout<<isSameSet(1,2)<<endl;
	
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

// .\codes\graphs\articulation_point_bridges.cpp

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

// .\codes\graphs\bfs.cpp

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

// .\codes\graphs\bipartite_check.cpp

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

// .\codes\graphs\connected_component.cpp

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

// .\codes\graphs\dag_check.cpp

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

// .\codes\graphs\dfs.cpp

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

// .\codes\graphs\edge_type.cpp

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

// .\codes\graphs\flood_fill.cpp

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

// .\codes\graphs\strongly_connected_components.cpp

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

// .\codes\graphs\topological_sort_khan.cpp

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

// .\codes\graphs\topological_sort_tarjan.cpp

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



