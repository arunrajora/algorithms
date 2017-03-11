
// n-th fibonacci number

#include<iostream>
#include<vector>
using namespace std;

#define ull unsigned long long

#define FIBMAX 100005

void mat_multiply(ull a[2][2],ull b[2][2],ull mod){
	ull p=((a[0][0]*b[0][0])%mod+(a[0][1]*b[1][0])%mod)%mod;
	ull q=((a[0][0]*b[0][1])%mod+(a[0][1]*b[1][1])%mod)%mod;
	ull r=((a[1][0]*b[0][0])%mod+(a[1][1]*b[1][0])%mod)%mod;
	ull s=((a[1][0]*b[0][1])%mod+(a[1][1]*b[1][1])%mod)%mod;
	a[0][0]=p;
	a[0][1]=q;
	a[1][0]=r;
	a[1][1]=s;
}

void fibpow(ull f[2][2],ull n,ull mod){
	if(n<2) return;
	ull val[2][2]={{1,1},{1,0}};
	fibpow(f,n/2,mod);
	mat_multiply(f,f,mod);
	if(n&1){
		mat_multiply(f,val,mod);
	}
}

ull fib(ull n,ull mod){
	ull val[2][2]={{1,1},{1,0}};
	if(n>0)
	fibpow(val,n-1,mod);
	return n>0?val[0][0]:0;
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
