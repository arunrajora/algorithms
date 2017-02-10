
// Disjoint set union

#include<iostream>
#include<vector>
using namespace std;

vector<int> p,rankArr;

void initialize(int N) { rankArr.assign(N,0);p.assign(N,0); for(int i=0;i<N;i++) p[i]=i; }

int findSet(int i){ return p[i]==i?i:(p[i]=findSet(p[i])); }

bool isSameSet(int i,int j){ return findSet(i)==findSet(j); }

void unionSet(int i,int j){
	if(!isSameSet(i,j)){
		int x=findSet(i),y=findSet(j);
		if(rankArr[x]>rankArr[y]) p[y]=x;
		else{
			p[x]=y;
			if(rankArr[x]==rankArr[y]) rankArr[y]++;
		}
	}
}

int main(){
	initialize(4);
	cout<<findSet(1)<<" "<<findSet(2)<<endl;
	cout<<isSameSet(1,2)<<endl;
	unionSet(1,2);
	cout<<findSet(1)<<" "<<findSet(2)<<endl;
	cout<<isSameSet(1,2)<<endl;
	
	return 0;
}
