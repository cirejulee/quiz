#include <string.h>
#include "employee.h"

// Define a function pointer type for search functions
typedef PtrToEmployee (*SearchFunction)(const Employee[], int, const void*);

// Function to search the employee table based on the provided search function
static PtrToEmployee searchEmployeeTable(PtrToConstEmployee ptr, int tableSize, const void* targetPtr,
                                        int (*functionPtr)(const void*, PtrToConstEmployee)) {
    PtrToConstEmployee endPtr = ptr + tableSize;

    for (; ptr < endPtr; ptr++) {
        if ((*functionPtr)(targetPtr, ptr) == 0) {
            return (PtrToEmployee)ptr;
        }
    }

    return NULL;
}


static int compareEmployeePhoneNumber(const void* targetPtr, PtrToConstEmployee tableValuePtr) {
    return strcmp((char*)targetPtr, tableValuePtr->phone);
}


PtrToEmployee searchEmployeeByPhoneNumber(PtrToConstEmployee ptr, int size, const char* phoneNumber) {
    return searchEmployeeTable(ptr, size, phoneNumber, compareEmployeePhoneNumber);
}


static int compareEmployeeSalary(const void* targetPtr, PtrToConstEmployee tableValuePtr) {
    return *(double*)targetPtr != tableValuePtr->salary;
}


PtrToEmployee searchEmployeeBySalary(PtrToConstEmployee ptr, int size, double salary) {
    return searchEmployeeTable(ptr, size, &salary, compareEmployeeSalary);
}


static int compareEmployeeNumber(const void* targetPtr, PtrToConstEmployee tableValuePtr) {
    return *(long*)targetPtr != tableValuePtr->number;
}

PtrToEmployee searchEmployeeByNumber(PtrToConstEmployee ptr, int size, long targetNumber) {
    return searchEmployeeTable(ptr, size, &targetNumber, compareEmployeeNumber);
}


static int compareEmployeeName(const void* targetPtr, PtrToConstEmployee tableValuePtr) {
    return strcmp((char*)targetPtr, tableValuePtr->name);
}


PtrToEmployee searchEmployeeByName(PtrToConstEmployee ptr, int size, char* targetName) {
    return searchEmployeeTable(ptr, size, targetName, compareEmployeeName);
}
