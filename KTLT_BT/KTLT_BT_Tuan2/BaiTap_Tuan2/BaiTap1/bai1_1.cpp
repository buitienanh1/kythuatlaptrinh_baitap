#include <stdio.h>
#include<conio.h>
#include <stdlib.h>
void TaoMangNgauNhien(int a[],int n) {
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % (20) + 15;
	}
}
