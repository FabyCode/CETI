#include "Mate.h"

#include <math.h>
#include <stdio.h>
#define pi 3.1415926536


int Mate::CuentaCifras(int num) 
{
    int cifras = 0;
    while(num>0)
    {
        cifras++;
        num = num/10;
    }
    return cifras;
};

int Mate::PareseImpares10(int n)
{
    int par, impar, i;
    for(int i = 1; i <= 10; i++)
    {
        printf("Escribe el número [%d]",i);
        fflush(stdout);
        scanf("%d",&n);
        if(n / 2 >= 0){
            par++;
        }
        else{
            impar++;
        }
    }
}

bool Mate::EnteroPerfecto(int num)
{
    int sumafactores = 0;
    for(int i = 1; i<num; i++)
        if(num % i == 0)
            sumafactores +=i;
    return(sumafactores == num) ? true : false;
}

int Mate::TresRango()
{
    int num;
    for (int i=1;i<=30;i++)
    {
        printf("Escribe un número = ");
        fflush(stdout);
        scanf("%d",&num);
        if(num<=15)
            printf("Es menor que 15\n");
        if(num>=25 && num<=45)
            printf("Está entre 25 y 45\n");
        if(num>=50)
            printf("Es mayor que 50\n");
        
    }
        
}

void Mate::TriplePitagorico()
{
    int Hipotenusa, CatetoOp, CatetoAdya;
for(int i=1;i<=500;i++)
    {
    for(int f=1;f<=500;f++)
        {
        for(int k=1;k<=500;k++)
            {
                if ((i * i)==((f*f)+(k*k)));
                {
                    printf("Se encontro un triple Pitagorico:\n");
                    printf("Este Cateto Adyacente es de %d:\n",k);
                    printf("Este Cateto Opuesto es de %d:\n", f);
                    printf("Esta Hipotenusa es de %d:\n", i);
                }
            }
        }
        
    }
}

double Mate::SenoRad()
{
    float x, seno, grados;
    printf("Dame un ángulo en radianes: ");
    scanf("%f",&x);
    //1 rad × 180/π = 57.296°
    //1° × π/180 = 0.01745rad
    //grados = x * 180/pi;
    seno=sin(x);
    printf("El seno de %.2f es de = %.4f \n", x, seno);
}