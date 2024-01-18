#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Juego.h"

void Juego::Adivinador()
{
    int randomizador, intento, enter, N1, o, NC, c, n;
    c = 100;
    n = 0;
    srand(time(0));
    randomizador = (((int)rand() % c) + n);
    printf("Escoge un número que esté entre el 1 y el 100 ");
    fflush(stdout);
    scanf("%d%d", &N1, &enter);
    if (N1 < 0 or N1 > 100)
    {
        do
        {
            printf("\nEscribe un número distinto que esté entre el 1 y el 100\n");
            fflush(stdout);
            scanf("%d", &N1);
        } while (N1 > 0 or N1 < 100);
    }
    while (true)
    {
        printf("\nDame un número entre el 1 y el 100 ");
        fflush(stdout);
        scanf("%d%d", &intento, &enter);
        if (intento < 0 or intento > 100)
        {
            do
            {
                printf("\nEscribe un número entre el 1 y el 100\n");
                fflush(stdout);
                scanf("%d", &intento);
            } while (intento > 0 or intento < 100);
        }

        if (intento == randomizador)
        {
            printf("\nAcertaste el número %d", randomizador);
            break;
        }
        else
            if (intento < randomizador)
                printf("\nEl caracter que estás buscando es mayor: ");
            else
                printf("\nEl caracter que estás buscando es menor: ");
        srand(time(0));
        NC = (((int)rand() % c) + n);
        printf("Tu numero es %d?", NC);
        printf("Tu numero es menor, mayor, o acerte? [1,2,3]");
        fflush(stdout);
        scanf("%d", &o);
        if (o == 1)
        {
            c = NC;
            printf("El número es menor");
            c = c - 1;
        }
        if (o == 2)
        {
            n = NC;
            printf("El número es mayor");
            n = n + 1;
        }
        if (o == 3)
        {
            printf("Vuelve a intentarlo luego");
            break;
        }
    }

}
char Juego::JuegoBalero(char c)
{

    float x;
    int y;
    double w;

    if (c == 'a')
    {
        x++;
        y = 1;
    }
    else if (c == 'b')
    {
        x = x + 5;
        y = 5;
    }
    else if (c == 'c')
    {
        x = x + 10;
        y = 10;
    }
    else if (c == 'd')
    {
        x = x + 10;
        y = 10;
    }
    else if (c == 'e')
    {
        x = x + 50;
        y = 50;
    }
    else if (c == 'f')
    {
        x = x + 100;
        y = 100;
    }
    else if (c == 'g')
    {
        x = x + 250;
        y = 250;
    }
    else if (c == 'h')
    {
        x = x + 500;
        y = 500;
    }
    else
    {
        x = 0;
    }

    printf("la jugada fue satisfactoria? 1=(si)  2=(no): ");
    fflush(stdout);
    scanf("%lf", &w);
    if (w == 2)
    {
        x = x - y;
    }
    return x;

}