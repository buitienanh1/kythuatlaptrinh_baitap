#include <stdio.h>
#include <stdlib.h>
int TongN(int a) {
	if (a == 0) {
		return 0;
	}
	return a + TongN(a - 1);
 }
//void main() {
//	int a = 10;
//	printf("tong tu 1 den n la: %d", TongN(a));
//}