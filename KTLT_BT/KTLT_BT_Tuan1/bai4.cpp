#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
void nhapM1C_SoNguyen(int *&a, int &b){
	b = 10;
	a = (int*)malloc(b*sizeof(int));
	for (int i = 0; i < b; i++)
	{
		*(a + i) = rand() % 100;
	}
}
void xuatM1C_SoNguyen(int *a, int b){
	for (int i = 0; i < b; i++)
	{
		printf("phan tu thu %d co gia tr %d và dia chi là %x", i, *(a + i), a + i);
	}
}