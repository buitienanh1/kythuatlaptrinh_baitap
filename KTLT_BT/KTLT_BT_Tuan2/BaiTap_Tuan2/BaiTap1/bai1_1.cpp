#include <stdio.h>
#include<conio.h>
#include <stdlib.h>
void TaoMangNgauNhien(int a[],int n) {
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % (20) + 15;
	}
}
void main() {
	int a[100];
	int n;
	printf("nhap so phan tu trong mang: ");
	scanf_s("%d", &n);
	TaoMangNgauNhien(a, n);
	for (int i = 0; i < n; i++)
	{
		printf("%d ",a[i]);
	}
	
}