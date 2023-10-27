#include <string.h> 

#include <stdlib.h> 

#include "employee.h" 


int main(void){ 


PtrToEmployee searchEmployeeByNumber(const Employee table[], int sizeTable, long numberToFind); 

PtrToEmployee searchEmployeeByName(const Employee table[], int sizeTable, char * nameToFind); 

PtrToEmployee searchEmployeeByPhoneNumber(const Employee table[], int sizeTable, char * targetPhoneNumber);

PtrToEmployee searchEmployeeBySalary(PtrToConstEmployee ptr, int tableSize, double targetSalary);

extern Employee EmployeeTable[];

extern const int EmployeeTableEntries;

PtrToEmployee matchPtr;

matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, 1045); 

if (matchPtr != NULL) 

printf("Employee ID 1045 is in record %ld\n", matchPtr - EmployeeTable); 

else 

printf("Employee ID is NOT found in the record\n"); 

 

matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Tony Bobcat"); 

if (matchPtr != NULL) 

printf("Employee Tony Bobcat is in record %ld\n", matchPtr - EmployeeTable); 

else 

printf("Employee Tony Bobcat is NOT found in the record\n"); 




char searchPhoneNumber[] = "909-555-1235";
    matchPtr = searchEmployeeByPhoneNumber(EmployeeTable, EmployeeTableEntries, searchPhoneNumber);

 if (matchPtr != NULL)
        printf("Employee with Phone Number '909-555-1235' is found at index %ld\n", matchPtr - EmployeeTable);
 else
        printf("Employee with Phone Number '909-555-1235' is NOT found in the record\n");




double searchSalary = 7.80;
matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, searchSalary);

if (matchPtr != NULL)
    printf("Employee with Salary $%.2f is found at index %ld\n", searchSalary, matchPtr - EmployeeTable);
else
    printf("Employee with Salary $%.2f is NOT found in the record\n", searchSalary);



}