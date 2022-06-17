#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int i,j;
	int tmp;
	int t;
	int n;
	int arr[50000];
	int cnt = 0;
	scanf("%d",&t);

	for(i=0;i<t;i++){
		cnt = 0;
		scanf("%d",&n);
		for(j=0;j<n;j++){
			scanf("%d",&arr[j]);
		}
		if(arr[0]>(n+1)/2){
			arr[0] = n-arr[0] + 1;
		}
		for(j=1;j<n;j++){
			if(arr[j]<arr[j-1]){
				arr[j]=n-arr[j]+1;
			}
			else if(arr[j]>=arr[j-1]&&n-arr[j]+1>=arr[j-1]){
				if(arr[j]>n-arr[j]+1){
					arr[j] = n-arr[j]+1;
				}
			}
		}

		// for(j=0;j<n;j++){
		// 	printf("%d ",arr[j]);
		// }
		// printf("==\n");


		for(j=1;j<n;j++){
			if(arr[j]>=arr[j-1]){
				cnt++;
			}
		}
		if(cnt == n-1||n==1){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}
	return 0;
}
