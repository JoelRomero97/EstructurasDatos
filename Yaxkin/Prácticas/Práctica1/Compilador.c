#include <stdio.h>
#include <stdlib.h>
#include "pila.c"

void leer(FILE *pt);

////////////////////////////////////////////////////////////////////////////////////////
////								Compilador.c 									////
////																				////
////																				////
//// Este programa analiza el correcto balanceo de los paréntesis con ayuda del 	////
//// manejo de archivos, de donde se obtienen los paréntesis a analizar, todos los	////
//// demás símbolos no los toma en cuenta el programa, más que paréntesis, llaves	////
//// y corchetes. Nos indica el tipo de error que tenemos y en que línea está.		////
//// Modificar archivos "1.txt", "2.txt", "3.txt" y "4.txt".						////
////																				////
////																				////
//// Autor: Romero Gamarra Joel Mauricio											////
////////////////////////////////////////////////////////////////////////////////////////

int main() {
	int resp;
	FILE *pt;
	printf("\n\n\t\t\tMENU\n\n\n");
	printf("1.Analizar 1.c\n");
	printf("2.Analizar 2.c\n");
	printf("3.Analizar 3.c\n");
	printf("4.Analizar 4.c\n");
	printf("5.Salir\n");
	scanf("%d",&resp);
	switch(resp){
		case 1: printf("\n\n\n\nPrimer Archivo:\n\n");
		pt=fopen("1.c","r");
		leer(pt);
		break;
		case 2: printf("\n\n\n\nSegundo Archivo:\n\n");
		pt=fopen("2.c","r");
		leer(pt);
		break;
		case 3: printf("\n\n\n\nTercer Archivo:\n\n");
		pt=fopen("3.c","r");
		leer(pt);
		break;
		case 4: printf("\n\n\n\nCuarto Archivo:\n\n");
		pt=fopen("4.c","r");
		leer(pt);
		break;
		case 5: system ("pause");
		exit(0);
		break;
	}
	
	return 0;
}
void leer(FILE *pt){
	int linea=1;
	char c;
	pila s;
	NODO D;
	ini_pila(&s);
	c=fgetc(pt);
	while (c!=EOF){
			
		switch (c){
			case '(' : case '[' : case '{':
				D.LL=c;
				D.Lg=linea;
				push(&s,D);
				break;
			case ')' : case ']' : case '}':
				if(empty(s)){
					printf("\n\nFalta signo de apertura en la linea\t %d\n\n",linea);
					system("pause");
					exit(0);
					break;
				} else {
					D=top(s);
					if((D.LL=='{'&&c=='}')||(D.LL=='['&&c==']')||(D.LL=='('&&c==')'))
					pop(&s);
					else{
					
					printf("\n\nError de correspondencia en la linea\t %d\n\n",linea);
					system("pause");
					exit(0);
				   }
				}
				break;
			case '\n': linea ++;
				
				
		}//SWITCH
		
	  c=fgetc(pt);	
	} // WHILE
	if(empty(s)){
		printf("\n\nArchivo balanceado\n");
	}
	else {
		printf("\n\nError, falta signo de cierre en la linea %d\n\n",s->Lg);
		system("pause");
		exit(0);
	}
	fclose(pt);
	printf("\n\n\n");
	system ("pause");	
}
