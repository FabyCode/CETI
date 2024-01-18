#include "Fechas.h"
#include <stdio.h>

Fechas::Fechas()
{
    DiasMes[0] = DiasMes[2] = DiasMes[4] = DiasMes[6] = 31;
    DiasMes[7] = DiasMes[9] = DiasMes[11] = 31;
    DiasMes[3] = DiasMes[5] = DiasMes[8] = DiasMes[10] = 30;
    DiasMes[1] = 29;
}

int Fechas::Anio(long fecha)
{
    return (int)(fecha / 10000);
}

int Fechas::Dia(long fecha)
{
    return (int)(fecha % 100);
}

bool Fechas::EsBisiesto(int anio)
{
    if((anio % 4) == 0)
        if((anio < 1589))                   // 1500
            return true;
        else
            if((anio % 100) == 0)
                if((anio % 400) == 0)       // 2000
                    return true;
                else
                    return false;           // 2100
            else
                return true;                // 2020
    else
        return false;                       // 2021
}

bool Fechas::FechaValida(long f)
{
    int a = Anio(f);
    int m = Mes(f);
    int d = Dia(f);
    if(m < 1 || m > 12)
        return false;
    if(d > DiasMes[m - 1] || d < 1)
        return false;
    if(d == 29 && m == 2 && !EsBisiesto(a))
        return false;
    return true;
}

int Fechas::Mes(long fecha)
{
    int mes;
    mes = (int)(fecha % 10000) / (int)100;
    return mes;
}

long Fechas::FechaAyer(long f)
{
    int a = Anio(f);
    int m = Mes(f);
    int d = Dia(f);
    if(d==1 and m==1)
    {
        m=12;
        a--;
        d=DiasMes[m-1];
    }
    else if(d==1){
        m=m-1;
        d=DiasMes[m-1];
    }
    else
        d=d-1;
    printf("%ld", f);
}

long Fechas::FechaMañana(long f)
{
    int a = Anio(f);
    int m = Mes(f);
    int d = Dia(f);
    if(d==31 and m==11)
    {
        m=0;
        a++;
        d=DiasMes[m-1];
    }
    else if(d==31 or d==29 or d==30){
        m=m+1;
        d=DiasMes[m+1];
    }
    else
        d=d+1;
    printf("%ld", f);
}