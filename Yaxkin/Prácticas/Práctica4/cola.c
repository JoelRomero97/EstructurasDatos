#include "Cola.h"

mensaje ini_cola (cola *c){
		cola temp;
		temp=(cola)malloc(sizeof(CAB));
		if(temp==NULL)
			return NO_MEMORY;
		temp->I=temp->F=NULL;
		*c=temp;
		return OK;
}
	
void lib_cola (cola c){
		while(!vacia(c))
		{
		 desencolar(c);			
		}
}
	
void borrar_cola (cola *c){
	lib_cola(*c);
	free(*c);
	*c=NULL;
}
	
booleano vacia (cola c){
		if(c->I==NULL && c->F==NULL)
			return TRUE;
		return FALSE;
}
	
mensaje encolar (cola c, NODO D){
	lig temp;
	temp=(lig)malloc(sizeof(CAB));
	if(temp==NULL)	{				
		return NO_MEMORY;
	}			
	*temp=D;
	temp->sig=NULL;
	if(vacia(c)){
		c->I=c->F=temp;
	}
	else{
		c->F->sig=temp;
		c->F=temp;
	}
		return OK;
}
	
NODO desencolar (cola c){
	NODO temp;
	if (vacia(c)){		
		exit(0);
	}	
	else{
		temp =*(c->I);
		if(c->I->sig==NULL){
			free(c->F);
			c->I=c->F=NULL;
		}
		else{
			free (c->I);
			c->I=temp.sig;
		}
	}
	temp.sig=NULL;
		return temp;
}
