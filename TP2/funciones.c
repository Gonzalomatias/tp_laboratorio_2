#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "basicFunctions.h"
#define LIBRE 0
#define OCUPADO  1


int initEmployee(Employee* list, int size)
{
    int isEmpty=-1;

    if(size>0 && list!=LIBRE)
    {
        isEmpty=0;

        for(int i=0; i<size; i++)
        {
            list[i].isEmpty=LIBRE;
        }

    }
    return isEmpty;
}

int addEmployee(Employee* list, int size, int id, char name[],char lastName[],float salary,int sector)
{
    int itsfree;
    char auxSector[20],auxSalary[20];
    int retorno=-1;
    itsfree=EmployeeFree(list,size);

    if(itsfree == -1)
    {
        printf("error no hay mas lugar\n\n");
        return retorno;
    }
    else
    {
        listSectores();

        while(!onlyLetters("\ningrese nombre del empleado: ",name))
        {
            printf("***Error solo letras Reingrese***\n");

        }
        while(!onlyLetters("\ningrese apellido del empleado: ",lastName))
        {
            printf("***Error solo letras Reingrese***\n");

        }

        while(!isNumbers("\ningrese sector: ",auxSector))
        {
            printf("***Error Reingrese***\n");

        }

        sector=atoi(auxSector);
        while(sector<1 || sector >4)
        {
            printf("***error el sector no esta en el sistema Reingrese: ");
            scanf("%d",&sector);
            getchar();
        }

        while(!isNumbers("\ningrese salario: ",auxSalary))
        {
            printf("***Error solo numeros Reingrese***\n");

        }
        salary=atoi(auxSalary);

        retorno=0;

        list[itsfree].id=id;
        strcpy(list[itsfree].name,name);
        strcpy(list[itsfree].lastName,lastName);
        list[itsfree].sector=sector;
        list[itsfree].salary=salary;
        list[itsfree].isEmpty=1;
        id=incrementalID(list,size);

        system("pause");
        system("cls");
    }

    return retorno;
}


int findEmployeeById(Employee* list, int size,int id)
{
    int isEmpty=-1;

    for(int i=0; i<size; i++)
    {
        if(list[i].isEmpty==OCUPADO && list[i].id==id)
        {
            isEmpty=i;
            break;
        }
    }
    return isEmpty;

}

int removeEmployee(Employee* list, int size, int id)
{
    char auxId[20];
    int control;

    printEmployees(list,size);
    printf("\n");
    if(!isNumbers("\ningrese id para dar de baja: ",auxId))
    {
        while("error solo numeros. Reingrese\n");
    }
    id=atoi(auxId);
    control=findEmployeeById(list,size,id);

    if(control== -1)
    {
        printf("no se encontro el ID\n");
        return -1;
    }
    printf("\nborrando datos espere.... \n- %d - %s - %s - %f - %d\n\n",list[control].id,list[control].name,list[control].lastName,list[control].salary,list[control].sector);
    printf("\ndatos borrados.\n\n");
    list[control].isEmpty=0;
    printEmployees(list,size);
    printf("\n\n");

    return 0;

}

void printEmployees(Employee* list, int size)
{
    if(size>0 && list!=NULL)
    {
        for(int i=0; i<size; i++)
        {
            if(list[i].isEmpty==OCUPADO)
            {
                printf("ID:%d  NAME:%s  LASTNAME:%s  SECTOR:%d  SALARY:%.2f\n",list[i].id,list[i].name,list[i].lastName,list[i].sector,list[i].salary);
                printf("\n\n");
            }
        }
    }


}

