
// LCM (Least Common Multiple)

#include<iostream>
using namespace std;

int hcf(int a,int b){ return b?hcf(b,a%b):a; }

int lcm(int a,int b){return a*b/hcf(a,b);}

int main(){
	cout<<lcm(9,12);
}
