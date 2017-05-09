#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct producto{
	char nombre[20];
	unsigned short id;
	char marca[20];
	float precio;
};

////////////////////////////////////////////////////////////////
////					Inventario.c						////
////														////
////														////
//// Realización de un inventario de productos ya definidos	////
//// que los imprime con sus precios e ID, ambos random.	////
////														////
////														////
//// Autor: Romero Gamarra Joel Mauricio					////
////////////////////////////////////////////////////////////////

void imprimir_valores(struct producto a1[10]){
	int x;
	printf ("ID \t Nombre \t Marca \t\t Precio \n\n");
	for (x=0;x<10;x++)
	{
		printf("\n");
		printf("%.5d \t %s \t %s \t %.2f \n", (*(a1+x)).id, (*(a1+x)).nombre, (*(a1+x)).marca, (*(a1+x)).precio);
	}
}


int main() 
{
	int x;
	struct producto inventario[10];
	strcpy((*(inventario+0)).marca,"Sol\t");
	strcpy((*(inventario+1)).marca,"Modelo");
	strcpy((*(inventario+2)).marca,"Victoria");
	strcpy((*(inventario+3)).marca,"Modelo");
	strcpy((*(inventario+4)).marca,"Dos Equis");
	strcpy((*(inventario+5)).marca,"Tecate");
	strcpy((*(inventario+6)).marca,"Indio\t");
	strcpy((*(inventario+7)).marca,"Kloster");
	strcpy((*(inventario+8)).marca,"Cucapa");
	strcpy((*(inventario+9)).marca,"Budlight");
	for (x=0;x<10;x++)
	{
		strcpy((*(inventario+x)).nombre,"Chela :D");
		(*(inventario+x)).id=rand() * (40) + 25;		
		(*(inventario+x)).precio=rand() % 9 + 23.0;
	}
	imprimir_valores(inventario);
	return 0;
}
