#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"
#include "parser.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
   int ret = 0;

    FILE* pFile = fopen("data.csv", "r");
    if(pFile != NULL)
    {
        ret = parser_EmployeeFromText(pFile, pArrayListEmployee);
    }
    else
    {
        printf("El Archivo No Existe\n\n");
        fflush(stdout);
        system("pause");
    }

    return ret;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
     int ret = 0;

    FILE* pFile = fopen("data.bin", "rb");
    if(pFile != NULL)
    {
        ret = parser_EmployeeFromBinary(pFile, pArrayListEmployee);
    }
    else
    {
        printf("El Archivo No Existe\n\n");
        fflush(stdout);
        system("pause");
    }

    return ret;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int ret = 0;

    Employee* employee = employee_new();
    char id[50];
    char nombre[50];
    char horasTrabajadas[50];
    char sueldo[50];

    if(pArrayListEmployee != NULL)
    {
        printf("Ingrese ID: ");
        fflush(stdout);
        scanf("%s", id);

        printf("Ingrese Nombre: ");
        fflush(stdout);
        scanf("%s", nombre);

        printf("Ingrese Horas Trabajadas: ");
        fflush(stdout);
        scanf("%s", horasTrabajadas);

        printf("Ingrese Sueldo: ");
        fflush(stdout);
        scanf("%s", sueldo);

        employee = employee_newParametros(id, nombre, horasTrabajadas, sueldo);

        ret = ll_add(pArrayListEmployee, employee);
    }
    else
    {
        printf("No hay Datos\n\n");
        fflush(stdout);
    }
    return ret;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int respuesta = 0;
    Employee* employee = employee_new();
    int id;
    char nombre[20];
    char horasTrabajadas[3];
    char sueldo[8];

    if(pArrayListEmployee != NULL)
    {
        printf("Ingrese un ID\n");
        fflush(stdout);
        scanf("%d", &id);

        for(int i = 0; i < ll_len(pArrayListEmployee); i++)
        {
            employee = ll_get(pArrayListEmployee, i);

            if(employee_getId(employee, &id))
            {
                    switch(menuEdit())
                    {
                    case 1:

                        printf("Ingrese Nombre: ");
                        fflush(stdout);
                        scanf("%s", nombre);
                        respuesta = employee_setNombre(employee, nombre);
                        break;
                    case 2:

                        do
                        {
                            printf("Ingrese Horas Trabajadas\n");
                            fflush(stdout);
                            scanf("%s", horasTrabajadas);
                            respuesta = employee_setHorasTrabajadas(employee, atoi(horasTrabajadas));
                        }
                        while(horasTrabajadas < 0);
                        break;
                    case 3:

                        do
                        {
                            printf("Ingrese Sueldo\n");
                            fflush(stdout);
                            scanf("%s", sueldo);
                            respuesta = employee_setSueldo(employee, atoi(sueldo));
                        }
                        while(sueldo < 0);
                        break;
                    default:
                        break;
                    }

                    if(!respuesta)
                    {
                        printf("\nProblemas pata modificar el campo.\n");
                        fflush(stdout);
                    }

                    respuesta = ll_set(pArrayListEmployee, i, employee);
                    break;
                }
            }
        }

    else
    {
        printf("No hay datos en la lista.\n");
        fflush(stdout);
    }

    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int respuesta = 0;
    int id;
    int len = ll_len(pArrayListEmployee);
    Employee* employee = employee_new();

    if(pArrayListEmployee != NULL && len>0)
    {
        printf("Ingrese un ID\n");
        fflush(stdout);
        scanf("%d", &id);

        for(int i = 0; i < len; i++)
        {
            employee = ll_get(pArrayListEmployee, i);

            if(employee_getId(employee, &id))
            {
                 respuesta = ll_remove(pArrayListEmployee, i);
				 break;
            }
        }
    }
    else
    {
        printf("No hay datos en la lista.\n");
        fflush(stdout);
    }

    return respuesta;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int ret = 0;
    int len = ll_len(pArrayListEmployee);
    Employee* employee;

    if(pArrayListEmployee != NULL && len > 0)
    {
        if(len != 0)
        {
            printf("Id  Nombre  Hs.Trab.  Sueldo\n\n");
            for(int i = 1; i < len; i++)
            {
                employee = ll_get(pArrayListEmployee, i);
                employee_showEmployee(employee);

                ret = 1;
            }
            system("pause");
        }
        else
        {
            printf("No hay datos\n\n");
            fflush(stdout);
            system("pause");
        }
    }
    return ret;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int ret = 0;
    int len = ll_len(pArrayListEmployee);

    if(pArrayListEmployee != NULL && len > 0)
    {
        switch(menuSort())
        {
        case 1:
                ll_sort(pArrayListEmployee, employee_sortById,1);
                employee_showEmployees(pArrayListEmployee);
                break;
        case 2:
                ll_sort(pArrayListEmployee, employee_sortByName,1);
                employee_showEmployees(pArrayListEmployee);
                break;
        case 3:
                ll_sort(pArrayListEmployee, employee_sortByHsTrabajadas,1);
                employee_showEmployees(pArrayListEmployee);
                break;
        case 4:
                ll_sort(pArrayListEmployee, employee_sortBySueldo,1);
                employee_showEmployees(pArrayListEmployee);
                break;
        case 5:
                break;
        }
    }
    else
    {
        printf("No hay datos\n");
        fflush(stdout);
    }
    system("pause");

    return ret;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int respuesta = 0;
    int longitud;

    if(ll_len(pArrayListEmployee) == 0)
    {
        printf("No hay datos en la lista.\n");
        fflush(stdout);
    }
    else
    {
        FILE *pFile = fopen(path,"w");
        Employee* pEmployee = employee_new();
        if(pFile==NULL)
        {
            printf("Archivo inexistente\n");
            fflush(stdout);
        }
        else
        {
            longitud = ll_len(pArrayListEmployee);
            for(int i = 0; i < longitud; i++)
            {
                pEmployee = (Employee*) ll_get(pArrayListEmployee, i);

                fprintf(pFile, "%d, %s, %d, %d\n", pEmployee->id, pEmployee->nombre, pEmployee->horasTrabajadas, pEmployee->sueldo);    //Se escribe al archivo

            }
            respuesta = 1;
            fclose(pFile);
        }
    }

    return respuesta;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int ret = 0;

    FILE* pFile;
    pFile = fopen("data.bin", "wb");
    Employee* emp;

    if(ll_len(pArrayListEmployee)!= 0)
    {
        if(pArrayListEmployee != NULL)
        {
            for(int i = 0; i<ll_len(pArrayListEmployee);i++)
            {
                emp = (Employee*)ll_get(pArrayListEmployee, i);
                fwrite(emp, sizeof(Employee*), 1, pFile);
            }
            fclose(pFile);
            ret = 1;
        }
        else
        {
            printf("No hay Archivo\n");
            fflush(stdout);
            system("pause");
        }
     }
     else
     {
         printf("No hay Datos\n");
         fflush(stdout);
     }

    return ret;
}

