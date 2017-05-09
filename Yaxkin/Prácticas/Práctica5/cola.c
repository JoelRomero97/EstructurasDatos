#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cola.h"

void ini_cola(cola *c){
	cola temp;
	temp=(cola)malloc(sizeof(CAB));
	if(temp==NULL){
		printf("\n\nMEMORIA NO DISPONIBLE\n");
		exit(1);
	}
	temp->i=temp->f=NULL;
	*c=temp;
}
void liberar_cola(cola c){
	while(vacia(c)==0)
		desencolar(c);
}
void vaciar_cola(cola *c){
	liberar_cola(*c);
	free(*c);
	*c=NULL;
}
int vacia(cola c){
	if(c->i==NULL && c->f==NULL)
		return 1;
	return 0;
}
void encolar_pri(cola c,NODO d){
	lig n, a1, a2;
	n=(lig)malloc(sizeof(NODO));
	if(n==NULL){
		printf("\n\nMEMORIA NO DISPONIBLE\n");
		exit(1);
	}
	strcpy(n->Doc,d.Doc);
	n->pri=d.pri;
	n->sig==NULL;
	if(vacia(c))
		c->i=c->f=n;
	else{
		if(d.pri>c->i->pri){
			n->sig=c->i;
			c->i=n;
		}
		else{
			if(d.pri<=c->f->pri){
				n->sig=NULL;
				c->f->sig=n;
				c->f=n;
			}
			else{
				a1=c->i;
				a2=c->i->sig;
				while(a2->pri>=d.pri){
					a1=a1->sig;
					a2=a2->sig;
				}
				n->sig=a2;
				a1->sig=n;
			}
		}
	}
}
NODO desencolar(cola c){
	NODO temp;
	if(vacia(c)==1){
		printf("\nCola Vacia\n");
		return;
	}
	else{
		temp=*(c->i);
		if(c->i->sig==NULL){
			free(c->i);
			c->i=c->f=NULL;
		} 
		else{
			free(c->i);
			c->i=temp.sig;
			temp.sig=NULL;
		}
		return temp;
	}
}


