#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct producto{
	char nombre[20];
 	int id;
	char marca[20];
	float precio;
	int cant;
};
void seleccionar(struct producto *ptr,int c, int z,int j);
void ver(struct producto *ptr, int c,int a);
void vaciar(struct producto *pt, int n);
void ticket(struct producto *pt, int a);

////////////////////////////////////////////////////////////////
////				InventarioArchivos.c					////
////														////
////														////
//// Inventario de productos definidos, pero utilizando el 	////
//// manejo de archivos y la opción de agregar opciones		////
//// al carrito de compras, además de mostrarlo, vaciarlo	////
//// y hacer el checkout mostrando el ticket.				////
////														////
////														////
//// Autor: Romero Gamarra Joel Mauricio					////
////////////////////////////////////////////////////////////////

int main(int argc, char *argv[]) {
	int i,n,a,z,x,c,y;
	int j=0;
	struct producto *pt=NULL;
	struct producto *ptr=NULL;
	FILE *fp;
	fp=fopen("productos.txt","r");
	fscanf(fp,"%d",&n);
	int carro[n];
	ptr=(struct producto *)malloc(sizeof(struct producto)*n); //inventario
	pt=(struct producto *)malloc(sizeof(struct producto)*(2*n)); //carrito
	for (i=0;i<n;i++){
		fscanf(fp,"%d %s %s %f %d",&(ptr+i)->id,(ptr+i)->nombre,(ptr+i)->marca,&(ptr+i)->precio,&(ptr+i)->cant);
	}
		menu:
	printf ("\n\n\t\tMENU\n\n");
	puts("1. Seleccionar productos");
	puts("2. Ver carrito");
	puts("3. Vaciar carrito");
	puts("4. Hacer checkout\n\n");
	scanf ("%d", &x);
    	  switch(x){
	case 1:		
				printf ("\n\n%cQue producto deseas agregar al carrito? \nIndice \t Nombre \t ID \t\t Marca \t\t Precio \t Existencia\n",168);
				for (i=0;i<n;i++){	
					printf("%-7d  %-14s  %-14d  %-14s  %-14.2f  %-5d \n",i+1,(ptr+i)->nombre,(ptr+i)->id,(ptr+i)->marca,(ptr+i)->precio,(ptr+i)->cant);
				}
				op1:
				printf("\n\n%d\tRegresar al menu\n\n", n+1);
				scanf ("%d", &z);
				if(z==(n+1)||z>n+1){
					printf("Opcion invalida");
					goto op1;
				}else 
				goto op2;
				op2:
				printf("\n\n%cCuantos elementos de este producto desea agregar?",168);
				scanf("%d",&c);	
				do {	
				printf("\n\n%cDesea agregar algun otro producto?",168);
				puts("\n1.Si\t\t\t2.No");
				scanf("%d",&y);
				switch (y){
					case 1: goto op1;
					break;
					case 2: goto menu;
					break;
					default: printf("\n\nOpcion invalida");
				}
				printf("\n\nPara regresar al menu presione %d",n+1);
				if(c>=1&&c<=n){
					((ptr+i)->precio)*=c;
					seleccionar(ptr,c,z,j);
					j++;
					
				}else {
					printf("No hay suficiente existencia en el inventario");
				}			
				}while(z!=(n+1)||z<=n);
				goto menu;
				break;
	case 2:
				ver(ptr,c,a);
				goto menu;
				break;
	case 3:
            	vaciar(ptr, n);
            	a=0;
            	goto menu;
		 		break;
	case 4:
		    	ticket(ptr, a);
    			break;
	default:
		printf ("\n\nOpcion invalida\n");
		goto menu;
	    }
	return 0;
}


void seleccionar(struct producto *ptr, int c, int z, int j){
	
}

void ver(struct producto *ptr, int c,int n)
{
	int i;
	printf ("\nIndice \t Nombre \t ID \t\t Marca \t\t Precio \t Cantidad\n");
	for (i=0;i<n;i++){	
	printf("%-7d  %-14s  %-14d  %-14s  %-14.2f  %-5d \n",i+1,(ptr+i)->nombre,(ptr+i)->id,(ptr+i)->marca,(ptr+i)->precio,c);
	}	
}

void vaciar(struct producto *pt, int n)
{
	int i;
	for (i=0;i<n;i++)
	{
		strcpy((pt+i)->nombre,"");
		(pt+i)->id=0;
		strcpy((pt+i)->marca,"");
		(pt+i)->precio=0.0;
	}
}

void ticket(struct producto *pt, int a){
	int i;
	float t;
	printf ("Los productos que compro fueron los siguiente:\nNombre \t ID \t Marca \t Precio\n");
	for (i=0;i<a;i++){	
	printf("%s \t %d \t %s \t %f \n",(pt+i)->nombre,(pt+i)->id,(pt+i)->marca,(pt+i)->precio);
	t+=(pt+i)->precio;
	}
	printf("   \t   \tTOTAL: %f \n\t\t",t);
	
}

