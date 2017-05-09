#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct usb{
	char nombre [20];
	int cap;
	char file [10];
	int uso;
};

void formatear (struct usb *pt);
void cambiar_nombre(struct usb *pt);
void imprimir_propiedades(struct usb memo);

////////////////////////////////////////////////////////////////
////						Memorias.c						////
////														////
////														////
//// Estructuras definidas que representan 2 memorias USB	////
//// con nombre previamente definido, realizamos el cambio	////
//// de nombre de una de ellas, y de la otra la formateamos	////
//// al final mostrando sus nuevos atributos, es decir que	////
//// el uso cambia al igual que el nombre.					////
////														////
////														////
//// Autor: Romero Gamarra Joel Mauricio					////
////////////////////////////////////////////////////////////////

main() {
	struct usb memo;
	struct usb memo1;
	strcpy(memo.nombre,"Dark side");
	memo.cap=8;
	strcpy(memo.file,"NTFS");
	memo.uso=2;
	strcpy(memo1.nombre,"Esfera del dragon");
	memo1.cap=16;
	strcpy(memo1.file,"FAT");
	memo1.uso=8;
	printf("\n\n\tMEMORIA 1:\n\n");
	imprimir_propiedades(memo);
	printf("\n\n\tMEMORIA 2:\n\n");
	imprimir_propiedades(memo1);
	formatear(&memo1);
	cambiar_nombre(&memo);
	printf("\n\n\tMEMORIA 1:\n\n");
	imprimir_propiedades(memo);
	printf("\n\n\tMEMORIA 2:\n\n");
	imprimir_propiedades(memo1);	
	
	return 0;
}
void imprimir_propiedades(struct usb memo){
	printf("%s\n",memo.nombre);
	printf("%d GB\n",memo.cap);
	printf("%s\n",memo.file);
	printf("%d GB\n",memo.uso);
}
void formatear (struct usb *pt){
	(*pt).cap=16;
	strcpy((*pt).file,"NFTS");
	(*pt).uso=0;
}
void cambiar_nombre(struct usb *pt){
	strcpy((*pt).nombre,"Bananon");
}
