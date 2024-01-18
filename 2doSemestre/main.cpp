#include <stdio.h>

#include "Caracter.h"
#include "Conversion.h"
#include "Fecha.h"
#include "Mate.h"
#include "Juego.h"

int main(int argc, char** argv)
{
    Mate m;
    Conversion conv;
    Fecha f;
    Caracter car;
    Juego j;

    //printf("Hola mundo");
    
    double millas, kms;
    printf("Dame una distancia en kilómetros: ");
    fflush(stdout);
    scanf("%lf",&kms);
    millas = conv.KilometrosAMillas(kms);
    printf("%lf kilómetros equivalen a %lf millas",kms,millas);


    double lbs, kls;
    printf("Dame un peso en libras: ");
    fflush(stdout);
    scanf("%lf",&lbs);
    kls = conv.LibrasAKilos(lbs);
    printf("%lf libras equivalen a %lf kilogramos",lbs,kls);
    
    
    float areaCirculo, radio;
    printf("Dame el radio de un círculo: ");
    fflush(stdout);
    scanf("%f",&radio);
    areaCirculo = m.AreaCirculo(radio);
    printf("El área de un círculo de radio %f es %f",radio,areaCirculo);


    float lado, area;
    printf("Dame el lado de un cuadrado: ");
    fflush(stdout);
    scanf("%f",&lado);
    area = m.AreaCuadrado(lado);
    printf("El área de un cuadrado de lado %f es %f",lado,area);


    float areaOctaedro, areaLado;
    printf("Dame el área de un lado de un octaedro: ");
    fflush(stdout);
    scanf("%f",&areaLado);
    areaOctaedro = m.AreaOctaedro(areaLado);
    printf("El área de un Octaedro con un área de un lado %f es %f",areaLado,areaOctaedro);
    

    double areaTetraedro, areaLado;
    printf("Dame el área de un lado de un tetraedro: ");
    fflush(stdout);
    scanf("%lf",&areaLado);
    areaTetraedro = m.AreaTetraedro(areaLado);
    printf("El área de un tetraedro con un área de un lado %f es %f",areaLado,areaTetraedro);
    

    double area, altura, base;
    printf("Dame la altura de un triángulo: ");
    fflush(stdout);
    scanf("%lf",&altura);
    printf("Dame la base de un triángulo: ");
    fflush(stdout);
    scanf("%lf",&base);
    area = m.AreaTriangulo(base,altura);
    printf("El área de un triángulo de base %lf y altura %lf es %lf",base,altura,area);

    
    int a, mm, d;
    long fec;
    printf("Dame una fecha (AAAAMMDD): ");
    fflush(stdout);
    scanf("%ld",&fec);
    a = f.Anio(fec);
    d = f.Dia(fec);
    mm = f.Mes(fec);
    printf("La fecha %ld tiene año %d, día %02d y mes %02d",fec,a,d,mm);


    float num1, num2, suma, diferencia, producto, cociente;
    printf("Dame el primer número: ");
    fflush(stdout);
    scanf("%f",&num1);
    printf("Dame el segundo número: ");
    fflush(stdout);
    scanf("%f",&num2);
    printf("\nLa variable diferencia tiene el nombre diferencia, el tipo float, el valor %f",diferencia);
    printf("\ntiene una longitud de 4 bytes (porque es float) y una dirección %x",&diferencia);
    m.Operaciones(num1,num2,&suma,&diferencia,&producto,&cociente);
    printf("\nLa variable diferencia tiene el nombre diferencia, el tipo float, el valor %f",diferencia);
    printf("\ntiene una longitud de 4 bytes (porque es float) y una dirección %x",&diferencia);
    printf("\nLa suma es %f",suma);
    printf("\nLa diferencia es %f",diferencia);
    printf("\nEl producto es %f",producto);
    printf("\nEl cociente es %f",cociente);
    printf("\nnum1 es %f y num2 es %f",num1,num2);


    float numero, inverso;
    printf("Dame un número: ");
    fflush(stdout);
    scanf("%f",&numero);
    //inverso = mat.Inverso(numero);
    m.Inverso(numero,&inverso);
    printf("El número %f tiene el inverso %f",numero,inverso);


    long numero, absoluto;
    printf("Dame un número: ");
    fflush(stdout);
    scanf("%ld",&numero);
    absoluto = m.Abs(numero);
    //m.Abs(numero,&absoluto);
    printf("El valor absoluto de %ld es %ld",numero,absoluto);


            
            char car1, car2, enter;
            printf("Dame un caracter: ");
            fflush(stdout);
            scanf("%c%c",&car1,&enter);
            printf("Dame otro caracter: ");
            fflush(stdout);
            scanf("%c%c",&car2,&enter);
            bool res = car.OrdenCaracteres(car1,car2);
            if(res)
                printf("Los caracteres están en orden alfabético");
            else
                printf("Los caracteres no están en orden alfabético");


                char car1, enter;
                printf("Dame un caracter: ");
                fflush(stdout);
                scanf("%c%c",&car1,&enter);


                int res = car.CaracterRespectom(car1);
                switch(res)
                {
                    case 1:
                        printf("El caracter es menor que m");
                        break;
                    case 2:
                        printf("El caracter es m");
                        break;
                    case 3:
                        printf("El caracter es mayor que m");
                        break;
                }
             

                int n1, n2, n3;
                printf("Dame el primer número: ");
                fflush(stdout);
                scanf("%d",&n1);
                printf("Dame el segundo número: ");
                fflush(stdout);
                scanf("%d",&n2);
                printf("Dame el tercer número: ");
                fflush(stdout);
                scanf("%d",&n3);
                bool res = m.NumIgualSuma(n1,n2,n3);
                if(res)
                    printf("Un número es igual a la suma de los otros dos");
                else
                    printf("Un número no es igual a la suma de los otros dos");
                return 0;


                char car1, car2, enter;
                printf("Dame un caracter: ");
                fflush(stdout);
                scanf("%c%c",&car1,&enter);
                char resus;
                car.CaracterRespectoIM(car1,&resus);
                switch(res)
                {
                    case '1':
                        printf("El caracter es i");
                        break;
                    case '2':
                        printf("El caracter es m");
                        break;
                    case '3':
                        printf("El caracter es menor que i");
                        break;
                    case '4':
                        printf("El caracter es mayor que m");
                        break;
                    case '5':
                        printf("El caracter esta entre i y m");
                        break;
                }


                int tipotriangulo, ladoA, ladoB, ladoC;
                printf("Escriba el valor del primer lado del triangulo: ");
                fflush(stdout);
                scanf("%d", &ladoA);
                printf("Escriba el valor del segundo lado del triangulo: ");
                fflush(stdout);
                scanf("%d", &ladoB);
                printf("Escriba el valor del tercer lado del triangulo: ");
                fflush(stdout);
                scanf("%d", &ladoC);
                char resultado;

                switch (resultado){
                        case '1':
                            printf("El triangulo es Equilatero");
                            break;
                        case '2':
                            printf("El triangulo es Isosceles");
                            break;
                        case '3':
                            printf("El triangulo es Escaleno");
                            break;
                        case '4':
                            printf("No se puede hacer un triangulo con las medidas dadas");
                            break;
                }

                return 0;


                /*float Peso, Estatura, IMC;
                printf("Escribe tu peso (en kilos): ");
                fflush(stdout);
                scanf("%f",&Peso);
                printf("Escribe tu estatura (en metros): ");
                fflush(stdout);
                scanf("%f",&Estatura);
                IMC= m.IMC(Peso, Estatura);
                printf("Tu peso es %f, tu estatura es %f y tu IMC %f",Estatura ,Peso ,IMC);
                

                float p = 0, n = 0;
                m.Posi(&p, &n);
                printf("%f números son positivos y %f son negativos",p, n);
                return 0;*/


                int n1;
                printf("Dame un número: ");
                fflush(stdout);
                scanf("%d",&n1);
                m.Impares(n1);
                return 0;


                float s = 0, p = 0;
                printf("%f es la suma de los 200 números y %f es su promedio",s, p);
                return 0;

                 
                 j.Adivinador();
                 return 0;


                 int n;
                 m.Pares(n);


                 float ff[4];
                 m.Estadistico(ff);
                 printf("El numero menor es %f \n El numero mayor es %f \n La suma de los numeros es %f \n El promedio es %f", ff[0], ff[1], ff[2], ff[3]);


                 int n;
                 printf("Introduce un número para ver sus divisores: ");
                 fflush(stdout);
                 scanf("%d",&n);
                 m.Divisores(n);
                 return 0;


                 char c;
                 float x;
                 printf(" a = sencillo 1 punto.    \n b = capirucho sencillo. 5 puntos.   \n c = clasico 10 puntos.   \n d = capirucho complicado. 10 puntos.   \n e = cruzado 50 puntos.   \n f = reves 100 puntos.   \n g = jalon 250 puntos.   \n h = invertido 500 puntos. \n que tipo de ensarte va a hacer? : ");
                 fflush(stdout);
                 scanf("%c",&c);
                 x = j.JuegoBalero(c);
                 printf("el jugador tiene %f puntos",x);

                 printf("Este codigo calcula el promedio de varios números, hasta que introduzcas un 0:\n");
                 m.PromedioHasta0();
                 return 0;

    m.TresRango();
    return 0;
}