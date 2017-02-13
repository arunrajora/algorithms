
// prime factors / prime divisors of a number
//also returns count 

#include<iostream>
#include<vector>
#include<set>
using namespace std;

vector<pair<int,int> > primeFactors(int x){
	vector<pair<int,int> > result;
	for(int i=2;i*i<=x;i++){
		if(x%i==0){
			int count=0;
			while(x%i==0) x/=i,count++;
			result.push_back(make_pair(i,count));
		}
	}
	if(x!=1){
		result.push_back(make_pair(x,1));
	}
	return result;
}

int main(){
	for(auto x:primeFactors(3)){
		cout<<x.second<<" times "<<x.first<<endl;
	}
}
