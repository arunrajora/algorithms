
// Power of a number

#include<iostream>
#include<vector>
using namespace std;

#define ull unsigned long long

ull pow(ull a,ull b){
	if(b==0){
		return 1;
	}
	else{
		ull val=pow(a,b/2);
		val*=val;
		if(b%2){
			val*=a;
		}
		return val;
	}
}

int main(){
	cout<<pow(2,4)<<endl;
	cout<<pow(2,10)<<endl;
	cout<<pow(3,3)<<endl;
}
