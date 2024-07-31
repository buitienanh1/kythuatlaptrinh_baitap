#include <stdio.h>
#include <stdlib.h>
int TongNTrenN(int a) {
	if (a == 0) {
		return 0;
	}
	return a/a+1 + TongNTrenN(a - 1);
}
void main() {
	int a = 10;
	printf("tong tu 1/2 den n/n+1 la: %d", TongNTrenN(a));
}