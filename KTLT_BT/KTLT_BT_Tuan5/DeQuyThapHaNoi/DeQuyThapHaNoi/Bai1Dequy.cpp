#include<stdio.h>
#include<stdlib.h>
void MoveDisk(char from, char to) {
    printf("Di chuyen dia tu %c sang %c\n", from, to);
}
void Tower(int n, char colA, char colB, char colC) {
    if (n == 1) {
        // Nếu chỉ có 1 đĩa, chuyển trực tiếp từ colA sang colC
        MoveDisk(colA, colC);
    }
    else {
        // Bước 1: Di chuyển n-1 đĩa từ colA sang colB, sử dụng colC làm trung gian
        Tower(n - 1, colA, colC, colB);

        // Bước 2: Di chuyển đĩa lớn nhất (đĩa n) từ colA sang colC
        MoveDisk(colA, colC);

        // Bước 3: Di chuyển n-1 đĩa từ colB sang colC, sử dụng colA làm trung gian
        Tower(n - 1, colB, colA, colC);
    }
}
void main() {
    int n;

    printf("Nhap so luong dia: ");
    scanf_s("%d", &n); // Nhập số lượng đĩa

    printf("Cac buoc di chuyen:\n");
    Tower(n, 'A', 'B', 'C'); // Gọi hàm Tower với 3 cột A, B, C
}
