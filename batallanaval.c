#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <ctype.h>
#define FALSO 0
#define VERDADERO 1

int tablero[11][11];
int tablero2[11][11];
int x_barco=0;
int y_barco=0;
int lado;

//lleno la matriz con '.'
void iniciar_tablero()
{
    for(int fila=0; fila<10; fila++)
    {
        for(int columna=0; columna<10; columna++)
            tablero[fila][columna]='.';
    }

    return;
}

void limpiar_tablero()
{
    for(int fila=0; fila<10; fila++)
        for(int columna=0; columna<10; columna++)
            if(tablero[fila][columna]==',')
                tablero[fila][columna]='.';
}

void area_barcos(int x_barco, int y_barco)
{
    for(int fila=x_barco-1; fila<= x_barco+1; fila++)
                for(int columna=y_barco-1; columna<= y_barco+1; columna++)
                    if(fila>=0 && fila <10 && columna>=0 && columna<10)
                        if(tablero[fila][columna]!='X')
                            tablero[fila][columna]=',';
}

int verificar_barcos(int contador)
{
    int verificar_barcos = VERDADERO;
    for(int verificar=0; verificar< contador; verificar++)
        {
        if(lado==0)
        {
            if(tablero[x_barco][y_barco+verificar]=='X' || tablero[x_barco][y_barco+verificar]==',')
                return FALSO;
        }

        if(lado==1)
        {
            if(tablero[x_barco+verificar][y_barco]=='X' || tablero[x_barco+verificar][y_barco]==',')
                return FALSO;
        }

        }
    return VERDADERO;
}

void ubicar_barcos()
{
    srand(time(NULL));

    int contador=5;


    for(int c=0; c<4; c++)
       {
        contador--;

       for(int c2=0; c2<c+1; c2++)
       {
          lado=rand()%2;
          if(lado==0)
          {
          do{
          x_barco= rand()%10;
          y_barco= rand()%7+c;
           }while(verificar_barcos(contador)==FALSO);

         for(int c=0; c<contador; c++)
        {
            tablero[x_barco][y_barco+c]='X';

            area_barcos(x_barco, y_barco+c);
    }
          }
    else if(lado==1)
         {
          do{
          x_barco= rand()%7+c;
          y_barco= rand()%10;
          }while(verificar_barcos(contador)==FALSO);

          for(int c=0; c<contador; c++)
           {
            tablero[x_barco+c][y_barco]='X';

            area_barcos(x_barco+c, y_barco);
           }
         }

        }
       }
       limpiar_tablero();
}

int f=0;

int norte(int fila, int columna)
{
    f=0;
    int norte=FALSO;
        while(norte==FALSO)
        {
            f++;
            printf("La casilla se mueve al norte en %d posiciones\n", f);
            if(fila-f>=0 && fila-f<10)
            {
                if(tablero[fila-f][columna]=='.' || tablero[fila-f][columna]=='-')
                {
                    norte= VERDADERO;
                }
                if(tablero[fila-f][columna]=='X')
                {
                    return FALSO;
                }
            }
            else
                norte=VERDADERO;
        }

       return VERDADERO;
}
int sur(int fila, int columna)
{
    int sur=FALSO;
    f=0;

        while(sur==FALSO)
        {
        f++;
        printf("La casilla se mueve al sur en %d posiciones\n", f);
        if(fila+f>=0 && fila+f<10)
        {
        if(tablero[fila+f][columna]=='.' || tablero[fila+f][columna]=='-')
        {
            sur= VERDADERO;
        }
        if(tablero[fila+f][columna]=='X')
        {
            return FALSO;
        }
        }

        else
            sur=VERDADERO;
        }

       return VERDADERO;
}
int este(int fila, int columna)
{
    int este=FALSO;
    f=0;
        while(este==FALSO)
        {
        f++;
        printf("La casilla se mueve al este en %d posiciones\n", f);
        if(columna+f>=0 && columna+f<10)
        {
        if(tablero[fila][columna+f]=='.' || tablero[fila][columna+f]=='-')
        {
            este= VERDADERO;
        }
        if(tablero[fila][columna+f]=='X')
        {
            return FALSO;
        }
        }

    else
        este=VERDADERO;

        }
       return VERDADERO;
}
int oeste(int fila, int columna)
{
    int oeste=FALSO;
    f=0;

    while(oeste==FALSO)
    {
        f++;
        printf("La casilla se mueve al oeste en %d posiciones\n", f);
        if(columna-f>=0 && columna-f<10)
        {
        if(tablero[fila][columna-f]=='.' || tablero[fila][columna-f]=='-')
        {
            oeste= VERDADERO;
        }
        if(tablero[fila][columna-f]=='X')
        {
            return FALSO;
        }
        }

    else
        oeste=VERDADERO;
    }

       return VERDADERO;
}
void iniciar_tablero2()
{
    int columna=10;


    for(int fila=0; fila<10; fila++)
    {
        for(int columna=0; columna<10; columna++)
            tablero2[fila][columna]='.';
    }
    for(int fila=0; fila<10; fila++)
        tablero2[fila][columna]=65+fila;

    int fila=10;

    for(columna=0; columna<10; columna++)
        tablero2[fila][columna]=1+columna;

    tablero2[10][10]=00;
}
void mostrar_tablero2()
{
    for(int fila=0; fila<11; fila++)
    {
        printf("\n");
        for(int columna=0; columna<11; columna++)
            if(fila!=10)
                printf("%c ",tablero2[fila][columna]);
            else
                printf("%d ",tablero2[fila][columna]);


    }
}

