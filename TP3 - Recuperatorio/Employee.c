#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"


Employee* employee_new()
{
    Employee* employee;
    employee = (Employee*)malloc(sizeof(Employee));
    (*employee).id = 0;
    strcpy((*employee).nombre, "");
    (*employee).horasTrabajadas = 0;
    (*employee).sueldo = 0;

    return employee;
};

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* employee;
    employee = (Employee*)malloc(sizeof(Employee));
    employee_setId(employee,atoi(idStr));
    employee_setNombre(employee,nombreStr);
    employee_setHorasTrabajadas(employee,atoi(horasTrabajadasStr));
    employee_setSueldo(employee,atoi(sueldoStr));


    return employee;
};

void employee_delete()
{

};

int employee_setId(Employee* this,int id)
{
    int ret;
    ret = 0;

    if( id > 0 && this != NULL)
    {
        (*this).id = id;
        ret=1;
    }

    return ret;
};

int employee_getId(Employee* this,int* id)
{
    int ret;
    ret = 0;

    if( this != NULL )
    {
        *id= (*this).id;
        ret = 1;

    }

    return ret;
};

int employee_setNombre(Employee* this,char* nombre)
{
    int ret;
    ret = 0;

    if(this != NULL)
    {
        strcpy((*this).nombre, nombre);
        ret=1;
    }

    return ret;
};
int employee_getNombre(Employee* this,char* nombre)
{
  int ret;
    ret = 0;

    if(this != NULL)
    {
        strcpy(nombre,(*this).nombre);
        ret=1;
    }

    return ret;
};

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
     int ret;
    ret = 0;

    if(this != NULL)
    {
        (*this).horasTrabajadas= horasTrabajadas;
        ret=1;
    }

    return ret;
};
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
   int ret;
    ret = 0;

    if(this != NULL)
    {
        *horasTrabajadas = (*this).horasTrabajadas;
        ret=1;
    }

    return ret;
};
int employee_setSueldo(Employee* this,int sueldo)
{
      int ret;
    ret = 0;

    if(this != NULL)
    {
        (*this).sueldo= sueldo;
        ret=1;
    }

    return ret;
};

int employee_getSueldo(Employee* this,int* sueldo)
{
    int ret;
    ret = 0;

    if(this != NULL)
    {
        *sueldo = (*this).sueldo;
        ret=1;
    }

    return ret;
};
void employee_showEmployee(Employee* this)
{
    if(this != NULL )
    {
        printf ( " %4d  %s  %d  %d \n\n " , (*this).id , (*this).nombre , (*this).horasTrabajadas , (*this).sueldo);
        fflush(stdout);
    }
}

void employee_showEmployees(LinkedList* this)
{
    Employee* employee;

    if(this != NULL )
    {
        for(int i=0; i<ll_len(this);i++)
        {
            employee = ll_get(this, i+1);
            employee_showEmployee(employee);
        }
    }
    else
    {
        printf("No hay empleados cargados\n\n");
        fflush(stdout);
        system("pause");
    }

}

int employee_sortByName(void* empleadoA, void* empleadoB)
{
    int ret;
    ret = strcmp(((Employee*)empleadoA)->nombre, ((Employee*)empleadoB)->nombre);
    return ret;
}


int employee_sortById(void* empleadoA, void* empleadoB)
{
    int ret;
    if(((Employee*)empleadoA)->id > ((Employee*)empleadoB)->id)
    {
        ret = 1;
    } if(((Employee*)empleadoA)->id < ((Employee*)empleadoB)->id)
    {
        ret = -1;
    }
    else
    {
        ret = 0;
    }
    return ret;

}

int employee_sortByHsTrabajadas(void* empleadoA, void* empleadoB)
{
    int ret;
    if(((Employee*)empleadoA)->horasTrabajadas > ((Employee*)empleadoB)->horasTrabajadas)
    {
        ret = 1;
    }
    else if(((Employee*)empleadoA)->horasTrabajadas < ((Employee*)empleadoB)->horasTrabajadas)
    {
        ret = -1;
    }
    else
    {
        ret = 0;
    }
    return ret;
}

int employee_sortBySueldo(void* empleadoA, void* empleadoB)
{
    int ret;
    if(((Employee*)empleadoA)->sueldo > ((Employee*)empleadoB)->sueldo)
    {
        ret = 1;
    }
    else if(((Employee*)empleadoA)->sueldo < ((Employee*)empleadoB)->sueldo)
    {
        ret = -1;
    }
    else
    {
        ret = 0;
    }
    return ret;
};







