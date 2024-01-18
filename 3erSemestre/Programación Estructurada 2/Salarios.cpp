#include <stdio.h>
#include "Salarios.h"

float salarios:: SalarioDe5() 

{
    int ok, horasextra;
    float suma, paga;
    float salario=250.50;
    for(int i=1;i<=5;i++)
    {
        printf("El empleado [%d] trabajó las 40 horas? [1]si\n",i);
        fflush(stdout);
        scanf("%d",&ok);
        if(ok==1)
        {
            printf("trabajo horas extra? [1]si\n");
            fflush(stdout);
            scanf("%d",&ok);
            if(ok==1)
            {
           printf("cuantas horas extra trabajo?\n");
           fflush(stdout);
           scanf("%d",&horasextra);
           paga=horasextra*(salario+salario/2);
           
            }//if horas extra
            paga+=salario;
        }//if trabajo las 40 horas
        suma=suma+paga;
        printf("su paga fue %.2f\n", paga);
        fflush(stdout);
    }//for
    printf("la suma semanal de los salarios de los 5 empleados fue de %.2f",suma);
}

int salarios::Bonificaciones()
{
    int bonificacion, hijos, anios;
    int Menos3=0;
    int Aniostotal=0;
    for(int i=1; i<=10;i++)
    {
      printf("¿Cuantos años lleva trabajando [%d]? ",i);
      fflush(stdout);
        scanf("%d",&anios);
        if(anios<=5)
            printf("No aplica para una bonificación\n");
        if(anios>=6 && anios<10)
        {
            printf("Bonificación del 5\n");
            fflush(stdout);
            Aniostotal=Aniostotal+5;
        }
        if(anios>=10)
        {
            printf("Bonificación del 10\n");
            fflush(stdout);
            Aniostotal=Aniostotal+10;
        }
        printf("¿Con cuántos hijos cuenta el empleado [%d]? ",i);
        fflush(stdout);
        scanf("%d",&hijos);
        if(hijos==1)
        {
            printf("Bonificacion $50,000\n");
            fflush(stdout);
            Menos3++;
        }
        if(hijos==2)
        {
            printf("Bonificacion $100,000\n");
            fflush(stdout);
            Menos3++;
        }
        if(hijos==3)
        {
            printf("Bonificacion $150,000\n");
            fflush(stdout);
            
        }
        if(hijos>=4)
        {
            printf("Bonificacion $200,000\n");
            fflush(stdout);
            
        }
        if(hijos==0)
        {
            printf("Sin bonificación por hijos\n");
            fflush(stdout);
            Menos3++;
        }
    }
       printf("El porcentaje acumulado es de %d \n",Aniostotal); 
       printf("%d empleados cuentan con menos de 3 hijos",Menos3);
}
