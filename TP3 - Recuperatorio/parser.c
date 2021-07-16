#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"


/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{

    int ret = 0;
    int cant = 0;
    char idStr[50];
    char nombreStr[50];
    char horasTrabajadasStr[50];
    char sueldoStr[50];

    if(pFile != NULL)
    {
        while(!feof(pFile))
        {
            cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,\n]\n", idStr, nombreStr, horasTrabajadasStr, sueldoStr);
            if(cant != 4)
            {
                printf("Error al cargar Arvhivo\n\n");
                fflush(stdout);
                system("pause");
            }
            else
            {
                Employee* employee = employee_new();

                employee = employee_newParametros(idStr,nombreStr,horasTrabajadasStr,sueldoStr);
                ll_add(pArrayListEmployee, employee);
            }
        }
    fclose(pFile);
    ret=1;
    }
    else
    {
        printf("Arvhivo hay datos\n\n");
        fflush(stdout);
        system("pause");
    }

    return ret;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int ret;
    ret = 0;

    if(pFile != NULL)
    {
        while(!feof(pFile))
        {

                Employee* emp = employee_new();
                ret = fread(emp, sizeof(Employee),1,pFile);
                if(ret != 1)
                {
                    printf("Error al cargar datos\n");
                    fflush(stdout);
                }
                else
                {
                    ll_add(pArrayListEmployee, emp);
                }
        }
    fclose(pFile);
    ret = 1;
    }
    else
    {
        printf("No hay datos");
        fflush(stdout);
        system("pause");
    }

    return ret;
}
