#include <stdio.h>
#include <stdlib.h>
#include "Employee.h"
#define len 100

int main()
{

    int opcion;
    Employee employeeList[len];
    int id;
    int orden;
    initEmployees(employeeList,len);

    do
    {
        printf("Elija una de las siguientes opciones.\n"
               "1) Dar de alta un usuario.\n"
               "2) Modificar un usuario.\n"
               "3) Eliminar un usuario.\n"
               "4) Informes.\n"
               "5) Salir.\n\n");
        fflush(stdout);
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
            {
                if(add_newEmployee(employeeList,len))
                {
                    printf("El empleado ha sido agregado correctamente.\n");
                    fflush(stdout);
                }
                break;
            }

            case 2:
            {
                printf("Por favor indique el id del empleado.");
                fflush(stdout);
                scanf("%d",&id);

                if(modifyEmployee(employeeList,len,id) != -1)
                {
                    printf("El empleado ha sido modificado correctamente.\n");
                    fflush(stdout);
                }
                break;
            }

            case 3:
            {
                printf("Por favor indique el id del empleado.");
                fflush(stdout);
                scanf("%d",&id);

                if(!removeEmployee(employeeList,len,id))
                {
                    printf("El empleado ha sido eliminado correctamente.\n");
                    fflush(stdout);
                }
                break;
            }

            case 4:
            {
                do
                {
                    printf("Por favor elija que informe desea ver:\n\n"
                    "1) Listado de empleados ordenados por Apellido y Sector.\n"
                    "2) Total y promedio de los salarios, y cuantos empleados superan el salario promedio.\n"
                    "3) Volver al menu principal.\n\n");
                    fflush(stdout);
                    scanf("%d",&opcion);

                    switch(opcion)
                    {
                        case 1:
                        {
                            printf("Por favor elija el ordenamiento.\n"
                                   "1) Ascendente.\n"
                                   "2) Descendente.\n");
                            fflush(stdout);
                            scanf("%d",&orden);
                            sortEmployees(employeeList,len,orden);
                            printEmployees(employeeList,len);
                            break;
                        }

                        case 2:
                        {
                            salaryAverage(employeeList,len);
                            break;
                        }
                    }

                }while(opcion!=3);

                break;
            }


        }

    }while(opcion!=5);

    return 0;
}
