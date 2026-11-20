/*
Name: Samta Prajapati
Roll No: CO2122
Title: Hospital Patient Registration System using Queue
*/
#include <stdio.h>
#define MAX 5

struct Patient {
    int patientID;
    int arrivalTime;
};

struct Patient queue[MAX];
int front = -1, rear = -1;

void addPatient(int patientID, int arrivalTime) {
    if (rear == MAX - 1) {
        printf("Queue Overflow! Cannot add patient.\n");
        return;
    }
    if (front == -1)
        front = 0;
    rear++;
    queue[rear].patientID = patientID;
    queue[rear].arrivalTime = arrivalTime;
    printf("Patient added successfully.\n");
}

void attendPatient() {
    if (front == -1) {
        printf("Queue Underflow! No patients waiting.\n");
        return;
    }
    printf("Attending Patient ID: %d, Arrival Time: %d\n",
           queue[front].patientID,
           queue[front].arrivalTime);
    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
}

void viewPatients() {
    int i;
    if (front == -1) {
        printf("No patients waiting.\n");
        return;
    }
    printf("\nWaiting Patients:\n");
    printf("Patient ID\tArrival Time\n");
    for (i = front; i <= rear; i++) {
        printf("%d\t\t%d\n",
               queue[i].patientID,
               queue[i].arrivalTime);
    }
}

void isQueueEmpty() {
    if (front == -1)
        printf("The queue is empty.\n");
    else
        printf("The queue is not empty.\n");
}

int main() {
    int choice, patientID, arrivalTime;
    do {
        printf("\n--- Hospital Patient Registration System ---\n");
        printf("1. Add Patient\n");
        printf("2. Attend Patient\n");
        printf("3. View Patients\n");
        printf("4. Check Queue Empty\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter Patient ID: ");
                scanf("%d", &patientID);
                printf("Enter Arrival Time: ");
                scanf("%d", &arrivalTime);
                addPatient(patientID, arrivalTime);
                break;
            case 2:
                attendPatient();
                break;
            case 3:
                viewPatients();
                break;
            case 4:
                isQueueEmpty();
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 5);
    return 0;
}

/*OUTPUT
--- Hospital Patient Registration System ---
1. Add Patient
2. Attend Patient
3. View Patients
4. Check Queue Empty
5. Exit
Enter your choice: 1
Enter Patient ID: 101
Enter Arrival Time: 10
Patient added successfully.

--- Hospital Patient Registration System ---
1. Add Patient
2. Attend Patient
3. View Patients
4. Check Queue Empty
5. Exit
Enter your choice: 1
Enter Patient ID: 102
Enter Arrival Time: 11
Patient added successfully.

--- Hospital Patient Registration System ---
1. Add Patient
2. Attend Patient
3. View Patients
4. Check Queue Empty
5. Exit
Enter your choice: 3
Waiting Patients:
Patient ID Arrival Time
101
10
102
11

--- Hospital Patient Registration System ---
1. Add Patient
2. Attend Patient
3. View Patients
4. Check Queue Empty
5. Exit
Enter your choice: 2
Attending Patient ID: 101, Arrival Time: 10

--- Hospital Patient Registration System ---
1. Add Patient
2. Attend Patient
3. View Patients
4. Check Queue Empty
5. Exit
Enter your choice: 4
The queue is not empty.

--- Hospital Patient Registration System ---
1. Add Patient
2. Attend Patient
3. View Patients
4. Check Queue Empty
5. Exit
Enter your choice: 5
Exiting the program.
*/
