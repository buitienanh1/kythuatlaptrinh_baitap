#include <stdio.h>
#include<conio.h>
#include <stdlib.h>
void TaoMangToanChan(int a[], int n) {
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % (100 + 1);
		if (a[i] % 2 != 0) {
			i--;
		}
	}
}