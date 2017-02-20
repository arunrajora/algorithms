
// minimum spanning forest kruskal

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<pair<int,pair<int,int> > > edges;

vector<int> p,rankArr;
int countSets;
void initialize(int N) { countSets=N;rankArr.assign(N,0);p.assign(N,0); for(int i=0;i<N;i++) p[i]=i; }

int findSet(int i){ return p[i]==i?i:(p[i]=findSet(p[i])); }

bool isSameSet(int i,int j){ return findSet(i)==findSet(j); }

void unionSet(int i,int j){
	if(!isSameSet(i,j)){
		countSets--;
		int x=findSet(i),y=findSet(j);
		if(rankArr[x]>rankArr[y]) p[y]=x;
		else{
			p[x]=y;
			if(rankArr[x]==rankArr[y]) rankArr[y]++;
		}
	}
}

int mst(int forestSize){
	initialize(edges.size());
	sort(edges.begin(),edges.end());
	int mst_cost=0;
	for(int i=0;i<edges.size() && countSets>forestSize;i++){
		pair<int,pair<int,int> > front=edges[i];
		if(!isSameSet(front.second.first,front.second.second)){
			mst_cost+=front.first;
			unionSet(front.second.first,front.second.second);
		}
	}
	return mst_cost;
}

int main(){
	edges.push_back(make_pair(4,make_pair(1,0)));
	edges.push_back(make_pair(2,make_pair(1,2)));
	edges.push_back(make_pair(6,make_pair(0,3)));
	edges.push_back(make_pair(4,make_pair(0,2)));
	edges.push_back(make_pair(6,make_pair(0,4)));
	edges.push_back(make_pair(8,make_pair(2,3)));
	edges.push_back(make_pair(9,make_pair(3,4)));
	cout<<mst(2);
}
