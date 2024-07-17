#include <stdio.h>
#include<conio.h>
#include <stdlib.h>
int timKiemTrongMang(int a[]) {
	int x;
	printf("nhap so muon tim kiem: ");
	scanf_s("%d", &x);
	for (int i = 0; i < sizeof(a); i++)
	{
		if (a[i]==x)
		{
			return i;
			break;
		}

	}
	return -1;
}
void TaoMangToanChans(int a[], int n) {
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % (100 + 1);
		if (a[i] % 2 != 0) {
			i--;
		}
	}
}
