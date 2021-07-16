#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "validaciones.h"

int initEmployees(Employee* employee, int len)
{

    int i;

    for(i=0;i<len;i++)
    {
        employee->isEmpty = 1;
        employee->id = 0;
        strcpy(employee->name, "");
        strcpy(employee->lastName, "");
        employee->salary = 0;
        employee->sector = 0;
        employee++;

    }

    return 1;

}

int add_newEmployee(Employee* employee, int len)
{

    char aux[51];
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int error = 0;
    int i;

    if(employee != NULL && len>0)
    {
        for(i=0;i<len;i++)
        {
            if(employee->isEmpty == 1)
            {
                do
                {
                printf("Por favor introduzca el id.\n");
                fflush(stdout);
                scanf("%s",aux);
                if(!esNumerico(aux))
                {
                    id = atoi(aux);
                }
                }while(esNumerico(aux));


                do
                {
                    printf("Por favor introduzca el nombre.\n");
                    fflush(stdout);
                    scanf("%s",aux);
                    if(!soloLetras(aux))
                    {
                        strcpy(name,aux);

                    }
                }while(soloLetras(aux));


                do
                {
                    printf("Por favor introduzca el apellido.\n");
                    fflush(stdout);
                    scanf("%s",aux);
                    if(!soloLetras(aux))
                    {
                        strcpy(lastName,aux);
                    }
                }while(soloLetras(aux));

                do
                {
                    printf("Por favor introduzca el salario.\n");
                    fflush(stdout);
                    scanf("%s",aux);
                    if(!esNumerico(aux))
                    {
                        salary = atof(aux);
                    }
                }while(esNumerico(aux));

                do
                {
                    printf("Por favor introduzca el sector.\n");
                    fflush(stdout);
                    scanf("%s",aux);
                    if(!esNumerico(aux))
                    {
                        sector = atoi(aux);
                    }
                }while(esNumerico(aux));

                addEmployee(employee, id, name, lastName, salary, sector);


                fflush(stdout);

                error = 1;
                break;

            }
            employee++;

        }
    }

    return error;
}

/** \brief sets the employee information into the element "Employee".
 *
 * \param list Employee*
 * \param len int
 * \param name char
 * \param lastName char
 * \param salary float
 * \param sector int
 * \return Return 1 if it worked or 0 if [NULL
pointer received]
 *
 */

int addEmployee(Employee* employee, int id, char name[],char lastName[],float salary,int sector)
{
    int returned = 0;

    if(employee != NULL)
    {
        employee->id = id;
        setEmployeeName(employee,name);
        setEmployeeLastName(employee,lastName);
        setEmployeeSalary(employee,salary);
        setEmployeeSector(employee,sector);
        employee->isEmpty = 0;
        returned = 1;
    }

    return returned;
}


/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param employee Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */
int findEmployeeById(Employee* employee, int len, int id)
{
    int i;
    int found =-1;

    if(len>0 && employee != NULL)
    {
        for(i=0;i<len;i++)
        {

        	if(id == employee->id)
            {

        		found = i;
                break;
            }
        	else

            employee++;
        }

    }

    return found;
}

/** \brief Modifies an Employee
 *
 * \param employee Employee*
 * \param len int
 * \param id int ID of the employee to be modified
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */
int modifyEmployee(Employee* employee, int len,int id)
{
    int position;
    int modified = -1;
    int opcion;
    char aux[50];

    if(findEmployeeById(employee, len, id) != -1)
    {

        position = findEmployeeById(employee, len, id);
        employee = employee + position;
        printf("Por favor indique que desea modificar.\n"
               "1) Nombre.\n"
               "2) Apellido.\n"
               "3) Salario.\n"
               "4) Sector\n");
        fflush(stdout);
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
            {

                printf("Por favor introduzca el nombre.\n");
                fflush(stdout);
                scanf("%s",aux);
                if(soloLetras(aux))
                {
                    setEmployeeName(employee,aux);

                }
                modified = 1;
                break;
            }

            case 2:
            {

                printf("Por favor introduzca el apellido.\n");
                fflush(stdout);
                scanf("%s",aux);
                if(soloLetras(aux))
                {
                    setEmployeeLastName(employee,aux);

                }
                modified = 1;
                break;
            }

            case 3:
            {

                printf("Por favor introduzca el Salario.\n");
                fflush(stdout);
                scanf("%s",aux);
                if(esNumerico(aux))
                {
                    setEmployeeSalary(employee,atof(aux));

                }
                modified = 1;
                break;
            }

            case 4:
            {

                printf("Por favor introduzca el Sector.\n");
                fflush(stdout);
                scanf("%s",aux);
                if(esNumerico(aux))
                {
                    setEmployeeSector(employee,atoi(aux));

                }
                modified = 1;
                break;
            }
        }


    }

    return modified;
}


