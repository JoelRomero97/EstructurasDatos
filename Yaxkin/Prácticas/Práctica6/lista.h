#ifndef _LISTA_H_
#define _LISTA_H_

#define TAM 50

struct nodo
{
	char nombre[TAM];
	char grupo[TAM];
	char album[TAM];
	struct nodo *sig;
	struct nodo *ant;	
};

struct cab
{
	int tamanio;
	struct nodo *inicio;
	struct nodo *fin;
};

struct l
{
	char nombre[30];
	int numCan;
	int id[100];
};

//Redefiniciones
typedef struct nodo NODO;
typedef struct cab LISTA;
typedef struct l REP;

//funciones de lista
void ini(LISTA *lista);
void insertar(LISTA *lista,NODO n);
void actualizar(LISTA *lista,NODO *n, int id);
NODO eliminar(LISTA *lista, int pos);
void verAdelante(LISTA *lista);
void verAtras(LISTA *lista);
void vaciarLista(LISTA *lista);
int vacia(LISTA *lista);

//funciones archivo
void lecturaArchivo(LISTA *lista);
void guardar(LISTA *lista);

//funciones programa
void Menu(LISTA l);

void SubMenuUno(LISTA l);
void mostrarBiblioteca(LISTA l);
void agregarCancion(LISTA l);
void modificarCancion(LISTA *l);
int buscarCancion(LISTA *l);
void borrarCancion(LISTA l);
void guardarCancion(LISTA l);
void actualizarLista(int id);

void SubMenuDos(LISTA l);
void busquedaFuncionId(LISTA *l,int id);
void mostrarListas(LISTA *lista);
void mostrarNombresListas(LISTA *lista);
void eliminarLista();
void lecturaListas(LISTA *listas);
void SubMenuTres(LISTA l);

void BuscarPaLista(LISTA *l, char bus[50]);
void AgregarALista(int ID);
void AgregarLista(char nom[50]);
#endif
