#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "basicFunctions.h"

int menu(int option)
{
    option=0;

    printf("\t---1-***ALTAS***\n");
    printf("\t---2-***MODIFICAR***\n");
    printf("\t---3-***BAJA***\n");
    printf("\t---4-***INFORMAR***\n");
    printf("\t---5-***SALIR***\n");
    printf("\n");
    printf("ingrese opcion: ");
    scanf("%d",&option);
    system("cls");
    system("pause");
    system("cls");
    return option;

}

int letters(char letter[])
{
    int i=0;

    while(letter[i] != '\0')
    {
        if((letter[i] != ' ') && (letter[i] < 'a' || letter[i] > 'z') && (letter[i] < 'A' || letter[i] > 'Z'))
        {
            return 0;
        }
        i++;
    }
    return 1;
}

int Mensage(char msj[])
{
    int aux;

    printf("%s",msj);
    scanf("%d",&aux);

    return aux;
}

int isNumbers(char msj[],char loadText[])
{
    char aux[300];
    isString(msj,aux);
    if(isNumeric(aux))
    {
        strcpy(loadText,aux);
        return 1;
    }
    return 0;
}

void isString(char msj[],char cargarTexto[])
{
    printf("%s",msj);
    fflush(stdin);
    gets(cargarTexto);

}

int onlyLetters(char msj[],char cargarTexto[])
{
    char aux[300];
    isString(msj,aux);
    if(letters(aux))
    {
        strcpy(cargarTexto,aux);
        return 1;
    }
    return 0;
}


int isNumeric(char number[])
{
    int i=0;
    while(number[i] != '\0')
    {
        if(number[i] < '0' || number[i] > '9')
        {
            return 0;
        }
        i++;
    }
    return 1;
}

void listSectores()
{
    printf("Sectores\n");
    printf("\n1-Systems\n\n");
    printf("\n2-Social\n\n");
    printf("\n3-Service\n\n");
    printf("\n4-Communication\n\n");
    printf("----------------------");
}
