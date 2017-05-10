#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

void ini(LISTA *lista)
{
	lista->inicio=NULL;
	lista->fin=NULL;
	lista->tamanio=0;
}

void insertar(LISTA *lista,NODO n)
{
	NODO *temp;
	
	temp=(NODO *)malloc(sizeof(NODO));
	if(temp==NULL)
		printf("NO_MEMORY");
	*temp=n;
	
	if(vacia(lista)==1)
	{
		temp->sig=NULL;
		temp->ant=NULL;
		lista->inicio=temp;
		lista->fin=temp;
		lista->tamanio++;
	} else
	{
		temp->sig=NULL;
		temp->ant=lista->fin;
		lista->fin->sig=temp;
		lista->fin=temp;
		lista->tamanio++;
	}
}

void actualizar(LISTA *lista,NODO *n, int id)
{
	int i=1;
	NODO *actual;
	
	actual=lista->inicio;
	for(i=1;i<id;i++)
	{
		actual=actual->sig;
	}
	
	strcpy(actual->album,n->album);
	strcpy(actual->grupo,n->grupo);
	strcpy(actual->nombre,n->nombre);
}

NODO eliminar(LISTA *lista, int pos)
{
	if(vacia(lista)==1)
		return;
	
	NODO *temp,*aux;
	
	temp=(NODO *)malloc(sizeof(NODO));
	aux=(NODO *)malloc(sizeof(NODO));
	if(temp==NULL)
		printf("NO_MEMORY");
	
	if(pos==1)
	{
		temp=lista->inicio;
		free(lista->inicio);
		lista->inicio=temp->sig;
			
		if(lista->inicio == NULL)
      		lista->fin = NULL;
      	else
      		lista->inicio->ant=NULL;
	}
	else if(pos==lista->tamanio)
	{
		temp=lista->fin;
		free(lista->fin);
		lista->fin=temp->ant;
		lista->fin->sig=NULL;
	}else
	{
		int i;
		temp=lista->inicio;
		for(i=1;i<pos;i++)
			temp=temp->sig;
		aux=temp;
		
		aux->ant->sig=aux->sig;
		aux->sig->ant=aux->ant;
		free(aux);
	}
	
	lista->tamanio--;
	actualizarLista(pos);
	return *temp;
}

int vacia(LISTA *lista)
{
	if(lista->fin==NULL && lista->inicio==NULL)
		return 1;
	return 0;
}

void verAdelante(LISTA * lista)
{
	NODO *actual;
	
	actual=lista->inicio;
	printf("%-30s %-30s %-30s\n\n","NOMBRE","ARTISTA","ALBUM");
	
	while(actual!=NULL)
	{
		printf("%-30s %-30s %-30s\n",actual->nombre,actual->grupo,actual->album);
		actual=actual->sig;
	}
}

void verAtras(LISTA * lista)
{
	NODO *actual;
	
	actual=lista->fin;
	printf("%-30s %-30s %-30s\n\n","NOMBRE","ARTISTA","ALBUM");
	
	while(actual->ant!=NULL)
	{
		printf("%-30s %-30s %-30s\n",actual->nombre,actual->grupo,actual->album);
		actual=actual->ant;
	}
}

void vaciarLista(LISTA * lista)
{
	while(lista->tamanio>0)
		eliminar(lista,1);
}