#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int i,j,k,l;
	int a;
	int cnt=0;
	int n;
	int min=4;
	//223
	scanf("%d",&n);
	for(i=223;i>=0;i--){
		for(j=0;j<=i;j++){
			for(k=0;k<=j;k++){
				for(l=0;l<=k;l++){
					if(i*i+j*j+k*k+l*l==n){
						if(i!=0){
							cnt++;
						}
						if(j!=0){
							cnt++;
						}
						if(k!=0){
							cnt++;
						}
						if(l!=0){
							cnt++;
						}
						if(cnt<min){
							min = cnt;
						}
						cnt = 0;
					}
				}
			}
		}
	}
	printf("%d",min);

	return 0;
}