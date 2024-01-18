#include <stdio.h>
#include "Mate.h"
#include "Juego.h"
#include "Salarios.h"
#include "ArreglosNumericos.h"
#include "Cadenas.h"
#include "Fechas.h"

int main(int argc, char** argv)
{
    Mate m;
    Juego j;
    salarios s;
    ArreglosNumericos ar;
    Cadenas c;

    Fechas f;
    //"&" se us apara la dirección y "*" se usa para apuntar
    printf("Hello World");

    return 0;

    int numero;
    printf("Escribe un número ");
    fflush(stdout);
    scanf("%d",&numero);
    
    int cifras = m.CuentaCifras(numero);
    printf("El número %d tiene %d cifras",numero,cifras);

    int par, impar, n;
    
    m.PareseImpares10(n);
    printf("En total hay %d pares y %d impares",par,impar);

    int numperfectos = 0, numero = 1;
    
    while(true)
    {
        if(m.EnteroPerfecto(numero))
        {
            numperfectos++;
            printf("%d es entero perfecto\n", numero);
            if(numperfectos==4)
                break;
        }
        numero++;
    }

    
    char cc;
    float x;
    printf(" a = sencillo 1 punto.    \n b = capirucho sencillo. 5 puntos.   \n c = clasico 10 puntos.   \n d = capirucho complicado. 10 puntos.   \n e = cruzado 50 puntos.   \n f = reves 100 puntos.   \n g = jalon 250 puntos.   \n h = invertido 500 puntos. \n que tipo de ensarte va a hacer? : ");
    fflush(stdout);
    scanf("%c",&c);
    x = j.JuegoBalero(cc);
    printf("el jugador tiene %f puntos",x); 

    
    s.SalarioDe5();

   
    m.TresRango(); 


    s.Bonificaciones(); 

    
    m.TriplePitagorico();

    
    m.SenoRad();

    
    int Arr[TAMARREGLO];

    //ar.FactoresArr(Arr, TAMARREGLO);

    //ar.LlenaArr(Arr,TAMARREGLO);
    ar.LlenaArrAleatorio(Arr,TAMARREGLO);
    ar.Despliega(Arr,TAMARREGLO);
    int num;
    printf("Dame un número: ");
    fflush(stdout);
    scanf("%d",&num);
    if(ar.BuscaArr(Arr,TAMARREGLO,num))
        printf("El %d está en el arreglo",num);
    else
        printf("El %d no está en el arreglo",num);
        int dif = ar.DifConsecutivos(Arr,TAMARREGLO);
        printf("La mayor diferencia entre consecutivos es %d",dif);


        
        char cad[10];
        printf("Dame una cadena: ");
        fflush(stdout);
        fgets(cad,10,stdin);

        c.NumMinusculas(cad);

        
        int num = c.str2i(cad);
        printf("El número que está en la cadena %s es %d\n",cad,num);
        int tam = c.MiStrlen(cad);
        printf("La cadena %s tiene una longitud de %d",cad,tam); 

        //c.CadToAltas(cad);
        //c.CadInvertida(cad);
        //c.CuentaVocales(cad);

        //int Hexa=c.ItoH(cad,cad);
        //printf("%d", &Hexa);

        //c.AtoF(cad);

        
        long fec;
        printf("Dame una fecha (AAAAMMDD): ");
        fflush(stdout);
        scanf("%ld",&fec);
        if(f.FechaValida(fec))
            printf("Fecha válida\n");
        else
            printf("Fecha no válida\n");
        f.FechaAyer(fec);

      
        int Arr[100];
        ar.DosMayores(Arr);


        char cad[10];
        printf("Dame una cadena: ");
        fflush(stdout);
        fgets(cad, 10, stdin);
        int tam = c.MiStrlen(cad);
        c.Base2ABase10(cad);

    return 0;
}