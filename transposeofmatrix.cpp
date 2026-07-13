#include <stdio.h>
int main(){
	int n=2;
	int m=3;
	
	int matrix[2][3]={
	{1, 2, 3},
	{4, 5, 6}
	};
	
	int transpose[3][2];
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			transpose[j][i]=matrix[i][j];
		}
	}
	printf("%d * %d", n, m);
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			printf("%d", transpose[i][j]);
		}
		return 0;
	}
}
