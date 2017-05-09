#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cola.h"

////////////////////////////////////////////////////////////////////////
////                         ColaImpresion.c						////
////																////
////																////
//// Se simula una cola de impresi�n, donde contamos con una cola   ////
//// de prioridad, en la que, la prioridad m�s alta se inserta      ////
//// al frente de la cola, y si ya hay esa prioridad, se forma en	////
//// el lugar indicado.												////
////																////
////																////
//// Autor: Romero Gamarra Joel Mauricio                    		////
////////////////////////////////////////////////////////////////////////

int main(int argc, char *argv[]) 
{
	int o=0,cont=0,prioridad,p=0; 
	cola l;
	NODO n;
	char remitente[30];
	ini_cola(&l);
	while(o!=3)
	{
		system("cls");
		if(cont!=5){
			printf("Introduce tu una opcion\n1.- Imprimir Documento\n2.- Iniciar Impresion\n3.- Salir\n");
			scanf("%d",&o);
			switch(o)
			{
				case 1:
					printf("Quien manda el documento: ");scanf("%s",remitente);
					printf("Prioridad del remitente: ");scanf("%d",&prioridad);
					strcpy(n.Doc,remitente);
					n.pri=prioridad;
					encolar_pri(l,n);
					cont++;
					break;
				case 2:
					while(vacia(l)==0){
						n=desencolar(l);
						printf("%s->",n.Doc);
					}
					p=9;
					break;
				default:
					break;
			}
			if(p==9)break;
		}
		else
		{
			while(vacia(l)==0)
			{
				n=desencolar(l);
				printf("%s->",n.Doc);
			}
			break;
			
		}
	}
	system("PAUSE>nul");
	return 0;
}



