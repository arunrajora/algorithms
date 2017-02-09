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
