#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "basicFunctions.h"
#define TAM 2

int main()
{
    int flag1=0;
    int add,efface,modify;
    char continues='s';
    int option=0,sector=0;
    int id=0;
    char name[51],lastName[51];
    float salary=0;

    Employee list[TAM];
    initEmployee(list,TAM);

    do
    {
        switch(menu(option))
        {
        case 1:
            printf("\t***Alta empleados***\n");
            add=addEmployee(list,TAM,id,name,lastName,salary,sector);
            if(add==1)// for the return == 1
            {
                printf("alta dada con exito!!!\n");

            }
            flag1=1;
            break;
        case 2:
            printf("\t***Modificacion Empleados***\n");
            if(flag1!=1)
            {
                printf("\nerror no hay datos en el sistema\n\n");
                system("pause\n");

            }
            else
            {
                modify=modifyEmployee(list,TAM,id,name,lastName,salary,sector);
                if(modify==0)
                {
                    printf("las modificacion que realizo fueron un exito!!!\n\n");
                }
            }
            break;
        case 3:
            printf("\t***Baja empleados***\n");
            if(flag1!=1)
            {
                printf("\nerror no hay datos en el sistema\n\n");
                system("pause\n");

            }
            else
            {
                efface=removeEmployee(list,TAM,id);
                if(efface==0)
                {
                    printf("la baja fue dada con exito!!!\n\n");
                }
            }
            break;
        case 4:
            if(flag1!=1)
            {
                printf("\nError no hay datos en el sistema\n\n");
                system("pause\n");
            }
            else
            {
                printf("\t**Listar**\n");
                sortEmployees(list,TAM,1);
                printEmployees(list,TAM);
                averageEmployees(list,TAM);
            }
            break;
        case 5:
            exit(-1);
            break;
        default:
            printf("error");
            getchar();
            exit(-1);
            break;
        }

    }
    while(continues=='s');

    return 0;
}

