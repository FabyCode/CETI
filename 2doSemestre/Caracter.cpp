#include "Caracter.h"

int Caracter::CaracterRespectom(char c)
{
    /* if(c < 'm')
        return 1;
    else
        if(c == 'm')
            return 2;
        else
            return 3; */
    return (c < 'm') ? 1 : (c == 'm') ? 2 : 3;
}

char Caracter::CaracterRespectomC(char c)
{
    /*if(c < 'm')
        return 'a';
    else
        if(c == 'm')
            return 'i';
        else
            return 'd';*/
    return (c < 'm') ? 'a' : (c == 'm') ? 'i' : 'd';
}

void Caracter::CaracterRespectomC(char c, char* r)
{
    /*if(c < 'm')
        return 'a';
    else
        if(c == 'm')
            return 'i';
        else
            return 'd';*/
    *r = (c < 'm') ? 'a' : (c == 'm') ? 'i' : 'd';
}

bool Caracter::OrdenCaracteres(char c1, char c2)
{
    if (c1 < c2)
        return true;
    else
        return false;
}
void Caracter::CaracterRespectoIM(char c, char* r)
{
    *r = (c == 'i') ? '1' : (c == 'm') ? '2' : (c < 'i') ? '3' : (c > 'm') ? '4' : '5';
}