#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.c"

void Menu(LISTA l);
void SubMenuUno(LISTA l);
void SubMenuDos(LISTA l);
void SubMenuTres(LISTA l);
void lecturaArchivo(LISTA *lista);
void guardar(LISTA *lista);
void mostrarBiblioteca(LISTA l);
void agregarCancion(LISTA l);
void modificarCancion(LISTA *l);
int buscarCancion(LISTA *l);
void borrarCancion(LISTA l);
void guardarCancion(LISTA l);
void mostrarListas(LISTA *lista);
void mostrarNombresListas(LISTA *lista);
void eliminarLista();
void busquedaFuncionId(LISTA *lista,int id);
void actualizarLista(int index);
void AgregarLista(char nom[50]);
void BuscarPaLista(LISTA *l, char bus[50]);
void AgregarALista(int ID);

////////////////////////////////////////////////////////////////////////////////////////
////									iTunas.c 									////
////																				////
////																				////
//// Programa parecido a lo que realiza el conocido reproductor musical iTunes de 	////
//// Apple, utilizando la estructura lista, se crean listas musicales, se borran 	////
//// canciones, buscan canciones, agregan canciones a las listas, etc. La 			////
//// biblioteca inicial es obtenida por un archivo donde previamente se agregaron 	////
//// canciones para comenzar.														////
//// Modificar el archivo "rolas.txt".												////
////																				////
////																				////
//// Autor: Romero Gamarra Joel Mauricio											////
////////////////////////////////////////////////////////////////////////////////////////

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

void lecturaArchivo(LISTA *lista)
{
	NODO n;
	FILE *i;
	int j,c;
	char a[TAM],let,nombre[TAM],grupo[TAM],album[TAM];
	
	i=fopen("rolas.txt","r");
	if(i==NULL)
	{
		printf("No se encontro el archivo");
		exit(1);
	}
	
	while(!feof(i))
	{
		j=0;
		fgets(a,100,i);
		c=0;
		do
		{
			let=a[j++];
			if(let!='_')
				grupo[c++]=let;
		}while(let!='_');
		grupo[c]='\0';
		strcpy(n.grupo,grupo);
		
		c=0;
		do
		{
			let=a[j++];
			if(let!='_')
				nombre[c++]=let;
		}while(let!='_');
		nombre[c]='\0';
		strcpy(n.nombre,nombre);
		
		c=0;	
		do
		{
			let=a[j++];
			album[c++]=let;
		}while(let!='\n');
		album[c-1]='\0';
		strcpy(n.album,album);	
		insertar(lista,n);
	}
	fclose(i);	
}

void guardar(LISTA *lista)
{
	FILE *i;
	NODO *actual;
	
	i=fopen("rolas.txt","w");
	if(i==NULL)
	{
		printf("Archivo no Encontrado");
		return;
	}
	
	actual=lista->inicio;
	while(actual!=NULL)
	{
		fprintf(i,"%s_%s_%s",actual->grupo,actual->nombre,actual->album);
		actual=actual->sig;
		if(actual!=NULL)
			fprintf(i,"\n");
	}
	
	printf("Cambios Guardados  :3");
	fclose(i);
}

//Funciones Biblioteca
void mostrarBiblioteca(LISTA l)
{
	system("CLS");
	fflush(stdin);
		printf("\t\t\t\tiTunas\t\t\n\n");
	verAdelante(&l);
	printf("\n\n\t\tOprimir una tecla para continuar");
	getch();
	SubMenuUno(l);
}

void agregarCancion(LISTA l)
{
	int i;
	NODO nod; 
	char nom[50], art[50], alb[50];
	
	system("CLS");
	fflush(stdin);
		printf("\t\t\t\tiTunas\t\t\n\n");
	printf("Nombre de la Cancion: ");
	gets(nom);
	fflush(stdin);
	for(i=0;nom[i]!='\0';i++)
		nom[i]=toupper(nom[i]);
	strcpy(nod.nombre,nom);
	
	printf("Nombre del Artista: ");
	gets(art);
	fflush(stdin);
	for(i=0;art[i]!='\0';i++)
		art[i]=toupper(art[i]);
	strcpy(nod.grupo,art);
	
	printf("Nombre del Album: ");
	gets(alb);
	fflush(stdin);
	for(i=0;alb[i]!='\0';i++)
		alb[i]=toupper(alb[i]);
	strcpy(nod.album,alb);
	
	nod.ant=NULL;
	nod.sig=NULL;
	insertar(&l,nod);
}

