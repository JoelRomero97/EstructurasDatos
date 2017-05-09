#ifndef _cola_h_
#define _cola_h_

//Estructuras
struct nodo{
	char Doc[100];
	char pri;
	struct nodo *sig;
};
struct cabecera{
	struct nodo *i;
	struct nodo *f;
};

//Alias
typedef struct nodo NODO;
typedef struct cabecera CAB;
typedef NODO *lig;
typedef CAB *cola;

//Funciones Colas
void ini_cola(cola *c);
void liberar_cola(cola c);
void vaciar_cola(cola *c);
void encolar(cola c, NODO d);
NODO desencolar(cola c);
int vacia(cola c);


#endif
