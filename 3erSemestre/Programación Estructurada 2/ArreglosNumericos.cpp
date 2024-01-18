#include "ArreglosNumericos.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

bool ArreglosNumericos::BuscaArr(int Arr[], int tam, int num)
{
    for (int i = 0; i < tam; i++)
        if (Arr[i] == num)
            return true;
    return false;
}

void ArreglosNumericos::Despliega(int Arr[], int tam)
{
    for (int i = 0; i < tam; i++)
        printf("%d\t", Arr[i]);
    printf("\n");
}

int ArreglosNumericos::DifConsecutivos(int Arr[], int tam)
{
    int diferencia = 0;
    for (int i = 0; i < tam - 1; i++)
        if (Arr[i] > Arr[i + 1])
            if ((Arr[i] - Arr[i + 1]) > diferencia)
                diferencia = Arr[i] - Arr[i + 1];
            else;
        else
            if ((Arr[i + 1] - Arr[i]) > diferencia)
                diferencia = Arr[i + 1] - Arr[i];
    return diferencia;
}

void ArreglosNumericos::LlenaArr(int* Arr, int tam)
{
    int dato;
    for (int i = 0; i < tam; i++)
    {
        printf("Dame el número %d del arreglo: ", i);
        fflush(stdout);
        scanf("%d", &dato);
        Arr[i] = dato;
    }
}

void ArreglosNumericos::AleatoriosDados(int Arr[], int tam)
{
    int tirada = 0;
    for (int i = 0; i < 19; i++)
    {
        Arr[i] = rand() % 12 + 2;
    }
}

void ArreglosNumericos::LlenaArrAleatorio(int Arr[], int tam)
{
    srand(time(NULL));
    for (int i = 0; i < tam; i++)
        Arr[i] = (((int)rand()) % 100) + 1; // del 1 al 100
}

int ArreglosNumericos::FactoresArr(int Arr[], int tam)
{
    int num;
    printf("Escribe un valor: ");
    fflush(stdout);
    scanf("%d", &num);

    for (int i = 0; i < num; i++) {
        Arr[i] = num % i;
        if (Arr[i] = 0) {
            printf("%d", Arr[i]);
        }//if
        else;
    }//for
}

/*double Mediana(const double Arr[], int Num)
{
    Num = 11;
    int Mid;
    printf("Ingresa %d números\n", &Num);
    fflush(stdout);

    for(int i = 0 ; i<Num ; i++)
    {
        scanf("%d", Arr[i]);
    }

    if(Num%2 == 0)
        {
            Mid = ((Num/2)+((Num/2)+ 1))/2;
        }
    else
        Mid = Num/2;

    printf("%d", &Mid);
}*/

int ArreglosNumericos::CorreDados(int Arr[])
{
    int tirada1 = 0;
    int tirada2 = 0;
    int tirada = 0;

    srand(time(NULL));
    for (int b = 0; b <= 11; b++)
        Arr[b] = 0;
    for (int i = 1; i <= 1000; i++)
    {
        tirada1 = (((int)rand()) % 6) + 1;
        tirada2 = (((int)rand()) % 6) + 1;
        tirada = tirada1 + tirada2;

        if (tirada == 2)
            Arr[0] += 1;
        else if (tirada == 3)
            Arr[1] += 1;
        else if (tirada == 4)
            Arr[2] += 1;
        else if (tirada == 5)
            Arr[3] += 1;
        else if (tirada == 6)
            Arr[4] += 1;
        else if (tirada == 7)
            Arr[5] += 1;
        else if (tirada == 8)
            Arr[6] += 1;
        else if (tirada == 9)
            Arr[7] += 1;
        else if (tirada == 10)
            Arr[8] += 1;
        else if (tirada == 11)
            Arr[9] += 1;
        else if (tirada == 12)
            Arr[10] += 1;
    }
    int valor = 2;
    for (int j = 0; j < 11; j++)
    {
        printf("La frecuencia de %d es %d \n", valor, Arr[j]);
        valor++;
    }
}

int ArreglosNumericos::DosMayores(int Arr[])
{
    int UnoMayor = 0, SegundoMayor = 0;
    for (int i = 0; i <= 100; i++)
    {
        if (Arr[i] > UnoMayor)
            UnoMayor = Arr[i];
        else if (Arr[i]<UnoMayor and Arr[i] > SegundoMayor)
            SegundoMayor = Arr[i];
    }
}
