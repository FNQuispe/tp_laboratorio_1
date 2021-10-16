#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

} Employee;

#endif // ARRAYEMPLOYEES_H_INCLUDED

int searchFree(Employee vec[], int len);
int checkCreatedEmployees(Employee vec[], int len);
void listEmployee(Employee* vec);

int printEmployees(Employee* vec, int len);
int initEmployees(Employee* vec,int len);
int addEmployee(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector);
int getDataEmployee(Employee *list, int len);
int findEmployeeById(Employee* vec, int len, int id);
int removeEmployee(Employee* vec, int len);
int sortEmployees(Employee* vec,int len,int order);

void reportEmployees(Employee* vec,int len);
void modifyEmployee(Employee* vec, int len);
void reportSalaryTotalAverage(Employee* vec,int len);

char menuReports();


