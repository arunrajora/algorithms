
// n-th fibonacci number

#include<iostream>
#include<vector>
using namespace std;

#define ull unsigned long long

#define FIBMAX 100005

int fdp[FIBMAX]={0};

ull fib(int n){
	if(n<3){
		return fdp[n]=(n>0);
	}
	if(fdp[n]>0){
		return fdp[n];
	}
	int k=(n%2)?(n+1)/2:n/2;
	return fdp[n]=(n%2)?(fib(k)*fib(k)+fib(k-1)*fib(k-1)):fib(k)*(fib(k)+2*fib(k-1));
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
