
// general geometry

#include<iostream>
#include<vector>
using namespace std;

struct point{
	int x;
	int y;
	point(int a,int b){
		x=a;
		y=b;
	}
};

int determinant(point a,point b){
	return a.x*b.y-b.x*a.y;
}

//ab and ac
bool isclockwise(point a,point b,point c){
	return ((b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y))>0;
}

//ab and ac
bool isanticlockwise(point a,point b,point c){
	return ((b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y))<0;
}

//ab and ac
bool iscolinear(point a,point b,point c){
	return ((b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y))==0;
}

int main(){
	point pt=point(2,3);
	cout<<determinant(pt,pt)<<endl;
	cout<<isclockwise(pt,pt,pt)<<" "<<isanticlockwise(pt,pt,pt)<<" "<<iscolinear(pt,pt,pt)<<endl;
}
