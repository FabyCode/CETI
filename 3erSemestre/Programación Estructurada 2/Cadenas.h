#ifndef CADENAS_H
#define CADENAS_H

class Cadenas
{
public:
    int MiStrlen(char[]);
    int str2i(char[]);
    int CadToAltas(char[]);
    int CadInvertida(char[]);
    int BinarioADecimal(char[]);
    int CuentaVocales(char[]);
    int HtoI(char[]);
    void ItoH(char cadInt[], char cadHex[]);
    double AtoF(char s[]);
    int NumMinusculas(char[]);
    int Palabras(char[]);
    void OctalADec(char z[], int tam);
    void DecAOctal(char z[], int tam);
    long Base2ABase10(char[]);
    int stdcompara(char cad1[50], char cad2[50]);
};

#endif /* CADENAS_H */
