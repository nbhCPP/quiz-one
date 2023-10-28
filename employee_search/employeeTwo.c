#include <string.h>
#include "employee.h"

// These are the comparison functions used by searchEmployeeTable.
static int compareEmployeeNumber(const void *targetPtr, PtrToConstEmployee tableValuePtr) {
    return *((long *)targetPtr) != tableValuePtr->number;
}

static int compareEmployeeName(const void *targetPtr, PtrToConstEmployee tableValuePtr) {
    return strcmp((char *)targetPtr, tableValuePtr->name);
}

static int compareEmployeePhone(const void *targetPtr, PtrToConstEmployee tableValuePtr) {
    return strcmp((char *)targetPtr, tableValuePtr->phone);
}

static int compareEmployeeSalary(const void *targetPtr, PtrToConstEmployee tableValuePtr) {
    return *((double *)targetPtr) != tableValuePtr->salary;
}

// This is the generic search function for both number and name.
static PtrToEmployee searchEmployeeTable(PtrToConstEmployee ptr, int tableSize, const void *targetPtr,
    int (*functionPtr)(const void *, PtrToConstEmployee)) {
    PtrToConstEmployee endPtr = ptr + tableSize;

    for (; ptr < endPtr; ptr++) {
        if ((*functionPtr)(targetPtr, ptr) == 0) {
            return (PtrToEmployee)ptr;
        }
    }

    return NULL;
}

// These are wrapper functions that you'll use in your main code.
PtrToEmployee searchEmployeeByNumber(PtrToConstEmployee ptr, int size, long number) {
    return searchEmployeeTable(ptr, size, &number, compareEmployeeNumber);
}

PtrToEmployee searchEmployeeByName(PtrToConstEmployee ptr, int size, char *name) {
    return searchEmployeeTable(ptr, size, name, compareEmployeeName);
}

PtrToEmployee searchEmployeeByPhone(PtrToConstEmployee ptr, int size, char *phone) {
    return searchEmployeeTable(ptr, size, phone, compareEmployeePhone);
}

PtrToEmployee searchEmployeeBySalary(PtrToConstEmployee ptr, int size, double salary) {
    return searchEmployeeTable(ptr, size, &salary, compareEmployeeSalary);
}