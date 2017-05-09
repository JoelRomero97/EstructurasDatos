#include <stdlib.h>
#include <stdio.h>
#include <string.h>

////////////////////////////////////////////////////////////////////////
////                         Recursividad.c							////
////																////
////																////
//// En el siguiente programa, practicamos la recursividad para     ////
//// la solución de distintos problemas propuestos, algunos con     ////
//// solución iterativa, y otros no, como son las Torres de Hanoi.	////
////																////
////																////
//// Autor: Romero Gamarra Joel Mauricio                    		////
////////////////////////////////////////////////////////////////////////

long facr(int N);
long faci(int N);
long fibr(int N);
long fibi(int p);
long fib_i (int N);
long fib (int *A, int N);
void TH(int N, char O, char A, char D);
int e(char *c,int I,int F);
int t(char *c,int I,int F);
int f(char *c,int I, int F);
int buscarsigno(char *c,int I,int F,char a);


int main(){
	int a, resp, N, I, F, p, x;
	int V[100000],i;
	long n;
	char c[80], signo, A='A', O='O', D='D';
	printf("\n\t\t\t\tMenu Principal\n\n\n\n");
	printf("\t1. Factorial de un numero Iterativo\n");
	printf("\t2.Factorial de un numero Recursivo\n");
	printf("\t3. Serie fibonacci iterativo\n");
	printf("\t4. Serie fibonacci recursivo\n");
	printf("\t5. Serie fibo recursivo con arreglo\n");
	printf("\t6. Torres de Hanoi\n");
	printf("\t7. Gramatica\n");
	printf("\t8. Salir\n");	
	menu:
	scanf ("%d",&a);
	switch (a){
		case 1:
			printf ("ingrese el numero que desee calcular\n");
			scanf ("%d",&N);
			n=faci(N);
			printf ("%ld", n);
			break;
		case 2:
			printf ("ingrese el numero que desee calcular\n");
			scanf ("%d",&N);
			n=facr(N);
			printf("%ld", n);
			break;
		case 3:
			printf ("ingrese el numero de la posicion de la serie que desee saber\n");
			scanf ("%d",&N);
			n=fibi(N);
			printf("%ld", n);
			break;
		case 4:
			printf ("ingrese el numero de la posicion de la serie que desee saber\n");
			scanf ("%d",&N);
			n=fibr(N);
			printf("%ld", n);
			break;
		case 5:
			printf("Introduce un valor:\n ");
			scanf("%d",&x);
			n=fib_i(x);
			printf("La sucesion de Fibonacci del numero %d es %ld\n",x,n);
			break;
		case 6:
			printf ("ingrese el numero de discos para las torres de hanoi\n");
			scanf ("%d",&N);
			TH(N, O, A, D);
			break;
		case 7:
			printf ("ingrese la expresion a analizar\n");
			scanf("%s", c);
			if (e(c,0,strlen(c)-1)){
				puts("Esta bien escrito\n");
			}else{
				puts("Esta mal escrito\n");
			}break;
		case 8:
			exit(0);
			break;
	}
}

long facr(int N){
	if (N==0 || N==1)
	   return 1;
    return facr (N-1)*N; 
}

long faci(int N){
	int n=1, x=1;
	for (n=1;n<=N;n++)
		x=x*n;
	return x;
}


long fibr(int N){
	if(N==1 || N==0)
    	return N;
    if(N<-1)
 	  	return N;
 	int x= fibr(N-1);  	
    return x + fibr(N-2);
}

long fib_i (int N)
{
	int A[N+1];
	int i;
	A[0]=0;
	A[1]=1;
	for (i=2; i<=N; i++)
	A[i]= -1;
	return fib (A, N);
}

long fib (int *A, int N)
{
	if (N==0||N==1)
		return N;
	if (A[N]>-1)
		return A[N];
	A[N-1]= fib (A, N-1);
	return A[N-1] + fib (A, N-2);
}

long fibi(int p){
	int n1=1, n2=0, i, N;
	for (i=0; i<p-1; i++ ){
		N=n1+n2;
		n2=n1;
		n1=N;
	}
	return N;
}

void TH(int N, char O, char A, char D){
	if(N==1){
		printf ("Mover disco %d de %c a %c \n", N, O, D);
	}else{
		TH(N-1, O, D, A);
		printf ("Mover disco %d de %c a %c \n", N, O, D);
		TH(N-1, A, O, D);
	}
}

int e(char *c,int I,int F)//e
{
	int p;
	if(t(c,I,F))
	return 1;
	p=buscarsigno(c,I,F,'+');
	if (p>0 && f(c,I,p-1) && f(c,p+1,F))
	return 1;
	return 0;
}
int t(char *c,int I,int F)//t
{
	int p;
	if(f(c,I,F)){
	return 1;}
	p=buscarsigno(c,I,F,'*');
	if (p>0 && f(c,I,p-1) && f(c,p+1,F)){
	return 1;}
	return 0;
}
int f(char *c,int I, int F)
{
	if(I==F && c[I]>='A' && c[I]<='Z')
	return 1;
	if(c[I]=='(' && e(c,I+1,F-1) && c[F]==')')
	return 1;
	return 0;
}
int buscarsigno(char *c,int I,int F,char a)
{ 	
    int flag=0;
	int i;
	if(c[I]=='(' && c[F]==')')
	return 0;
	for(i=I;i<F;i++)
	{
	    if(c[i]=='(')
		{
		flag++;
		}
		if(c[i]==')')
		{
		flag--;
		}
		if(c[i]==a && flag==0)
		{
		return i;
		}
	}
	return 0;
}