void modificarCancion(LISTA *l)
{
	NODO nod;
	int i, j=1,id, cont=0;
	char *fp;
	char nom[50], art[50], alb[50];
	
	cont=buscarCancion(l);
	fflush(stdin);

	if(cont==1)
	{
		printf("\n\nEscribir Id de la cancion: ");
		scanf("%d",&id);
		fflush(stdin);
	
		printf("Nombre de la Cancion: ");
		gets(nom);
		fflush(stdin);
		for(i=0;nom[i]!='\0';i++)
			nom[i]=toupper(nom[i]);
		strcpy(nod.nombre,nom);
	
		printf("Nombre del Artista: ");
		gets(art);
		fflush(stdin);
		for(i=0;art[i]!='\0';i++)
			art[i]=toupper(art[i]);
		strcpy(nod.grupo,art);
	
		printf("Nombre del Album: ");
		gets(alb);
		for(i=0;alb[i]!='\0';i++)
			alb[i]=toupper(alb[i]);
		strcpy(nod.album,alb);
	
		nod.sig=NULL;
		nod.ant=NULL;
		actualizar(l,&nod,id);
	}
}

int buscarCancion(LISTA *l)
{
	NODO *nod;
	int i, j=1, cont=0;
	char *fp;
	char bus[50];
	
	system("cls");
	fflush(stdin);
		printf("\t\t\t\tiTunas\t\t\n\n");
	
	printf("Escriba la palabra a buscar: ");
	gets(bus);
	for(i=0;bus[i]!='\0';i++)
		bus[i]=toupper(bus[i]);
	
	nod=l->inicio;
	printf("%-3s%-30s %-30s %-30s\n\n","ID","NOMBRE","ARTISTA","ALBUM");
	while(nod!=NULL)
	{
		fp=strstr(nod->nombre,bus);
		if(fp==NULL)
			fp=strstr(nod->grupo,bus);
		if(fp==NULL)
			fp=strstr(nod->album,bus);
		if(fp!=NULL)
		{
			printf("%-3d%-30s %-30s %-30s\n",j,nod->nombre,nod->grupo,nod->album);
			cont=1;
		}
		j++;
		nod=nod->sig;
	}
	return cont;
}

void borrarCancion(LISTA l)
{
	int i, cont;

	cont=buscarCancion(&l);
	fflush(stdin);
	
	if(cont==1)
	{
		printf("\n\nEscribir Id de la cancion: ");
		scanf("%d",&i);
		eliminar(&l,i);
	}
}

void guardarCancion(LISTA l)
{
	system("CLS");
	fflush(stdin);
	
		printf("\t\t\t\tiTunas\t\t\n\n");
	guardar(&l);	
}

//Funciones Listas de Reproduccion
void mostrarListas(LISTA *lista)
{
	FILE *i;
	int numerolistas,j,id;
	char nombre[50];
	i=fopen("listas.txt","r");
	
	if(i==NULL)
	{
		printf("No se encontro el archivo");
		exit(1);
	}
	
	while(!feof(i))
	{
		fscanf(i,"%s",nombre);
		fscanf(i,"%d",&numerolistas);
		printf("******\t%s  *******\n\n",nombre);
		printf("%-30s %-30s %-30s\n\n","ID","NOMBRE","ARTISTA","ALBUM");
		for(j=0;j<numerolistas;j++)
		{
			fscanf(i,"%d",&id);
			if(id!=0)
				busquedaFuncionId(lista,id);
		}
		printf("\n");
	}
	fclose(i);
}

void mostrarNombresListas(LISTA *lista)
{
	FILE *i;
	int numerolistas,j,id,k=1;
	char nombre[50];
	i=fopen("listas.txt","r");
	
	if(i==NULL)
	{
		printf("No se encontro el archivo");
		exit(1);
	}
	
	system("CLS");
		printf("\t\t\t\tiTunas\t\t\n\n");
			
	while(!feof(i))
	{
		fscanf(i,"%s",nombre);
		fscanf(i,"%d",&numerolistas);
		printf("Lista %d:\t%s\n\n",k++,nombre);
		for(j=0;j<numerolistas;j++)
		{
			fscanf(i,"%d",&id);
		}
	}
	fclose(i);
}

