#include "Mate.h"

#include <math.h>
#include <stdio.h>

long Mate::Abs(long num)
{
    long abs = (num < 0) ? num * -1 : num;
    return abs;
}

void Mate::Abs(long num, long* abs)
{
    if (num < 0)
        *abs = num * -1;
    else
        *abs = num;
}

float Mate::AreaCirculo(float radio)
{
    float area;
    area = 3.14159 * radio * radio;
    return area;
}

float Mate::AreaCuadrado(float lado)
{
    float area = lado * lado;
    return area;
}

float Mate::AreaOctaedro(float areaLado)
{
    float area;
    area = 2 * (areaLado * areaLado) * (float)sqrt(3.0);
    return area;
}

double Mate::AreaTetraedro(double areaLado)
{
    double area;
    area = pow(areaLado, 2) * sqrt(3.0);
    return area;
}

double Mate::AreaTriangulo(double base, double altura)
{
    return (base * altura) / 2.0;
}

float Mate::Inverso(float num)
{
    float inv = 0.0;
    if (num != 0.0)
        inv = (float)1.0 / num;
    return inv;
}

void Mate::Inverso(float num, float* inv)
{
    if (num != 0.0)
        *inv = (float)1.0 / num;
    else
        *inv = 0.0;
}

void Mate::MenorYMayorDe5(int n1, int n2, int n3, int n4, int n5, int* men, int* may)
{
    *men = (n1 < n2) ? n1 : n2;
    if (n3 < *men)
        *men = n3;
    if (n4 < *men)
        *men = n4;
    if (n5 < *men)
        *men = n5;
    *may = (n1 > n2) ? n1 : n2;
    if (n3 > *may)
        *may = n3;
    if (n4 > *may)
        *may = n4;
    if (n5 > *may)
        *may = n5;
}

bool Mate::NumIgualSuma(int n1, int n2, int n3)
{
    if ((n1 == (n2 + n3)) || (n2 == (n1 + n3)) || (n3 == (n1 + n2)))
        return true;
    else
        return false;
}

void Mate::Operaciones(float n1, float n2, float* suma, float* resta,
    float* multiplicacion, float* division)
{
    printf("\nLa variable resta tiene el nombre resta, el tipo apuntador a float, el valor %x", resta);
    printf("\ntiene una longitud de 4 bytes (porque es apuntador a float) y una dirección %x", &resta);
    *suma = n1 + n2;
    *resta = n1 - n2;
    *multiplicacion = n1 * n2;
    *division = n1 / n2;
    n1 = n2 = 0;
}

void Mate::ParesEntreNums(int num1, int num2)
{
    if (num1 > num2)
        return;
    if (num1 % 2 == 1)
        num1++;
    for (int i = num1; i <= num2; i += 2)
    {
        printf("%d\t", i);
        if (i % 32 == 0)
            printf("\n");
    }
}

int Mate::PositivosDe20()
{
    int num, positivos = 0;
    for (int i = 1; i <= 20; i++)
    {
        printf("Dame el siguiente número [%d]: ", i);
        fflush(stdout);
        scanf("%d", &num);
        if (num > 0)
            positivos++;
    }
    return positivos;
}
void Mate::Impares(int num1)
{
    int h = 0;
    for (int i = 0; i <= num1; i += 1)
    {
        if (i % 2 == 1)
        {
            printf("\n");
            printf("%d", i);
            h = h + i;
        }
    }
    printf("\n%d", h);
}
float Mate::SumaYMedia(int n)
{
    int num, suma = 0, promedio = 0;
    for (int i = 1; i <= 200; i++)
    {
        printf("Dame el siguiente número [%d]: ", i);
        fflush(stdout);
        scanf("%d", &num);
        suma = suma + num;
    }
    return suma;
}
int Mate::Pares(int n)
{
    int i;
    printf("Dame cualquier número par entre el 100 y el 200 ");
    fflush(stdout);
    scanf("%d", &n);
    printf("Los números pares entre %d y 200 son: ", n);
    for (int i = n; i <= 200; i = i + 2)
    {
        printf("%d ", n);
        fflush(stdout);
        n = n + 2;
    }
    return 0;
}
void Mate::Estadistico(float* f)
{
    int a = 2;
    //float z[a];
    float z[2];
    for (int i = 0;i <= a;i++)
    {
        printf("inserte el numero %d: ", i);
        fflush(stdout);
        scanf("%f", &z[i]);
        if (z[i] > z[i - 1])
        {
            f[1] = z[i];
        }
        else
        {
            f[0] = z[i];
        }
        f[2] += z[i];
        f[4] = i;
    }
    f[4]++;
    f[3] = f[2] / f[4];
}
void Mate::Divisores(int n)
{
    int c;
    c = 1;
    while (true)
    {
        if (0 == n % c)
        {
            printf("Tu número se puede dividir entre %d\n", c);
            if (n == c)
            {
                break;
            }
        }
        c = c + 1;
    }
}
double Mate::PromedioHasta0()
{
    int i = 0;
    float  h = 0;
    while (true)
    {
        float a[i];
        i++;
        printf("Anota un número del que quieras sacar el promedio:", i);
        fflush(stdout);
        scanf("%f", &a[i]);
        if (a[i] == 0)
        {
            i = i - 1;
            break;
        }
        h = h + a[i];

    }
    h = (h / i);
    printf("EL PROMEDIO ES: %lf", h);
}
void Mate::TresRango()
{
    int Quince = 0;
    int EnMedio = 0;
    int MasCincuenta = 0;
    printf("Anota  20 números:\n");
    for (int i = 1; i <= 20; i += 1)
    {
        float num = 0;
        fflush(stdout);
        scanf("\n%f", &num);
        if (num <= 15)
        {
            Quince++;
        }
        if (num <= 45 and num >= 25)
        {
            EnMedio++;
        }
        if (num >= 50)
        {
            MasCincuenta++;
        }
    }
    printf("Los numeros antes del quince son en total %d", Quince);
    printf("Los numeros antes del cuarenta y cinco y veinti cinco son en total %d", EnMedio);
    printf("Los numeros arriba del cincuenta %d", MasCincuenta);
}