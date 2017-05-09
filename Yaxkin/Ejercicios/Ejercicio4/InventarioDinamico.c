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

void seleccionar(struct producto *ptr,struct producto *pt,int a, int z);
void ver(struct producto *pt, int a);
void vaciar(struct producto *pt, int n);
void ticket(struct producto *pt, int a);

////////////////////////////////////////////////////////////////
////				InventarioDinamico.c					////
////														////
////														////
//// Inventario de productos ingresados por el usuario de 	////
//// manera dinámica que imprime los productos con su ID	////
//// y precio.												////
////														////
////														////
//// Autor: Romero Gamarra Joel Mauricio					////
////////////////////////////////////////////////////////////////

int main(void){
	int n,i,x,z,a=0;
	struct producto *ptr=NULL;
	struct producto *pt=NULL;
	printf("%cCuantos productos desea registrar? \n",168);
	scanf ("%d",&n);
	ptr=(struct producto *)malloc(sizeof(struct producto)*n);
	pt=(struct producto*)malloc(sizeof(struct producto)*(2*n));
	for (i=0;i<n;i++)
	{
		printf("\nIngrese el nombre del producto %d\t",i+1);
		scanf("%s",(ptr+i)->nombre);
		fflush(stdin); //POR SI A CASO :D
		printf("\nIngrese el ID del producto %d\t\t",i+1);
		scanf("%d",&(ptr+i)->id);
		fflush(stdin);
		printf("\nIngrese la marca del producto %d\t\t",i+1);
		scanf("%s",(ptr+i)->marca);
		fflush(stdin);
		printf("\nIngrese el precio del producto %d\t",i+1);
		scanf("%f",&(ptr+i)->precio);
		(ptr+i)->cant=rand() % 12;
		printf("\n\n\n");
	}
	menu:
	printf ("\n\nMENU\n");
	puts("1. Seleccionar productos");
	puts("2. Ver carrito");
	puts("3. Vaciar carrito");
	puts("4. Hacer checkout\n\n");
	scanf ("%d", &x);
    	  switch(x){
	case 1:
				printf ("\n\n%cQue producto deseas agregar al carrito? \nIndice \t Nombre \t ID \t Marca \t Precio \t Existencia\n",168);
				for (i=0;i<n;i++)
				{	
					printf("%d \t %s \t\t %d \t %s \t %.2f \t\t %d \n",i+1,(ptr+i)->nombre,(ptr+i)->id,(ptr+i)->marca,(ptr+i)->precio,(ptr+i)->cant);
				}
				printf("\n\n%d\tRegresar al menu\n\n", n+1);
				do{
					scanf ("%d", &z);
					if ((ptr+(z-1))->cant==0)
					{
						printf("Se termino ese producto \n");
						goto menu;
					}
					seleccionar(ptr, pt, a, z);
					a++;
				}while(z!=(n+1) || z<=n);
				goto menu;
				break;
	case 2:
				ver(pt, a);
				goto menu;
				break;
	case 3:
            	vaciar(pt, n);
            	a=0;
            	goto menu;
		 		break;
	case 4:
		    	ticket(pt, a);
    			break;
	default:
		printf ("\n\nOpcion invalida\n");
		goto menu;
	    }
	return 0;
}

void seleccionar(struct producto *ptr, struct producto *pt, int a, int z)
{
	strcpy((pt+a)->nombre,(ptr+(z-1))->nombre);
	(pt+a)->id=(ptr+(z-1))->id;
	strcpy((pt+a)->marca,(ptr+(z-1))->marca);
	(pt+a)->precio=(ptr+(z-1))->precio;
	(ptr+(z-1))->cant--;
}

void ver(struct producto *pt, int a)
{
	int i;
	printf ("Nombre \t ID \t Marca \t Precio\n");
	for (i=0;i<a;i++)
	{	
		printf("%s \t %d \t %s \t %f \n",(pt+i)->nombre,(pt+i)->id,(pt+i)->marca,(pt+i)->precio);
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

void ticket(struct producto *pt, int a)
{
	int i;
	float t;
	printf ("Los productos que compro fueron los siguiente:\nNombre \t ID \t Marca \t Precio\n");
	for (i=0;i<a;i++)
	{	
	printf("%s \t %d \t %s \t %f \n",(pt+i)->nombre,(pt+i)->id,(pt+i)->marca,(pt+i)->precio);
	t+=(pt+i)->precio;
	}
	printf("   \t   \tTOTAL: %f \n\t\t",t);
	
}

