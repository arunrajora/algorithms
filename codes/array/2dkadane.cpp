
// Dynamic programming ( largest sum contiguous subarray / maximum subarray problem ) in a 2D matrix
// 2D Kadane's algorithm 

#include<iostream>
#include<cstring>
using namespace std;

int mat[100][100];
int tmp_array[110]; 

int kadane(int arr[], int n) {
    int sum = INT_MIN;
    int maxsum = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (sum < 0)
            sum = arr[i];
        else
            sum += arr[i];
        maxsum = max(maxsum, sum);
    }
    return maxsum;
}

int kadane_2d(int R,int C) {
    int maxsum = INT_MIN;
    for (int left = 0; left < C; left++) {
        memset(tmp_array, 0, sizeof(tmp_array));
        for (int right = left; right < C; right++) {
            for (int i = 0; i < R; ++i) {
                tmp_array[i] += mat[i][right];
            }
            maxsum = max(maxsum, kadane(tmp_array, R));
        }
    }
    return maxsum;
}

int main(){
	
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			mat[i][j]=2;
		}
	}
	cout<<kadane_2d(2,3);
	
	return 0;
}
