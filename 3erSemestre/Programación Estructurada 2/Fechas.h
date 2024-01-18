#ifndef FECHAS_H
#define FECHAS_H

class Fechas 
{
private:
    int DiasMes[12];
public:
    Fechas();
    int  Anio(long);
    int  Dia(long);
    bool EsBisiesto(int);
    bool FechaValida(long);
    int  Mes(long);
    long FechaAyer(long);
    long FechaMañana(long);
};

#endif /* FECHAS_H */
