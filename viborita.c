#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

#define W 22
#define H 22
#define TABLERO '*'
#define ESPACIO ' '
#define MANZANA 'O'
#define BANANA 'j'
#define GOOOOOD 169
#define ESC 27
#define CABEZA 254
#define CUERPO 'x'
#define VERDADERO 1
#define FALSO 0


int posicionCabeza[2];
int ManzanaPosicion[2];
int BananaPosicion[2];
int GooodPosicion [2];
int puntuacion;
int colaPosicionX[484], colaPosicionY[484];
int longCola;
int Velocidad = 50;
int serpienteDireccion2;

enum direccionEnum { Parar = 0, Izquierda = -2, Derecha = 2, Arriba = 1, Abajo = -1 };
enum direccionEnum serpienteDireccion;

int fin = FALSO;

void iniciarVariables()
{
    ManzanaPosicion[0]= rand() % W;
    ManzanaPosicion[1]= rand() % H;
    posicionCabeza[0]=W/2;
    posicionCabeza[1]=H/2;
    puntuacion = 0;
    serpienteDireccion = Parar;
}
void saltoLinea()
{
    printf("\n");
}
int comprobacion(){
    if(serpienteDireccion*-1 == serpienteDireccion2 )
        return 1;
    return 0;
}
COORD hola;

void mostrarJuego()
{
    hola.X = 0;
    hola.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),hola);

	for (int i = 0; i < W + 2; i++)
	{
		printf("%c", TABLERO);
	}
	saltoLinea();

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (j == 0)
				printf("%c",TABLERO);

			if (j == posicionCabeza[0] && i == posicionCabeza[1])
				printf("%c",CABEZA);

			else if (j == ManzanaPosicion[0] && i == ManzanaPosicion[1])
				printf("%c",MANZANA);

            else if (j == BananaPosicion[0] && i == BananaPosicion[1] && puntuacion>=100){
                        BananaPosicion[0]= rand() % W;
                        BananaPosicion[1]= rand() % H;
                        printf("%c",BANANA);
            }


            else if (j == GooodPosicion[0] && i == GooodPosicion[1] && puntuacion>=150){
                GooodPosicion[0]= rand() % W;
                GooodPosicion[1]= rand() % H;
                Velocidad = 25;
				printf("%c",GOOOOOD);
            }
			else
			{
				int printCola = FALSO;

				for (int k = 0; k < longCola; k++)
				{

					if (colaPosicionX[k] == j && colaPosicionY[k] == i)
					{
						printf("%c",CUERPO);
						printCola = VERDADERO;
					}
				}

				if (!printCola)
					printf("%c",ESPACIO);
			}

			if (j == W - 1)
				printf("%c",TABLERO);
		}

		saltoLinea();
	}
	for (int i = 0; i < W + 2; i++)
	{
		printf("%c",TABLERO);
	}

	saltoLinea();
	saltoLinea();

	printf("Puntuacion: %d", puntuacion);
	saltoLinea();
}

void teclas()
{
	if (_kbhit())
	{
		serpienteDireccion2 = serpienteDireccion;
		switch (_getch())
		{
		case 'a':
			serpienteDireccion = Izquierda;
			break;
		case 'd':
			serpienteDireccion = Derecha;
			break;
		case 'w':
			serpienteDireccion = Arriba;
			break;
		case 's':
			serpienteDireccion = Abajo;
			break;
        case 'A':
			serpienteDireccion = Izquierda;
			break;
		case 'D':
			serpienteDireccion = Derecha;
			break;
		case 'W':
			serpienteDireccion = Arriba;
			break;
		case 'S':
			serpienteDireccion = Abajo;
			break;
        case ESC:
			fin = VERDADERO;
			break;
		}
	}
}
void juego()
{
	int colaPosicionAnteriorX = colaPosicionX[0];
	int colaPosicionAnteriorY = colaPosicionY[0];
	int colaPosicionAnterior2X, colaPosicionAnterior2Y;

	colaPosicionX[0] = posicionCabeza[0];
	colaPosicionY[0] = posicionCabeza[1];

	for (int i = 1; i < longCola; i++)
	{
		colaPosicionAnterior2X = colaPosicionX[i];
		colaPosicionAnterior2Y = colaPosicionY[i];

		colaPosicionX[i] = colaPosicionAnteriorX;
		colaPosicionY[i] = colaPosicionAnteriorY;

		colaPosicionAnteriorX = colaPosicionAnterior2X;
		colaPosicionAnteriorY = colaPosicionAnterior2Y;
	}

	switch (serpienteDireccion)
	{
	case Parar:
		break;

	case Izquierda:
            posicionCabeza[0]--;


		break;

	case Derecha:
		posicionCabeza[0]++;
		break;

	case Arriba:
		posicionCabeza[1]--;
		Sleep(10);
		break;

	case Abajo:
		posicionCabeza[1]++;
		Sleep(10);
		break;
	}

	if (posicionCabeza[0] >= W || posicionCabeza[0] < 0 ||posicionCabeza[1] >= H || posicionCabeza[1] < 0)
		fin= VERDADERO;


	for (int i = 0; i < longCola; i++)
	{
		if (colaPosicionX[i] == posicionCabeza[0] && colaPosicionY[i] == posicionCabeza[1])
			fin = VERDADERO;
	}


	if ((posicionCabeza[0] == ManzanaPosicion[0] && posicionCabeza[1] == ManzanaPosicion[1]))
	{
            puntuacion += 10    ;

            ManzanaPosicion[0] = rand() % W;
            ManzanaPosicion[1] = rand() % H;

            longCola++;
	}
    if ((posicionCabeza[0] == BananaPosicion[0] && posicionCabeza[1] == BananaPosicion[1]))
    {
            puntuacion += 25;

            BananaPosicion[0] = rand() % W;
            BananaPosicion[1] = rand() % H;

            longCola++;
    }
     if ((posicionCabeza[0] == GooodPosicion[0] && posicionCabeza[1] == GooodPosicion[1]))
    {
            fin=VERDADERO;
    }
}

int main()
{
	srand(time(0));

	iniciarVariables();

	while (!fin)
	{
		mostrarJuego();
		Sleep(Velocidad);
		teclas();
		juego();
	}

	printf("Perdiste TONTO :D");
	saltoLinea();

	return 0;
}