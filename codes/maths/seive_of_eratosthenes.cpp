
// check if a number is a prime or not
// Seive of eratosthenes

#include<iostream>
#include<cstring>
using namespace std;

#define N_PRIME 1000000
bool primes[N_PRIME+1];

void seive(){
	memset(primes,true,N_PRIME*sizeof(typeof(primes[0])));
	primes[0]=primes[1]=false;
	for(int i=2;i*i<=N_PRIME;i++){
		if(primes[i]){
			for(int j=i*2;j<=N_PRIME;j+=i){
				primes[j]=false;
			}
		}
	}
}

int main(){
	seive();
	cout<<primes[2]<<" "<<primes[11]<<endl;
	cout<<primes[1]<<" "<<primes[100]<<endl;
}
