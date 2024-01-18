#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Juego.h"

char Juego::JuegoBalero(char c)
{

    float x;
    int y;
    double w;

        if(c=='a')
        {
            x++;
            y=1;
        }
        else if(c=='b')
        {
            x=x+5;
            y=5;
        }
        else if(c=='c')
        {
            x=x+10;
            y=10;
        }
        else if(c=='d')
        {
            x=x+10;
            y=10;
        }
        else if(c=='e')
        {
            x=x+50;
            y=50;
        }
        else if(c=='f')
        {
            x=x+100;
            y=100;
        }
        else if(c=='g')
        {
            x=x+250;
            y=250;
        }
        else if(c=='h')
        {
            x=x+500;
            y=500;
        }
        else
        {
            x=0;
        }

            printf("la jugada fue satisfactoria? 1=(si)  2=(no): ");
            fflush(stdout);
            scanf("%lf",&w);
            if(w==2)
            {
                x=x-y;
            }
    return x;

}