void mostrar_tablero()
{
    int columna=10;

    for(int fila=0; fila<10; fila++)
        tablero[fila][columna]=65+fila;

    int fila=10;
    for(columna=0; columna<10; columna++)
        tablero[fila][columna]=1+columna;

    tablero[10][10]=00;
    for(int fila=0; fila<11; fila++)
    {
        printf("\n");
        for(int columna=0; columna<11; columna++)
            if(fila!=10)
                printf("%c ",tablero[fila][columna]);
            else
                printf("%d ",tablero[fila][columna]);


    }

}

int hundido(int x_barco, int y_barco)
{
    int contador_hundido=0;
    for(int c=1; c<5; c++)
    {
        switch(c)
        {
            case 1:
                    if(norte(x_barco, y_barco)==VERDADERO)
                        break;
                    else
                        return FALSO;
                        break;
            case 2:
                    if(sur(x_barco, y_barco)==VERDADERO)
                        break;
                    else
                        return FALSO;
                        break;
            case 3:
                    if(este(x_barco, y_barco)==VERDADERO)
                        break;
                    else
                        return FALSO;
                        break;
            case 4:
                    if(oeste(x_barco, y_barco)==VERDADERO)
                        break;
                    else
                        return FALSO;
                        break;
        }



    }
    return VERDADERO;

}
int contador_barcos=20;

void agua_tocada(int x, int y)
{
    if(tablero[x][y]=='.')
    {
        tablero[x][y]='-';
        tablero2[x][y]='-';
        system("cls");
        printf("Agua");
    }


    if(tablero[x][y]=='X')
    {
        tablero[x][y]='O';
        tablero2[x][y]='O';
        if(hundido(x, y)==FALSO)
        {
            contador_barcos--;
             //system("cls");
             printf("Tocado");


        }

        else
            {
             contador_barcos--;
             //system("cls");
             printf("Hundido");
            }


    }
}

void sonar_vacio(char x, int y)
{
    for(int fila=x-1; fila<=x+1; fila++)
            for(int columna=y-1; columna<=y+1; columna++)
                if(fila>=0 && fila<=10 && columna>=0 && columna<=10)
                {
                    tablero[fila][columna]='-';
                    tablero2[fila][columna]='-';
                }
    return;
}

int cant_sonar=3;
void sonar(char x, int y)
{
    if(cant_sonar>0)
    {
        int sonar_barcos=0;
    for(int fila=x-1; fila<=x+1; fila++)
        for(int columna=y-1; columna<=y+1; columna++)
            if(tablero[fila][columna]=='X' || tablero[fila][columna]=='O')
                sonar_barcos++;

    system("cls");
    x=x+65;
    printf("El sonar cayo en la coordenada %c %d", x, y+1);
    printf("\nHay %d fragmentos de barcos en el area\n", sonar_barcos);

    x=x-65;
    if(sonar_barcos==0)
        sonar_vacio(x, y);

    cant_sonar--;
    }
    else
        printf("Usted ya no dispone de sonares\n");

    return;
}

void boombardeo(char x, int y)
{
    if(tablero[x][y]=='-' || tablero[x][y]=='O')
        while(tablero[x][y]=='-' || tablero[x][y]=='O')
        {
            printf("\nEsa casilla ya fue bombardeada\n");

            printf("\nIngrese una letra: ");
            scanf(" %c", &x);

            printf("Ingrese un numero: ");
            scanf(" %d", &y);

            x= toupper(x);
            y= y-1;
            x=x-65;
        }
        agua_tocada(x, y);
        return;
}

int accion;

void elegir_accion(int x, int y)
{
    printf("\n1. Boombardear");
    printf("\n2. Sonar de 3x3");
    do{
        printf("\nQue accion desea realizar: ");
        scanf(" %d", &accion);
    }while(accion!=1 && accion!=2);

    if(accion==1)
    {
        boombardeo(x, y);
    }
    else if(accion==2)
    {
        sonar(x, y);
    }

}



void pedir_coordenadas()
{
    char x;
    int y;

    do{
    mostrar_tablero2();
    int cont_errores=0;
    do{
        if(cont_errores>0)
            printf("\nEsas coordenadas no son validas");
        printf("\nVamos a ingresar coordenadas.");
        printf("\nIngrese una letra: ");
        scanf(" %c", &x);

        printf("Ingrese un numero: ");
        scanf(" %d", &y);

        x= toupper(x);
        printf("Las coordenadas ingresadas son: %c %d", x, y);

        y= y-1;
        x=x-65;
        cont_errores++;


    }while((x<0 || x>9) || (y<0 || y>9));




    elegir_accion(x, y);

    }while(contador_barcos>0);
}


int main()
{
    iniciar_tablero();
    iniciar_tablero2();
    ubicar_barcos();
    pedir_coordenadas();
    return 0;
}