/** \brief Remove an Employee by Id (set isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 *
 */
int removeEmployee(Employee* employee, int len, int id)
{

    int position;
    int removed = -1;

    if(len>0 && employee != NULL)
    {

        if(findEmployeeById(employee,len,id) == 1)
        {
            position = findEmployeeById(employee,len,id);
            employee = employee + position;
            employee->isEmpty = 1;
            removed = 0;
        }

    }

    return removed;
}



/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(Employee employee[], int len, int order)
{

    int sorted = -1;

    if(len>0 && employee!= NULL)
    {
        switch(order)
        {
            case 1:
            {
                    sortByNameAscend(employee,len);
                    sortBySectorAscend(employee,len);
                    sorted = 1;
                    break;
            }

            case 2:
            {

                    sortByNameDescend(employee,len);
                    sortBySectorDescend(employee,len);
                    sorted = 1;
                    break;
            }
        }
    }


    return sorted;
}

void sortByNameAscend(Employee employee[],int len)
{

	int i;
	int j;
	Employee aux;


	for(i=1;i<len;i++)
	{

		aux = employee[i];
		j= i - 1;

		while(j>=0 && !nameCriteria(aux,employee[j]))
		{
			employee[j+1] = employee[j];
			j--;
		}
		employee[j+1] = aux;
	}


}

void sortByNameDescend(Employee* employee,int len)
{

	int i;
		int j;
		Employee aux;


		for(i=1;i<len;i++)
		{

			aux = employee[i];
			j= i - 1;

			while(j>=0 && nameCriteria(aux,employee[j]))
			{
				employee[j+1] = employee[j];
				j--;
			}
			employee[j+1] = aux;
		}

}

void sortBySectorAscend(Employee* employee,int len)
{

	int i;
		int j;
		Employee aux;


		for(i=1;i<len;i++)
		{

			aux = employee[i];
			j= i - 1;

			while(j>=0 && !sectorCriteria(aux,employee[j]))
			{
				employee[j+1] = employee[j];
				j--;
			}
			employee[j+1] = aux;
		}

}

void sortBySectorDescend(Employee* employee,int len)
{

	int i;
		int j;
		Employee aux;


		for(i=1;i<len;i++)
		{

			aux = employee[i];
			j= i - 1;

			while(j>=0 && sectorCriteria(aux,employee[j]))
			{
				employee[j+1] = employee[j];
				j--;
			}
			employee[j+1] = aux;
		}

}


int nameCriteria(Employee A, Employee B)
{
    int criteria = 0;

    if(strcmp(A.name,B.name) > 0)
    {
        criteria = 1;
    }

    return criteria;
}

int sectorCriteria(Employee A, Employee B)
{
    int criteria = 0;

    if(A.sector > B.sector)
    {
        criteria = 1;
    }

    return criteria;
}

/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */
int printEmployees(Employee* employee, int length)
{

    int i;
    int error = 0;

    if(employee != NULL && length>0)
    {

    	printf("ID ||    Name ||  LastName   || Salary   || Sector\n");
        for(i=0;i<length;i++)
        {
            if(employee->isEmpty!=1)
            {


                printf("%d||     %s  ||    %s       ||   %f     ||    %d \n",
                employee->id, employee->name, employee->lastName, employee->salary,employee->sector);
                fflush(stdout);
            }
            employee++;
        }
        error = 1;
    }

    return error;
}

void salaryAverage(Employee* employee, int len)
{
    int i;
    int cantidad = 0;
    float promedio = 0;
    float salarios = 0;
    int superan = 0;

    for(i=0;i<len;i++)
    {
        if(employee->isEmpty == 0)
        {
            cantidad++;
            salarios = salarios + employee->salary;
        }
        employee++;
    }

    promedio = salarios / cantidad;

    for(i=0;i<len;i++)
    {
        if(employee->salary > promedio)
        {
            superan++;
        }
        employee--;
    }

    printf("El total de los salarios es: %f\n"
           "El promedio de los salarios es: %f\n"
           "La cantidad de empleados que supera el promedio es: %d\n", salarios, promedio, superan);
    fflush(stdout);

}


void setEmployeeName(Employee* employee, char name[])
{
    strcpy(employee->name,name);
}

void setEmployeeLastName(Employee* employee, char lastName[])
{
    strcpy(employee->lastName,lastName);
}

void setEmployeeSalary(Employee* employee, float salary)
{
    employee->salary = salary;
}

void setEmployeeSector(Employee* employee, int sector)
{
    employee->sector = sector;
}

