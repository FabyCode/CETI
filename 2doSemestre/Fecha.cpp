#include "Fecha.h"

int Fecha::Anio(long f)
{
    int a;
    a = (int)(f / 10000);
    return a;
}

int Fecha::Dia(long f)
{
    int d;
    d = (int)f % (int)100;
    return d;
}

int Fecha::Mes(long f)
{
    int m;
    m = (int)((f % 10000) / 100);
    return m;
}

/*Fecha::bisiesto(int anio)
{
    if(anio % 4 == 0)
        if(anio <= 1582)
            return true;
        else
            if(anio %100 == 0)
                if(anio % 400 == 0)
                    return true;
                else
                    return false;
            else
                return true;
    else
        return false;
}*/