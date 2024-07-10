#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
/*void main(){
	int namsinh;
	printf("nhap nam sinh cua ban: ");
	scanf("%d", &namsinh);
	try{
		int tuoi = tinhtuoi(namsinh);
		if (tuoi == -1){
			printf("loi khong hop le");
		}
		else
		{
			printf("tuoi cua ban la: %d", tuoi);
		}
		
	}
	catch (char *st){
		printf("loi %s", st);
	}
	getch();
}*/
int tinhtuoi(int namsinh){
	time_t now = time(0);
	tm*ltm = localtime(&now);
	int namhh = 1900 + ltm->tm_year;
	try{
		if (namsinh <= 0 || namsinh > namhh){
			throw 101;
		}
		else
		{
			if (namsinh < 1920){
				throw 102;

			}
			else
			{
				return namhh - namsinh;
			}
		}
	}
	catch(int errcode){
		if (errcode == 101)
		{
			printf("khong hop le!");
		}
		else{
			printf("nam sinh vuot qua  1920");
		}
		return -1;
	}
}