#include<stdio.h>
#include<stdlib.h>

typedef struct{
	int *p;
	int size;
} array;

array a;

// Nhap phan tu
void nhap(void){
	printf("Nhap so luong phan tu: ");
	scanf("%d", &a.size);
	a.p = (int *)malloc(a.size * sizeof(int));
	for(int i = 0; i < a.size; i++){
		scanf("%d", &a.p[i]);
	}
}

//Xuat phan tu 
void xuat(void){
	printf("Cac phan tu cua mang cap phat la: ");
	for(int i = 0; i < a.size; i++){
		printf("%d ", a.p[i]);
	}	
}

// Them phan tu 
void them(void){
	int position, value;
	printf("\n-----------------------------\n");
	printf("\nGia tri phan tu them vao: ");
	scanf("%d", &value);
	printf("Vi tri them vao: ");
	scanf("%d", &position);
	a.size++;
	a.p=(int*)realloc(a.p, a.size * sizeof(int));
	for(int i = a.size-1; i > position; i--){
		a.p[i] = a.p[i-1];
	}
	a.p[position]=value;
} 
	
// Sua phan tu 
void sua(void){
	int position, value;
	printf("\n-----------------------------\n");
	printf("\nGia tri phan tu can sua: ");
	scanf("%d", &value);
	printf("Vi tri sua: ");
	scanf("%d", &position);
	if(position <= 0 || position >= a.size){
		printf("Vi tri khong hop le\n");
	}else{
		a.p[position] = value;
	}
}

//Xoa phan tu
void xoa(void){
	int position;
	printf("\n-----------------------------\n");
	printf("\nVi tri can xoa: ");
	scanf("%d", &position);
	if(position >= 0 && position < a.size){
		for(int i = position; i < a.size-1; i++){
			a.p[i] = a.p[i+1];
		}
		a.size--;
        a.p = (int *)realloc(a.p, a.size * sizeof(int));
	}else{
		printf("Vi tri khong hop le");
	}
}
int main(){
	
	nhap();
	
	xuat();
	
	them();
	xuat();
	
	sua();
	xuat();
	
	xoa();
	xuat();
	return 0;
}