void eliminarLista()
{
	char nom[30],nombre[30];
	FILE *i,*o;
	int numerolistas,j,id,m;
	
	printf("Nombre de la LISTA: ");
	fflush(stdin);
	gets(nom);
	for(m=0;nom[m]!='\0';m++)
		nom[m]=toupper(nom[m]);

	i=fopen("listas.txt","r");
	
	if(i==NULL)
	{
		printf("No se encontro el archivo");
		exit(1);
	}
	
	REP r[30];
	int k=0;

	while(!feof(i))
	{
		fscanf(i,"%s",nombre);
		if(strcmp(nombre,nom)!=0){
			strcpy(r[k].nombre,nombre);
			fscanf(i,"%d",&numerolistas);
			r[k].numCan=numerolistas;
			for(j=0;j<r[k].numCan;j++)
			{
				fscanf(i,"%d",&id);
				r[k].id[j]=id;
			}
			k++;
		}else
		{
			fscanf(i,"%d",&numerolistas);
			for(j=0;j<numerolistas;j++)
			{
				fscanf(i,"%d",&id);
			}
		}
	}

	o=fopen("listas.txt","w");
	id=0;
	
	for(id=0;id<k;id++)
	{
		fprintf(o,"%s\n",r[id].nombre);
		fprintf(o,"%d\n",r[id].numCan);
		for(j=0;j<r[id].numCan;j++)
		{
			fprintf(o,"%d",r[id].id[j]);
			if(id+1==k && j+1==(r[id].numCan))break;
			fprintf(o,"\n");
		}
	}
	
	fclose(i);
	fclose(o);
}

void busquedaFuncionId(LISTA *lista,int id)
{
	NODO *actual;
	int i;
	
	if(id>(lista->tamanio))
	{
		printf("id no valido");
		return;
	}
	
	actual=lista->inicio;
	for(i=1;i<id;i++)
		actual=actual->sig;
	
	printf("%-30s %-30s %-30s\n",actual->nombre,actual->grupo,actual->album);
}

void actualizarLista(int index)
{
	char nom[30],nombre[30];
	FILE *i,*o;
	int numerolistas,j,id,m;
	
	i=fopen("listas.txt","r");
	
	if(i==NULL)
	{
		printf("No se encontro el archivo");
		exit(1);
	}
	
	REP r[30];
	int k=0;

	while(!feof(i))
	{
		fscanf(i,"%s",nombre);
		strcpy(r[k].nombre,nombre);
		fscanf(i,"%d",&numerolistas);
		r[k].numCan=numerolistas;
		for(j=0;j<r[k].numCan;j++)
		{
			fscanf(i,"%d",&id);
			r[k].id[j]=id;
		}
		k++;
	}
	
	int cont=0;
	for(id=0;id<k;id++)
	{
		for(j=0;j<r[id].numCan;j++)
		{
			int nc=r[id].id[j];
			if(nc==index)
			{
				r[id].id[j]=0;
				cont++;
			}
			else if(nc>index)
			{
				r[id].id[j]-=1;
			}
		}
	}

	o=fopen("listas.txt","w");
	id=0;
	
	for(id=0;id<k;id++)
	{
		fprintf(o,"%s\n",r[id].nombre);
		fprintf(o,"%d\n",r[id].numCan);
		for(j=0;j<r[id].numCan;j++)
		{
			fprintf(o,"%d",r[id].id[j]);
			if(id+1==k && j+1==(r[id].numCan))break;
			fprintf(o,"\n");
		}
	}
	
	fclose(i);
	fclose(o);
}

void AgregarLista(char nom[50])
{
	FILE *i;
	i=fopen("listas.txt","a");
	if(i==NULL)
	{
		printf("No se encontro el archivo");
		exit(1);
	}
	fprintf(i,"\n%s",nom);
	fclose(i);
}

void BuscarPaLista(LISTA *l, char bus[50])
{
	NODO *nod;
	int i, j=1,id;
	char *fp;
	char nom[50], art[50], alb[50];
	nod=l->inicio;
	printf("%-3s%-30s %-30s %-30s\n\n","ID","NOMBRE","ARTISTA","ALBUM");
	while(nod!=NULL){
		fp=strstr(nod->nombre,bus);
		if(fp==NULL)
			fp=strstr(bus,nod->grupo);
		if(fp==NULL)
			fp=strstr(bus,nod->album);
		if(fp!=NULL)
			printf("%-3d%-30s %-30s %-30s\n",j,nod->nombre,nod->grupo,nod->album);
		j++;
		nod=nod->sig;
	}
}

void AgregarALista(int ID)
{
	FILE *i;
	i=fopen("listas.txt","a");
	if(i==NULL)
	{
		printf("No se encontro el archivo");
		exit(1);
	}
	fprintf(i,"\n%d",ID);
	fclose(i);
}