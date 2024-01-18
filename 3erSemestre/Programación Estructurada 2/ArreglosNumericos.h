#ifndef ARREGLOSNUMERICOS_H
#define ARREGLOSNUMERICOS_H

#define TAMARREGLO 10

class ArreglosNumericos {
public:
    bool BuscaArr(int Arr[], int tam, int num);
    void Despliega(int Arr[], int tam);
    int  DifConsecutivos(int Arr[], int tam);
    void LlenaArr(int Arr[], int tam);
    void LlenaArrAleatorio(int Arr[], int tam);
    void AleatoriosDados(int Arr[], int tam);
    int TresMayoresArr(int Arr[], int tam);
    int FactoresArr(int Arr[], int tam);
    void DespliegaFactores(int DArr[], int tam);
    double Mediana(const double Arr[], int Num);
    int CorreDados(int Arr[]);
    int DosMayores(int Arr[]);

};

#endif /* ARREGLOSNUMERICOS_H */