int EmployeeFree(Employee *list,int size)
{
    int retorno=-1;
    for(int i=0; i<size; i++)
    {
        if(list[i].isEmpty==LIBRE)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}

int incrementalID(Employee *list,int size)
{

    int start=0;

    for(int i=0; i<size; i++)
    {
        if(list[i].isEmpty==OCUPADO)
        {
            if(list[1].id==0)
            {
                start++;
                list[i].id=start;
            }

        }

    }
    return start;
}


int modifyEmployee(Employee* list,int size,int id, char name[],char lastName[],float salary,int sector)
{
    char auxId[20],auxSalary[20],auxSector[20];
    int control,retorno=-1;
    char option;

    printEmployees(list,size);
    printf("\n");
    if(!isNumbers("\ningrese id para Modificar los datos: ",auxId))
    {
        while("error solo numeros. Reingrese\n");
    }
    id=atoi(auxId);
    control=findEmployeeById(list,size,id);
    if(control== -1)
    {
        printf("no se encontro el ID\n");
        return retorno;
    }
    else
    {

        printf("Desea modificar el nombre? S/N\n");
        fflush(stdin);
        scanf("%c",&option);
        if(option=='s'|| option =='S')
        {
            while(!onlyLetters("\ningrese nuevo nombre: ",name))
            {
                printf("***Error solo letras Reingrese***\n");

            }
            strcpy(list->name,name);
            printf("Modificacion de nombre finalizada\n");
        }
        else
        {
            printf("Modificacion no realizada\n");
        }
        printf("Desea modificar el apellido? S/N\n");
        fflush(stdin);
        scanf("%c",&option);
        if(option=='s'|| option =='S')
        {
            while(!onlyLetters("\ningrese nuevo apellido: ",lastName))
            {
                printf("***Error solo letras Reingrese***\n");
            }
            strcpy(list->lastName,lastName);
            printf("Modificacion de apellido finalizada\n");
        }
        else
        {
            printf("Modificacion no realizada\n");
        }

        printf("Desea modificar el sector? S/N\n");
        fflush(stdin);
        scanf("%c",&option);
        if(option=='s' || option =='S')
        {
            while(!isNumbers("\ningrese nuevo sector: ",auxSector))
            {
                printf("***Error solo numeros Reingrese***\n");
            }
            sector=atoi(auxSector);
            list->sector=sector;
            printf("Modificacion de sector finalizada\n");
        }
        else
        {
            printf("Modificacion no realizada\n");
        }

        printf("Desea modificar el salario? S/N\n");
        fflush(stdin);
        scanf("%c",&option);
        if(option=='s' || option =='S')
        {
            while(!isNumbers("\ningrese nuevo salario: ",auxSalary))
            {
                printf("***Error solo numeros Reingrese***\n");
            }
            salary=atoi(auxSalary);
            list->salary=salary;
            printf("Modificacion de salario finalizada\n");
        }
        else
        {
            printf("Modificacion no realizada\n");
        }

        retorno=0;

    }

    return retorno;
}

void sortEmployees(Employee* list, int size,int order)
{

    // int auxInt;
    Employee aux;
    Employee aux2;
    for(int i=0; i<size-1; i++)
    {
        if(order==1 && list[i].sector>list[i+1].sector)
        {
            printf("\n\t\t***orden por sector***\n\n");
            aux2=list[i];
            list[i]=list[i+1];
            list[i+1]=aux2;

        }
        if(order==1 && strcmp(list[i].lastName,list[i+1].lastName) > 0 )
        {
            printf("\n\t\t***orden por apellido***\n\n");
            aux = list[i+1];
            list[i+1] = list[i];
            list[i] = aux;

        }


    }


}

void averageEmployees(Employee* list,int size)
{
    float aux=0;
    float suma;
    float promedio;
    int contador=0;
    for(int i=0; i<size; i++)
    {
        suma=aux+=list[i].salary;
        promedio=suma/size;

        if(list[i].salary>promedio)
        {
            contador++;
        }

    }
    printf("\nel total de salarios: %.2f\n\n",suma);
    printf("\nel promedio de los salarios es: %.2f\n\n",promedio);
    printf("\nlos empleados que superan el promedio de salario son: %d\n\n",contador);
}





