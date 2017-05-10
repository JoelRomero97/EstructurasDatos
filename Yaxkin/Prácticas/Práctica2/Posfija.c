#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pila.c"
#define TAM 100

int prec_opr(char L,char G);
void conversion(char *inf, char *pos);
void calculo(char * pos);

////////////////////////////////////////////////////////////////////////////////////////
////									Posfija.c 									////
////																				////
////																				////
//// Evaluamos una expresión aritmética que contiene paréntesis, es decir que 		////
//// modifica la precedencia de los operadores, convirtiéndola a posfija y con 		////
//// ayuda de la estructura pila, la evaluamos, mostrando el resultado al usuario.	////
//// Modificar archivo "Oper.txt".													////
////																				////
////																				////
//// Autor: Romero Gamarra Joel Mauricio											////
////////////////////////////////////////////////////////////////////////////////////////

int main() 
{
	int h=1;
	char inf[TAM];
	char pos[TAM];
	FILE *pt=NULL;
	printf("\n\tPROGRAMA PARA CONVERTIR Y EVALUAR UNA CADENA INFIJA A POSFIJA:\n\n");
	pt=fopen("Oper.txt","r");
	while(fscanf(pt,"%s",inf)!=EOF)   //CONVERSION
	{
		printf("EXPRESION %d:\t",h);
      conversion(inf,pos);
      calculo(pos);
      printf("\n\n\n");
      h++;
    }
	return 0;
}

void conversion(char * inf, char * pos)
{
   int i=0,j=0;
	pila opr;
	NODO D;
	ini_pila(&opr);
	int pre=0;
	while(inf[i]!='\0')
	{
	
			 if (inf[i]>='0'&&inf[i]<='9')  //ES UN NUMERO
			 {
			 
				pos[j++]=inf[i++];
				
			 } else if ( inf[i] == '(' )   //PARENTESIS QUE ABRE
			 {
			 		    
				     D.op=inf[i++];
				     push(&opr,D);
			 			 
			 } else if (inf[i] == '+'||inf[i] =='-'|| inf[i] =='*'||inf[i] == '/') //OPERADOR
			 {
			 
			     if ( empty(opr) )  //PRIMER OPERADOR
				   {
				     D.op=inf[i++];
				     push(&opr,D);
				   } else 
					{ // 1
				   	    pre=prec_opr(inf[i],top(opr).op);
				   	   	if(pre==1)  //LEIDO < GUARDADO
					    {   
		   			    while(!empty(opr)&&top(opr).op!='(')
							 {
	   			    	    pos[j++]=pop(&opr).op;
						    }
  				        D.op=inf[i++];
  				        push(&opr,D);
  				       }else if(pre==2)  //LEIDO = GUARDADO
	 		 		 	  {   
   		 			   pos[j++]=pop(&opr).op;
				  			D.op=inf[i++];
  				    		push(&opr,D);
					     }else if(pre==3)  //LEIDO > GUARDADO
  		  		  		     { 
       	 	  	 			   D.op=inf[i++];
	  		        				push(&opr,D);
					    	  }
				   	   
				   	
				   } // else 1
					
			} // IF operador
			
			else if ( inf[i] == ')' )  //PARENTESIS QUE CIERRA
			{
			   while(!empty(opr)&&top(opr).op!='(')
			   {
				 	pos[j++]=pop(&opr).op;
			   }
				 pop(&opr).op;
								
			   i++;
		   }
		 	
	}//WHILE
	while(!empty(opr))
	{
		pos[j++]=pop(&opr).op;
	}
	pos[j]='\0';
	puts(pos);	
} // pos2inf

int prec_opr(char L,char G)
{
   int l,g;
	if(L=='+'||L=='-')
	{
		l=1;
	}else if(L=='*'||L=='/')
	{
		l=2;
	}
	if(G=='+'||G=='-')
	{
 	   g=1;
	}else if(G=='*'||G=='/')
	{
 	  g=2;
	}
	if(l-g==0)
	    return 2;
	if(l-g<0)
        return 1;
    return 3;
}

void calculo(char * pos)
{
		char c[10];
		int i=0;
		float a1=0;
		float a2=0;
		float x=0;
		pila opr;
		NODO D;
	do
	{
		if(pos[i]>='0' && pos[i]<='9')
		{
			c[0]=pos[i];
    		D.num=atoi(c);
    		push(&opr,D);
		}
		if (pos[i] == '+'|| pos[i] == '-'|| pos[i] == '*'|| pos[i] == '/')
		{
			if (pos[i] == '+')
			{
				a2=pop(&opr).num;
				a1=pop(&opr).num;
				x=(a1+a2);
				D.num=x;
				push (&opr, D);
			}
			if (pos[i] == '-')
			{
				a2=pop(&opr).num;
				a1=pop(&opr).num;
				x=(a1-a2);
				D.num=x;
				push (&opr, D);
			}
			if (pos[i] == '*')
			{
				a2=pop(&opr).num;
				a1=pop(&opr).num;
				x=(a1*a2);
				D.num=x;
				push (&opr, D);
			}
			if (pos[i] == '/')
			{
				a2=pop(&opr).num;
				a1=pop(&opr).num;
				if(a2==0)
				{
					x=111;
					break;
				}else
				{
					x=(a1/a2);
					D.num=x;
					push (&opr, D);
				}
			}
		}
		i++;
	}while(pos[i]!=00);
	if(x==111)
	{
		printf("El resultado es una indeterminacion\n");
	}else
	{
		x=pop(&opr).num;
		printf("El resultado de la expresion es: %.2f\n", x);
	}
}
