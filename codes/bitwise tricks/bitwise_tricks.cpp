
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
	
}
