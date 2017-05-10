#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "cola.c"
#include <windows.h>
#include <time.h>
#define Y_INI 5
#define Y_LIT 25

cola gen_letras(int num);
void marco(int vidas, int score, int nivel);
void gotoxy(int x,int y);
void game();

////////////////////////////////////////////////////////////////////////////////////////
////								LluviaLetras.c 									////
////																				////
////																				////
//// Lluvia de letras es un juego en el que las letras van cayendo desde la parte	////
//// superior de la pantalla hasta abajo, donde el usuario debe presionar la tecla	////
//// corresponiente en el menor tiempo posible antes de que la letra caiga por 		////
//// completo, dandole un puntaje mayor, se cuenta con 3 vidas y cuando la letra 	////
//// cae, se pierde 1 vida, además, tiene 3 niveles de dificultad.					////
////																				////
////																				////
//// Autor: Romero Gamarra Joel Mauricio											////
////////////////////////////////////////////////////////////////////////////////////////

int main(int argc, char *argv[]) 
{
	printf("\n\t\t-------Bienvenido a Lluvia de Letras-------\n\n");	
	printf("Teclee la letra correspondiente lo antes posible, 3 niveles de dificultad con 3 vidas.\n");
	printf("Presione cualquier tecla para comenzar a jugar/Presione ESC para salir\n");
	getch();
	game(); //COMIENZA EL JUEGO
	system("pause");
}

cola gen_letras(int num)
{
	cola c;
	ini_cola(&c);
	srand(time(NULL));
	NODO D;
 	int i;
	for(i=0; i<num; i++)
	{
    	D.L=('a' + rand() % (('z' - 'a') + 1));
    	encolar(c,D);
	}
	return c;
}

void marco(int vidas, int score, int nivel)
{
	gotoxy(0,0);
	printf("\n--------------------------------LLUVIA DE LETRAS--------------------------------\n\tNivel: %d \t \t Score: %d \t \t Vidas: %d \n", nivel, score, vidas);
	printf("--------------------------------------------------------------------------------\n");
}

void gotoxy(int x,int y)
{  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
}  

void game()
{
	cola letras;
	ini_cola(&letras);
   NODO D;
	int score=0;
 	int vidas=3;
 	int nivel=1;
 	int n_letras=3;  //NOS DICE LAS LETRAS QUE HABRÁ POR NIVEL
 	char LC,LT;
 	srand(time(NULL));
 	int  x,y;
 	int vel=180; //VELOCIDAD DE LA ANIMACION	
 	system("cls");
 	marco(vidas,score,nivel);
 	letras=gen_letras(n_letras);
   while(vidas>=0&&nivel<=3&& !GetAsyncKeyState(VK_ESCAPE))
   {
   	LC=desencolar(letras).L;
 		x=rand()%70;
 		for(y=Y_INI;y<Y_LIT;y++)
 		{
 		 gotoxy(x,y);
		 printf("%c",LC);
		 Sleep(vel);
		 gotoxy(x,y);
		 printf(" ");
		 if(kbhit())
			{
			 LT=getch();
			 if(LT==LC)
		  	   {
				 score +=-nivel*4*(y-35);   //FORMULA PARA SUMAR SCORE
				 marco(vidas,score,nivel);
				 if(vacia(letras))
				   {
					 if(nivel==3)
					   {
				   	 gotoxy(30,12);
				       printf("GANASTE, ERES UN CAMPEON :D\n\n\n");
						 system("pause");   //TERMINA EL JUEGO
						 }else
						 {
			 		 	  nivel++;
						  vel-=70;
						  marco(vidas,score,nivel);
						  letras=gen_letras(n_letras);
						  //goto JUEGO;
					    }
			      }
				 break;
				}else if(LT!=LC&& !GetAsyncKeyState(VK_ESCAPE))  //27=ASCII PARA ESCAPE KEY
						  {
						   vidas--;
						   marco(vidas,score,nivel);
							if(vidas>=1)
      					  {
      					   continue;
							  }else if(vidas==0)
		  				 	          {
										  gotoxy(35,12);
										  printf("PERDISTE\n\n\n");
										  system("pause");
 				  		             }
   				     }else if(GetAsyncKeyState(VK_ESCAPE))
   				     {
   				     	system("cls");
   				     	gotoxy(35,12);
   				     	printf("Has salido del juego");
   				     	exit(0);
						  }
		   }
      }
      if(y==Y_LIT)
      {
      	vidas--;
      	marco(vidas,score,nivel);
      	if(vidas>=1)
      	{
      		//continue;
			}else if(vidas==0)
			{
				gotoxy(35,12);
		  		printf("PERDISTE\n\n\n");
		  		system("pause");
			}
		}
	} 
}
