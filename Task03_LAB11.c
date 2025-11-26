#include <stdio.h>

#define MAX_EMPLOYEES 100

typedef struct {
    char name[50];
    int id;
    int daysPresent;
} Employee;

int totalAttendance(Employee emp[], int n) {
    if(n == 0) return 0;
    return emp[n-1].daysPresent + totalAttendance(emp, n-1);
}

int main() {
    Employee emp[MAX_EMPLOYEES];
    int n, i, minimumDays;
    printf("EMPLOYEE ATTENDANCE TRACKER\n");
    printf("___________________________\n");
    printf("\nEnter number of employees: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("\nEnter name of employee %d: ", i+1);
        scanf("%s", &emp[i].name);
         printf("Enter ID for employee %d: ", i+1);
        scanf("%d", &emp[i].id);
         printf("Enter number of presents for employee %d: ", i+1);
        scanf("%d", &emp[i].daysPresent);
        printf("________________________________________\n");
    }

    printf("\nTotal attendance: %d\n", totalAttendance(emp, n));

    printf("Enter minimum required days: ");
    scanf("%d", &minimumDays);
    
    if(emp[i].daysPresent>minimumDays)
      printf("\nEmployees inddividual attendance is not scarce\n");
    else{
    for(i = 0; i < n; i++) {
        	printf("\nEmployees with less than %d days:\n", minimumDays);
            printf("%s (ID: %d) - %d days\n", emp[i].name, emp[i].id, emp[i].daysPresent);
        }
}

    return 0;
}

