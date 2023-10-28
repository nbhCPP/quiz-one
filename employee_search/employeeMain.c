#include <string.h>
#include <stdlib.h>
#include "employee.h"

int main(void) {
    // Functions defined in employeeSearchOne.c
    PtrToEmployee searchEmployeeByPhone(const Employee table[], int sizeTable, char *numberToFind);
    PtrToEmployee searchEmployeeBySalary(const Employee table[], int sizeTable, double salary);
    PtrToEmployee searchEmployeeByNumber(const Employee table[], int sizeTable, long numberToFind);
    PtrToEmployee searchEmployeeByName(const Employee table[], int sizeTable, char *nameToFind);
    

    // Variables and constants defined in employeeTable.c
    extern Employee EmployeeTable[];
    extern const int EmployeeTableEntries;

    PtrToEmployee matchPtr; // Declaration
    matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, 1045);

    // Example: Not found
    if (matchPtr != NULL) {
        printf("Employee ID 1045 is in record %d\n", matchPtr - EmployeeTable);
    } else {
        printf("Employee ID is NOT found in the record\n");
    }

    // Example: Found
    matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Tony Bobcat");
    if (matchPtr != NULL) {
        printf("Employee Tony Bobcat is in record %d\n", matchPtr - EmployeeTable);
    } else {
        printf("Employee Tony Bobcat is NOT found in the record\n");
    }

    // Example: Found
    matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "909-555-2134");
    if (matchPtr != NULL) {
        printf("Employee phone number 909-555-2134 is in record %d\n", matchPtr - EmployeeTable);
    } else {
        printf("Employee phone number 909-555-2134 is NOT found in the record\n");
    }

    // Example: Not found
    matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "123-456-789");
    if (matchPtr != NULL) {
        printf("Employee phone number 123-456-789 is in record %d\n", matchPtr - EmployeeTable);
    } else {
        printf("Employee phone number 123-456-789 is NOT found in the record\n");
    }

    // Example: Found
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 8.32);
    if (matchPtr != NULL) {
        printf("Employee salary 8.32 is in record %d\n", matchPtr - EmployeeTable);
    } else {
        printf("Employee salary 8.32 is NOT found in the record\n");
    }

    // Example: Not found
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 10.5);
    if (matchPtr != NULL) {
        printf("Employee salary 10.5 is in record %d\n", matchPtr - EmployeeTable);
    } else {
        printf("Employee salary 10.5 is NOT found in the record\n");
    }

    return EXIT_SUCCESS;
}