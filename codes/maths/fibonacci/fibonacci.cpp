
// n-th fibonacci number

#include<iostream>
#include<vector>
using namespace std;

#define ull unsigned long long

#define FIBMAX 100005

void mat_multiply(int a[2][2],int b[2][2]){
	int p=a[0][0]*b[0][0]+a[0][1]*b[1][0];
	int q=a[0][0]*b[0][1]+a[0][1]*b[1][1];
	int r=a[1][0]*b[0][0]+a[1][1]*b[1][0];
	int s=a[1][0]*b[0][1]+a[1][1]*b[1][1];
	a[0][0]=p;
	a[0][1]=q;
	a[1][0]=r;
	a[1][1]=s;
}

void fibpow(int f[2][2],int n){
	if(n<2) return;
	int val[2][2]={{1,1},{1,0}};
	fibpow(f,n/2);
	mat_multiply(f,f);
	if(n&1){
		mat_multiply(f,val);
	}
}

ull fib(int n){
	int val[2][2]={{1,1},{1,0}};
	if(n>0)
	fibpow(val,n-1);
	return n>0?val[0][0]:0;
}

int main(){
	cout<<fib(0)<<endl;
	cout<<fib(1)<<endl;
	cout<<fib(2)<<endl;
	cout<<fib(3)<<endl;
	cout<<fib(4)<<endl;
	cout<<fib(5)<<endl;
	cout<<fib(6)<<endl;
	cout<<fib(7)<<endl;
	cout<<fib(8)<<endl;
	cout<<fib(9)<<endl;
	return 0;
}
