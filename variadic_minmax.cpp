// Viet ham tra ve ca min va max cho cac so nguyen truyen vao 
// Viet ham tra ve gia tri trung binh cho cac so thuc truyen vao

#include<stdio.h>
#include<stdarg.h>

int find(int n, ...){
	
	va_list ptr;
	
	va_start(ptr,n);
	
		int max = va_arg(ptr,int);
		int min = max;
			for(int i = 1; i < n; i++){
				int temp = va_arg(ptr,int);	
				if(temp > max){
					max = temp;
		}else{
			min = temp;
		}
		}
		printf("\nGia tri max la: %d", max);
		printf("\nGia tri min la: %d", min);
	va_end(ptr);
	return 0;
	}

double tb(int n ...){
// kieu double vi so luong tham so truyen vao khong xac dinh
// co the vuot qua kich thuoc cua float 
	
	va_list(ptr);
	
	va_start(ptr,n);

		double sum = 0.0;
		for(int i = 0; i < n; i++){
			sum+= va_arg(ptr,double);
	}
	double tb = sum/n;
	va_end(ptr);
	return tb;
}
	
int main(){
	printf("\nIn cac ket qua: ");
	find(5,4,7,-9,10,20);
	printf("\nGia tri trung binh la: %.2lf", tb(3, 2.3, 4.5, 1.0));
	return 0;
}
