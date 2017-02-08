
// HCF (Highest Common Factor)

#include<iostream>
using namespace std;

int hcf(int a,int b){ return b?hcf(b,a%b):a; }

int main(){
	cout<<hcf(9,12);
}
