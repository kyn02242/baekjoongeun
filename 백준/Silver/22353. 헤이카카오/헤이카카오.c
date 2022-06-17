#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int a;
	double d,k;
	double sum = 0;
	double tmp = 1;
	int cnt = 1;
	int flag = 0;
	int tmp2;

	scanf("%d %lf %lf",&a,&d,&k);	
	tmp2 = a;
	d/=100;
	k/=100;
	a = 0;
	while(d<=1){
		a+=tmp2;
		sum += d*a*tmp;
		tmp *= 1-d;
		d=d+d*k;
		if(d>1&&flag == 0){
			d=1;
			flag = 1;
		}
	}
	printf("%.7lf\n",sum);





	return 0;
}
