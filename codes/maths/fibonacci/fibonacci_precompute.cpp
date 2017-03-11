
// precompute fibonacci numbers

#include<iostream>
#include<vector>
using namespace std;

#define ull unsigned long long

#define FIBMAX 100005

vector<int> fib;

void pre_fib(int n=FIBMAX){
	 fib.assign(n+1,0);
	 fib[1]=1;
	 for(int i=2;i<=n;i++){
	 	fib[i]=fib[i-1]+fib[i-2];
	 }
}

int main(){
	pre_fib();
	for(int i=0;i<10;i++){
		cout<<fib[i]<<endl;
	}
	return 0;
}
