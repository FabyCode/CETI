#include "Cadenas.h"
#include <stdio.h>
#include <string.h>
#include <math.h>
#define LONGITUD_MAXIMA 1000

int Cadenas::MiStrlen(char cad[])
{
    int tam = 0;
    for (int i = 0; cad[i] != 10; i++, tam++);
    return tam;
}

int Cadenas::str2i(char cad[])
{
    int num = 0;
    for (int i = 0; cad[i] != 10; i++)
    {
        num *= 10;
        num += (cad[i] - 48);
    }
    return num;
}

int Cadenas::CadToAltas(char cad[])
{
    for (int i = 0; cad[i] != 10; i++)
    {
        printf("Ingresa una cadena de caracteres: \n");
        fflush(stdout);
        scanf("%c", cad[i]);

        if (cad[i] >= 'a' && cad[i] <= 'z')
            cad[i] -= 32;
        else if (cad[i] >= 'A' && cad[i] <= 'Z')
            cad[i] += 32;
    }
    for (int i = 0; cad[i]; i++)
        printf("%c", cad[i]);
    return 0;
}

/*int Cadenas::CadInvertida(char cad[])
{
    for(int i=0; cad[i] !=10; i++)
    {
        printf("Escribe una cadena de caracteres: \n");
        fflush(stdout);
        scanf("%s", cad[i]);
        strrev(cad[i]);
        printf("%s \n",cad[i]);
    }
}*/

/*int Cadenas::BinarioADecimal(char [])
{
 char binario[LONGITUD_MAXIMA];
  printf("Introduce un número binario de hasta %d caracteres:\n",
         LONGITUD_MAXIMA - 1);
  fgets(binario, LONGITUD_MAXIMA, stdin);
  binario[strcspn(binario, "\r\n")] = 0;

  unsigned long long decimal = binarioADecimal(binario, strlen(binario));
  printf("El binario %s es %llu en decimal", binario, decimal);

  unsigned long long binarioADecimal(char *cadenaBinaria, int longitud) {
  unsigned long long decimal = 0;
  int multiplicador = 1;
  char caracterActual;
  for (int i = longitud - 1; i >= 0; i--) {
    caracterActual = cadenaBinaria[i];
    if (caracterActual == '1') {
      decimal += multiplicador;
    }
    multiplicador = multiplicador * 2;
  }
  return decimal;
}
}*/

int Cadenas::CuentaVocales(char cad[])
{
    int vocal = 0;
    for (int i = 0; cad[i] != 10; i++)
    {
        if (cad[i] == 'a' or cad[i] == 'e' or cad[i] == 'i' or cad[i] == 'o' or cad[i] == 'u')
            vocal++;
        else if (cad[i] == 'A' or cad[i] == 'E' or cad[i] == 'I' or cad[i] == 'O' or cad[i] == 'U')
            vocal++;
        else;
        /*if(cad[i] == 'a' or cad[i] == 'A')
            vocal++;
        if(cad[i] == 'e' or cad[i] == 'E')
            vocal++;
        if(cad[i] == 'i' or cad[i] == 'I')
            vocal++;
        if(cad[i] == 'o' or cad[i] == 'O')
            vocal++;
        if(cad[i] == 'u' or cad[i] == 'U')
            vocal++;*/
    }
    printf("La cadena cuenta con %d vocales\n", vocal);
}

int Cadenas::HtoI(char cad[])
{
    int num = 0;
    for (int i = 0; cad[i] != 10; i++)
    {
        num *= 16;
        switch (cad[i])
        {
        case '1':
            num += cad[i] - 49;
            break;
        case '2':
            num += cad[i] - 50;
            break;
        case '3':
            num += cad[i] - 51;
            break;
        case '4':
            num += cad[i] - 52;
            break;
        case '5':
            num += cad[i] - 53;
            break;
        case '6':
            num += cad[i] - 54;
            break;
        case '7':
            num += cad[i] - 55;
            break;
        case '8':
            num += cad[i] - 56;
            break;
        case '9':
            num += cad[i] - 57;
            break;
        case 'A':
            num += cad[i] - 50;
            break;
        case 'B':
            num += cad[i] - 51;
            break;
        case 'C':
            num += cad[i] - 52;
            break;
        case 'D':
            num += cad[i] - 53;
            break;
        case 'E':
            num += cad[i] - 54;
            break;
        case 'F':
            num += cad[i] - 55;
            break;

        }
    }
}

void Cadenas::ItoH(char cadInt[], char cadHex[])
{
    int res = 0;

    for (int i = 0; cadInt[i] != 10; i++)
        while (cadInt[i] != 0)
        {
            res = cadInt[i] / 16;
            if (res < 10)
                cadHex[i++] = 48 + res;
            else if (res > 10)
                cadHex[i++] = 55 + res;

            cadInt[i] /= 16;

        }
}

double Cadenas::AtoF(char s[])
{
    int r = 0;
    for (int i = 0; s[i] != '\48'; i++)
    {
        r = r * 10 + s[i] - '48';
    }
    printf("%d", r);

}

int Cadenas::NumMinusculas(char m[])
{
    int minus = 0;
    for (int i = 0; m[i] != 10; i++)
    {
        if (m[i] >= 97 && m[i] <= 122)
            minus++;

    }
    printf("La cadena cuenta con %d minúsculas.", minus);
}

int Cadenas::Palabras(char palabras[])
{
    int CuentaPalabra = 0;
    for (int i = 0; palabras[i] != 10; i++)
    {
        if (palabras[i] ? 10 : 32)
            if (palabras[i - 1] != 32)
                CuentaPalabra++;

    }
}

void Cadenas::OctalADec(char z[], int tam)
{
    int temp = 0, i = 0, c = 1;
    char h;
    do
    {
        h = z[i];
        z[i] = z[tam - c];
        z[tam - c] = h;
        i++;
        c++;
    } while (i != (tam / 2));
    for (int c = 0; c != tam;c++)
        z[c] = z[c] - 48;
    temp += z[c] * (pow(8, c));
    printf("%d ", temp);
}

void Cadenas::DecAOctal(char z[], int tam)
{
    int Division = 0;
    int temp = 0;
    int c = 0, NumEnOctal;
    for (int i = 0; i != tam; i++)
    {
        temp = z[i] - 48;
        Division += temp * (pow(10, (tam - c)));
        temp = 0;
    }
    Division++;
    for (int i = 0; i != tam; i++)
        z[i] = '0';
    Division /= 10;
    printf("Traduccion a decimal %d\n", Division);
    printf("%o\n", Division);
    do
    {
        NumEnOctal = Division % 8;
        Division = Division / 8;
        NumEnOctal += 48;
        z[tam - c] = NumEnOctal;
        c++;
    } while (Division != 0);
    printf("%s", z);
}

long Cadenas::Base2ABase10(char cad[])
{
    long decimal = 0;
    int multiplicador = 1;
    char cifra;
    for (int i = 0; i <= 100.; i++)
    {
        cifra = cad[i];
        if (cifra == '1')
        {
            decimal += multiplicador;
        }
        multiplicador = multiplicador * 2;
    }
    //return decimal;
    printf("%ld", decimal);
}

int Cadenas::stdcompara(char cad1[50], char cad2[50])
{

    for (int i = 0; cad1[i] != 10, cad2[i] != 10; i++)
    {
        if (cad1[i] != cad2[i])
        {
            if (cad1[i] < cad2[i])
                printf("-1");
            else
                printf("1");
        }
        else
            printf("0");
    }

}