int menuPrincipal()
{
    int r;
    do
    {

        printf(" \n");
        printf("  Menu:                                                                          \n");
        printf("  1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).   \n");
        printf("  2. Cargar los datos de los empleados desde el archivo data.csv (modo binario). \n");
        printf("  3. Alta de empleado                                                            \n");
        printf("  4. Modificar datos de empleado                                                 \n");
        printf("  5. Baja de empleado                                                            \n");
        printf("  6. Listar empleados                                                            \n");
        printf("  7. Ordenar empleados                                                           \n");
        printf("  8. Guardar los datos de los empleados en el archivo data.csv (modo texto).     \n");
        printf("  9. Guardar los datos de los empleados en el archivo data.bin (modo binario).   \n");
        printf(" 10. Salir                                                                       \n");
        printf(" \n");
        fflush(stdout);
        scanf("%d", &r);

    }while(r < 1 || r > 10);

    return r;
}

int menuEdit()
{
    int r;

    do
    {
        system("cls");
        printf("***********************************\n");
        printf("     Seleccione un campo a editar: \n");
        printf("     1. Nombre.                    \n");
        printf("     2. Horas Trabajadas.          \n");
        printf("     3. Sueldo                     \n");
        printf("     4. Salir                      \n");
        printf("***********************************\n");
        fflush(stdout);
        scanf("%d", &r);
    }
    while(r < 1 || r > 4);

    return r;
}

int menuSort()
{
    int r;

    do
    {
        system("cls");
        printf("***********************************\n");
        printf("     Seleccione el sort:           \n");
        printf("     1. Id.                        \n");
        printf("     2. Nombre.                    \n");
        printf("     3. Horas Trabajadas.          \n");
        printf("     4. Sueldo                     \n");
        printf("     5. Salir                      \n");
        printf("***********************************\n");
        fflush(stdout);
        scanf("%d", &r);
    }
    while(r < 1 || r > 5);

    return r;
}

