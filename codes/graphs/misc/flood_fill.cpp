
// Flood fill on 2d Matrix
// replace a character with other character in a continuous area.
#include<iostream>
#include<vector>
using namespace std;

char grid[1001][1001]={{'+','-','-','-'},
	       {'+','+','+','-'},
		   {'+','-','+','+'},
		   {'+','+','+','-'}};
int R,C;

int dr[8]={1,1,0,-1,-1,-1,0,1};
int dc[8]={0,1,1,1,0,-1,-1,-1};

int floodfillrec(int r,int c,char c1,char c2){
	if(r<0 || r>=R || c<0 || c>=C) return 0;
	if(grid[r][c]!=c1) return 0;
	int ans=1;
	grid[r][c]=c2;
	for(int d=0;d<8;d++){
		ans+=floodfillrec(r+dr[d],c+dc[d],c1,c2);
	}
	return ans;
}

void floodfill(char c1,char c2){
	int region_count=0;
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			if(grid[i][j]==c1){
				int blocks=floodfillrec(i,j,c1,c2);
				region_count++;
				cout<<region_count<<" has "<<blocks<<" blocks."<<endl;
			}
		}
	}
}

int main(){
	R=4,C=4;
	
	floodfill('-','*');
	
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			cout<<grid[i][j];
		}cout<<endl;
	}
}
