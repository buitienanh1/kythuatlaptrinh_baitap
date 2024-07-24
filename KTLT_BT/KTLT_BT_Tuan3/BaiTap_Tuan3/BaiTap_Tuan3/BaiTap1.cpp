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
void xuatDongChiChuaSoChan(int a[][100], int n, int m) {
	int x[100];
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] % 2 !=0)
			{
				x=[];
				break;
			}
		}
		printf("%d ");
		Max = 0;
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
	case 2: 
		printf("\nTong cua tung dong trong mang la: ");
		xuatTongTungDong(a, n, m);
	
	case 3:
		printf("\nPhan Tu lon nhat cua tung cot trong mang la: ");
		xuatPhanTuMAXCot(a, n, m);

	case 6:
		printf("\n Phan Tu Tang dan theo dong:");
		sapXepPhanTuTangDan(a, n, m);
		XuatMaTran2chieu(a, n, m);
	default:
		break;
	}
}