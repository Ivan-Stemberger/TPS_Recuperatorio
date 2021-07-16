#ifndef EMPLOYEE_H_
#define EMPLOPYEE_H_

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}Employee;

int initEmployees(Employee* employee, int len);
int add_newEmployee(Employee* employee, int len);
int addEmployee(Employee* employee, int id, char name[],char lastName[],float salary,int sector);
int findEmployeeById(Employee* employee, int len, int id);
int modifyEmployee(Employee* employee, int len,int id);
int removeEmployee(Employee* employee, int len, int id);
int sortEmployees(Employee employee[], int len, int order);
void sortByNameAscend(Employee employee[],int len);
void sortByNameDescend(Employee* employee,int len);
void sortBySectorAscend(Employee* employee,int len);
void sortBySectorDescend(Employee* employee,int len);
int nameCriteria(Employee A, Employee B);
int sectorCriteria(Employee A, Employee B);
int printEmployees(Employee* employee, int length);
void salaryAverage(Employee* employee, int len);
void setEmployeeName(Employee* employee, char name[]);
void setEmployeeLastName(Employee* employee, char lastName[]);
void setEmployeeSalary(Employee* employee, float salary);
void setEmployeeSector(Employee* employee, int sector);






#endif /* EMPLOYEE_H_ */
