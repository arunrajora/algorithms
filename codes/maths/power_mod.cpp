
// Power of a number mod a number

#include<iostream>
#include<vector>
using namespace std;

#define ull long long

ull pow(ull a,ull b,ull mod){
	if(b==0){
		return 1;
	}
	else{
		ull val=pow(a,b/2,mod);
		val=(val*val+mod)%mod;
		if(b%2){
			val=(val*a+mod)%mod;
		}
		return val%mod;
	}
}

int main(){
	cout<<pow(2,4,3)<<endl;
	cout<<pow(2,10,5)<<endl;
	cout<<pow(3,3,27)<<endl;
}
