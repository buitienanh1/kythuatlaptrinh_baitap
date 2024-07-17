#include <stdio.h>
#include<conio.h>
#include <stdlib.h>
void SapxepMang(int &a,int &b) {
	int temp = a;
	a = b;
	b = temp;
}
void  Interchange_Sort(int a[]) {
	int n = sizeof(a);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n+1; j++)
		{
			if (a[i] > a[j]) {
				SapxepMang(a[i], a[j]);
			}
		}
	}
}
void TaoMangToanChanss(int a[], int n) {
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % (100 + 1);
		if (a[i] % 2 != 0) {
			i--;
		}
	}
}
void main() {
	int a[100];
	int n;
	printf("nhap so phan tu trong mang: ");
	scanf_s("%d", &n);
	TaoMangToanChanss(a, n);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	Interchange_Sort(a);
	printf("\n sau sap xep: ");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}

}