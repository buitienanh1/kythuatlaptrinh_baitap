#include <stdio.h>
#include <stdlib.h>
int Tong2Nthem1TrenN(int a) {
	if (a == 0) {
		return 0;
	}
	return 1 / 2*a + 1 + Tong2Nthem1TrenN(a - 1);
}
void main() {
	int a = 10;
	printf("tong tu 1/1 den 1/2n+1 la: %d", Tong2Nthem1TrenN(a));
}