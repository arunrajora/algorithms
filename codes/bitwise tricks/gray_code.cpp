
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
