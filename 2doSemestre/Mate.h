#ifndef MATE_H
#define MATE_H

class Mate
{
public:
    long   Abs(long num);
    void   Abs(long num, long* abs);
    float  AreaCirculo(float radio);
    float  AreaCuadrado(float lado);
    float  AreaOctaedro(float areaLado);
    double AreaTetraedro(double areaLado);
    double AreaTriangulo(double base, double altura);
    float  Inverso(float num);
    void   Inverso(float num, float* inv);
    void   MenorYMayorDe5(int n1, int n2, int n3, int n4, int n5, int* men, int* may);
    bool   NumIgualSuma(int n1, int n2, int n3);
    void   Operaciones(float n1, float n2, float* suma, float* resta,
        float* multiplicacion, float* division);
    void   ParesEntreNums(int num1, int num2);
    int    PositivosDe20();
    void Impares(int num1);
    float SumaYMedia(int n);
    int Pares(int n);
    void Estadistico(float* f);
    void Divisores(int n);
    double PromedioHasta0();
    void TresRango();
};

#endif /* MATE_H */