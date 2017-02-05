
//Calculate day from date

#include<iostream>
#include<string>
using namespace std;

string days[7]={"sunday","monday","tuesday","wednesday","thursday","friday","saturday"};

string dayFromDate(int d,int m,int y){
	y-=m<3;
	//0xD50E9994 => 0,3,2,5,0,3,5,1,4,6,2,4
	return days[(y+y/4-y/100+y/400+d+((((unsigned long long)0xD50E9994)>>((12-m)*3))&0x7))%7];
}

int main(){
	cout<<dayFromDate(5,2,2017);//sunday
	return 0;
}
