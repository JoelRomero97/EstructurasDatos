#include <stdlib.h>
#include <stdio.h>

struct nodo{
	char L;
	struct nodo * sig;	
};
struct cabecera{
	struct nodo *I;
	struct nodo *F;
};

//ALIAS
typedef struct nodo NODO;
typedef struct cabecera CAB;
typedef NODO *lig;
typedef CAB *cola;
typedef enum b{FALSE,TRUE}booleano;
typedef enum m{NO_MEMORY, OK}mensaje;


//PROTOTIPOS
mensaje ini_cola (cola *c); 
void lib_cola (cola c); 
void borrar_cola (cola *c); 
mensaje encolar (cola c, NODO D); 
NODO desencolar (cola c); 
booleano vacia (cola c); 
