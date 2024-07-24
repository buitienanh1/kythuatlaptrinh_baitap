#include <stdlib.h>
#include<conio.h>
#include <stdint.h>
#include <stdio.h>
void TaoMaTran2Chieu(int a[][100], int n, int m) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			a[i][j] = rand() + (100 + 1);
		}
	}
}
void XuatMaTran2chieu(int a[][100], int n, int m) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}
void xuatTongTungDong(int a[][100], int n, int m)
{
	int Tong = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m - 1; j++)
		{
			Tong = Tong + a[i][j + 1];
		}
		printf("%d ", Tong);
		Tong = 0;
	}
}
void xuatPhanTuMAXCot(int a[][100], int n, int m) {
	int Max = 0;
	for (int i = 0; i < m; i++)
	{
		for (int  j = 0; j < n; j++)
		{
			if (Max<a[j][i])
			{
				Max = a[j][i];
			}
		}
		printf("%d ", Max);
		Max = 0;
	}
}
int kiemtraDongToanChan(int a[][100], int n, int m)
{
	for (int i = 0; i < m; i++)
	{
		if (a[n][i] % 2 != 0)
		{
			return -1;
		}
	}
	return n;
}
void xuatDongChiChuaSoChan(int a[][100], int n, int m) {
	int x[100];
	for (int i = 0; i < m; i++)
	{
		int ktra = kiemtraDongToanChan(a, i, n);
		if (ktra != -1) {
			for (int j = 0; j < n; j++)
			{
				printf("%d ", a[i][j]);
			}
		}
		
		
	}
	
}
void sapxep(int a, int b) {
	int tam = a;
	a = b;
	b = tam;
}
void sapXepPhanTuTangDan(int a[][100], int n, int m) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] < a[i][j+1])
			{
				sapxep(a[i][j], a[i][j + 1]);
			}
		}
		
	}
}
void xuatDuongvien(int a[][100], int n, int m) {
	// Kiểm tra nếu mảng rỗng
	if (n <= 0 || m <= 0) {
		printf("Mang rong!\n");
		return;
	}

	// In các phần tử trên cùng
	printf("\ncac phan tu tren cung: ");
	for (int j = 0; j < m; ++j) {
		printf("%d ", a[0][j]);
	}
	printf("\ncac phan tu ben phai: ");
	// In các phần tử bên phải
	for (int i = 1; i < n - 1; ++i) {
		printf("%d ", a[i][m - 1]);
	}
	printf("\ncac phan tu duoi cung: ");
	// In các phần tử dưới cùng (nếu có)
	if (n > 1) {
		for (int j = m - 1; j >= 0; --j) {
			printf("%d ", a[n - 1][j]);
		}
	}
	printf("\ncac phan tu ben tra : ");
	// In các phần tử bên trái (nếu có)
	if (m > 1) {
		for (int i = n - 2; i > 0; --i) {
			printf("%d ", a[i][0]);
		}
	}

	printf("\n"); // Xuất dòng mới
}
void menu() {
	printf("------------------------Menu----------------------------");
	printf("\n1.Tao va xuat ma tran a chua cac phan tu ngau nhien.");
	printf("\n2. Tinh va xuat tong gia tri tung dong.");
	printf("\n3. Xuat phan tu lon nhat tren tung cot..");
	printf("\n4. Xuat cac phan tu thuoc cac đuong bien tren, duoi, trai và phai. ");
	printf("\n5.Xuat dong chi chua so chan. ");
	printf("\n6.Sap xep mang a tang theo tung dong.");
}
void main() {
	menu();
	int n=0;
	int m=0;
	int a[100][100];
	int luachon;
	while (1)
	{
		printf("\nNhap Lua chon ban muon su dung:");
		scanf_s("%d", &luachon);
		switch (luachon)
		{
		case 1:
			printf("\nNhap so dong muon tao:");
			scanf_s("%d", &n);
			printf("\nnhap so hang muon tao:");
			scanf_s("%d", &m);
			TaoMaTran2Chieu(a, n, m);
			XuatMaTran2chieu(a, n, m);
			break;
		case 2:
			printf("\nTong cua tung dong trong mang la: ");
			xuatTongTungDong(a, n, m);
			break;
		case 3:
			printf("\nPhan Tu lon nhat cua tung cot trong mang la: ");
			xuatPhanTuMAXCot(a, n, m);
			break;
		case 4:
			xuatDuongvien(a, n, m);
			break;

		case 5:
			printf("\nDong toan phan tu chan trong mang la: ");
			xuatDongChiChuaSoChan(a, n, m);
			break;

		case 6:
			printf("\n Phan Tu Tang dan theo dong:");
			sapXepPhanTuTangDan(a, n, m);
			XuatMaTran2chieu(a, n, m);
			break;
		default:
			break;
		}
	}
}