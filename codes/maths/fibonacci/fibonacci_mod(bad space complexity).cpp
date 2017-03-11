
// n-th fibonacci number

#include<iostream>
#include<vector>
using namespace std;

#define ull unsigned long long

#define FIBMAX 100005

int fdp[FIBMAX]={0};

ull fib(ull n,ull mod){
	if(n<3){
		return fdp[n]=(n>0);
	}
	if(fdp[n]>0){
		return fdp[n];
	}
	int k=(n%2)?(n+1)/2:n/2;
	return fdp[n]=(n%2)?((fib(k,mod)*fib(k,mod))%mod+(fib(k-1,mod)*fib(k-1,mod)%mod))%mod:(fib(k,mod)*(((fib(k,mod)+2*fib(k-1,mod)))%mod))%mod;
}

int main(){
	cout<<fib(0,10)<<endl;
	cout<<fib(1,10)<<endl;
	cout<<fib(2,10)<<endl;
	cout<<fib(3,10)<<endl;
	cout<<fib(4,10)<<endl;
	cout<<fib(5,10)<<endl;
	cout<<fib(6,10)<<endl;
	cout<<fib(7,10)<<endl;
	cout<<fib(8,10)<<endl;
	cout<<fib(9,10)<<endl;
	return 0;
}
