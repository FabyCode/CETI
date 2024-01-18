#include "Conversion.h"

double Conversion::KilometrosAMillas(double Kilometros)
{
    double Millas;
    Millas = Kilometros * 1.609;
    return Millas;
}

double Conversion::LibrasAKilos(double Libras)
{
    double kilos;
    kilos = Libras * 0.453592;
    return kilos;
}