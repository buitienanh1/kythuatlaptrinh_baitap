#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int phepchia2so(int &a, int &b){
	int a, b;
	printf("nhap 2 gia tri muon chia: ");
	scanf("%d%d", &a, &b);
	try{
		if (b == 0)
		{
			printf("khong ca phep chia nao cho 0");
		}
		else{
			int i = a / b;
			return i;
		}
	}
	catch (char *st){
		printf("loi %s", st);
		return -1;
	}
}