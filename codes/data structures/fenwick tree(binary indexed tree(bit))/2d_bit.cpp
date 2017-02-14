// 2-D Fenwick Tree / Binary Indexed Tree
// Point update Range Query or Range update Point Query
// use size of array N+1

#include<iostream>
#include<vector>
using namespace std;

#define N_X 1001
#define N_Y 1001
int ft[N_X][N_Y];

void updatey(int x,int y,int v){
	while(y<=N_Y){
		ft[x][y]+=v;
		y+=y&(-y);
	}	
}

void update(int x,int y,int v){
	 while(x<=N_X){
	 	updatey(x,y,v);
	 	x+=x&(-x);
	 }	
}

int update(int r1,int c1,int r2,int c2,int v){
	update(r1,c1,v);
	update(r1,c2+1,-v);
	update(r2,c1+1,-v);
	update(r2+1,c2+1,v);
}

int query(int x,int y){
	int sum=0;
	while(x){
		int y1=y;
		while(y1){
			sum+=ft[x][y];
			y1-=y1&(-y1);
		}
		x-=x&(-x);
	}
	return sum;
}


int query(int r1,int c1,int r2,int c2){
	return query(r2,c2)-query(r2,c1-1)-query(r1-1,c2)+query(r1-1,c1-1);
}

int main(){

	update(1,1,4,4,5);
	update(2,2,2,2,3);
	cout<<query(2,2)<<endl;
	cout<<query(5,5)<<endl;

//	update(1,1,4);
//	update(2,2,4);
//	cout<<query(1,1,2,2)<<endl;
//	cout<<query(1,1,4,4)<<endl;
//	cout<<query(3,3,5,5)<<endl;
//	
	return 0;
}
