#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

////////////////////////////////////////////////////////////////////////
////                         iTunas.c								////
////																////
////																////
//// Programa parecido a lo que realiza el conocido programa iTunes ////
//// utilizando la estructura lista para crear listas músicales,    ////
//// borrar canciones, buscar canciones, etc. La biblioteca musical	////
//// es jalada por un archivo en donde ya previamente se agregaron  ////
//// algunas canciones.												////
////																////
////																////
//// Autor: Romero Gamarra Joel Mauricio                    		////
////////////////////////////////////////////////////////////////////////

int main(int argc, char *argv[])
{
	LISTA l;
	ini(&l);
	lecturaArchivo(&l);
	Menu(l);

	return 0;
}

void Menu(LISTA l)
{
	int num=1;
	do
	{
		system("cls");
		printf("\t\t\t\tiTunas\t\t\n\n");
		if(num!=1 && num!=2 && num!=3)
			printf("Opcion NO valida\n");
		printf("\t1-Biblioteca Musical\n\t2-Listas de Reproduccion\n\t3-Salir\n\n\n\n ");
		scanf("%d",&num);
	}while(num!=1 && num!=2 && num!=3);
	switch(num)
	{
		case 1:
			SubMenuUno(l);
			break;
		case 2:
			SubMenuDos(l);
			break;
		case 3:
			printf("\n\nPrograma Finalizado\n");
			exit(0);
			break;
	}
}

void SubMenuUno(LISTA l)
{
	int num=1;
	do
	{
		system("cls");
		printf("\t\t\t\tiTunas\t\t\n\n");
		if(num<1 || num>7)
			printf("Opcion NO valida\n");
		printf("1-Mostrar Biblioteca\n2-Agregar una cancion\n3-Modificar una cancion\n4-Buscar Canciones\n5-Borrar una cancion\n6-Guardar Cambios\n7-Regresar\nOpc: ");
		scanf("%d",&num);
	}while(num<1 || num>7);
	switch(num)
	{
		case 1:
			mostrarBiblioteca(l);
			printf("\n\n\t\tOprimir una tecla para continuar");
			getch();
			SubMenuUno(l);	
			break;
		case 2:
			agregarCancion(l);
			printf("\n\n\t\tOprimir una tecla para continuar");
			getch();
			SubMenuUno(l);	
			break;
		case 3:
			modificarCancion(&l);
			printf("\n\n\t\tOprimir una tecla para continuar");
			getch();
			SubMenuUno(l);	
			break;
		case 4:
			buscarCancion(&l);
			printf("\n\n\t\tOprimir una tecla para continuar");
			getch();
			SubMenuUno(l);
			break;
		case 5:
			borrarCancion(l);
			printf("\n\n\t\tOprimir una tecla para continuar");
			getch();
			SubMenuUno(l);	
			break;
		case 6:
			guardarCancion(l);
			printf("\n\n\t\tOprimir una tecla para continuar");
			getch();
			SubMenuUno(l);	
			break;
		case 7:
			Menu(l);
			break;
	}
}

void SubMenuDos(LISTA l)
{
	char nom[50], art[50], alb[50],car,noml[50];
	int num=1,i,ID,nc,j=0;
	do
	{
		system("cls");
		printf("\t\t\t\tiTunas\t\t\n\n");
		if(num<1 || num>6)
			printf("Opcion NO valida\n");
		printf("1-Mostrar Listas\n2-Cargar Listas\n3-Editar Lista\n4-Borrar Lista\n5-Crear Lista\n6-Regresar\nOpc: ");
		scanf("%d",&num);
	}while(num<1 || num>6);
	switch(num)
	{
		case 1:
			system("CLS");
		printf("\t\t\t\tiTunas\t\t\n\n");
			mostrarListas(&l);
			printf("\n\n\t\tOprime una tecla perro");
			getch();
			SubMenuDos(l);
			break;
		case 2:
			system("CLS");
		printf("\t\t\t\tiTunas\t\t\n\n");
			mostrarNombresListas(&l);
			printf("\n\n\t\tOprime una tecla");
			getch();
			SubMenuDos(l);
			SubMenuTres(l);
			break;
		case 3:
			SubMenuTres(l);
			break;
		case 4:
			system("CLS");
		printf("\t\t\t\tiTunas\t\t\n\n");
			mostrarNombresListas(&l);
			eliminarLista();
			printf("\n\n\t\tOprime una tecla perro");
			getch();
			SubMenuDos(l);
			break;
			break;
		case 5:
			system("CLS");
		printf("\t\t\t\tiTunas\t\t\n\n");
			strcpy(nom,"");
			strcpy(art,"");
			strcpy(alb,"");
			system("CLS");
			fflush(stdin);
		printf("\t\t\t\tiTunas\t\t\n\n");
			printf("Introduzca el nombre de la lista:\t");
			gets(noml);
			for(i=0;noml[i]!='\0';i++)
				noml[i]=toupper(noml[i]);
			AgregarLista(noml);
			printf("Cuantas canciones quieres agregar?\t");
			scanf("%d",&nc);
			AgregarALista(nc);
			do
			{
				system("CLS");
				fflush(stdin);
				printf("Escriba la palabra a buscar: ");
				gets(nom);
				for(i=0;nom[i]!='\0';i++)
					nom[i]=toupper(nom[i]);
				BuscarPaLista(&l, nom);
				printf("Introduzca el ID de la cancion que se desea agregar a la lista: ");
				scanf("%d",&ID);
				AgregarALista(ID);
				fflush(stdin);
				j++;
			}while(j<nc);
			printf("\n\n\t\tOprime una tecla perro");
			getch();
			SubMenuDos(l);
			break;
		case 6:
			Menu(l);
			break;
	}
}

void SubMenuTres(LISTA l)
{
	int num;
	do
	{
		system("cls");
		printf("\t\t\t\tiTunas\t\t\n\n");
		if(num<1 || num>6)
		printf("1-Mostrar Listas de Reproduccion\n2-Agregar Lista de Reproduccion\n3-Modificar Lista de Reproduccion\n4-Borrar Lista de Reproduccion\n5-Guardar Cambios\n6-Regresar\nOpc: ");
		scanf("%d",&num);
	}while(num<1 || num>6);
	switch(num)
	{
		case 1:
			system("CLS");
		printf("\t\t\t\tiTunas\t\t\n\n");
			mostrarListas(&l);
			printf("\n\n\t\tOprime una tecla perro");
			getch();
			break;
		case 2:
			system("CLS");
		printf("\t\t\t\tiTunas\t\t\n\n");
			mostrarNombresListas(&l);
			printf("\n\n\t\tOprime una tecla");
			getch();
			break;
		case 3:
			break;
		case 4:
			system("CLS");
		printf("\t\t\t\tiTunas\t\t\n\n");
			mostrarNombresListas(&l);
			eliminarLista();
			printf("\n\n\t\tOprime una tecla perro");
			getch();
			break;
		case 5:
			break;
		case 6:
			SubMenuDos(l);
			break;
	}
}
