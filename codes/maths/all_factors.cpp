
// all factors / all divisors of a number
//including 1

#include<iostream>
#include<vector>
using namespace std;

vector<int> factors(int x){
	vector<int> result;
	for(int i=1;i*i<=x;i++){
		if(x%i==0){
			result.push_back(i);
			if(x/i!=i)	result.push_back(x/i);
		}
	}
	return result;
}

int main(){
	for(int x:factors(130)){
		cout<<x<<" ";
	}
}
