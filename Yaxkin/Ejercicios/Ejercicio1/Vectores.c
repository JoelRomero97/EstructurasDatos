#include <stdio.h>
#include <stdlib.h>

void mult (int a[4],int x);
void suma(int a[4],int b[]);

int main() {
	int resp,x=4;
	int a[4]={2,4,6,10};
	int b[4]={1,3,5,12};
	puts("\t\t\nMENU\n\n");
	puts("\t1.MULTIPLICAR UN VECTOR POR UNA CANTIDAD ESCALAR\n\n");
	puts("\t2.SUMAR 2 VECTORES\n\n'");
	scanf("%d",&resp);
	switch(resp){
		case 1: printf("\n\tEl vector es: 2x + 4y + 6z = 10\n");
			 	printf("\n\tEl numero escalar es: 4\n");
		    mult(a,x);
		    break;
		case 2: printf("\n\tEl primer vector es: 2x + 4y + 6z = 10\n");
			 	printf("\n\tEl segundo vector es: x + 3y + 5z = 12\n");
			 	suma(a,b);
			 	break;
	}
	
	return 0;
}

void mult(int a[4],int x){
	int i,res[4];
for (i=0;i<4;i++){
	res[i]=a[i]*x;
}	
printf("%dx + %dy + %dz = %d",res[0],res[1],res[2],res[3]);
}
void suma(int a[4],int b[4]){
	int i,res[4];
	for (i=0;i<4;i++){
	res[i]=a[i]+b[i];
	}
	printf ("%dx + %dy + %dz = %d",res[0],res[1],res[2],res[3]);
}
