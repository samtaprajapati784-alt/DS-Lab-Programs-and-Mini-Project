/*
Title: Roll No Sorting System Using Bubble Sort
Name: Samta Prajapati
Roll No: CO2122
*/
#include <stdio.h>

int main() {
    int rollno[20], n = 0, i, j, k, choice, temp;

    do {
        printf("\n====== MENU ======");
        printf("\n1. Insert Roll No");
        printf("\n2. Sort Roll No");
        printf("\n3. Display Roll No");
        printf("\n4. Exit");
        printf("\nEnter your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter no. of Students: ");
                scanf("%d", &n);
                if (n < 1 || n > 20) {
                    printf("Invalid number of students (1 to 20).\n");
                    n = 0;
                    break;
                }
                printf("Enter roll no:\n");
                for (i = 0; i < n; i++) {
                    scanf("%d", &rollno[i]);
                }
                break;

            case 2:
                if (n == 0) {
                    printf("\nNo roll numbers inserted yet.\n");
                    break;
                }
                for (i = 0; i < n - 1; i++) {
                    for (j = 0; j < n - i - 1; j++) {
                        if (rollno[j] > rollno[j + 1]) {
                            temp = rollno[j];
                            rollno[j] = rollno[j + 1];
                            rollno[j + 1] = temp;
                        }
                    }
                    printf("\nPass %d\n", i + 1);
                    for (k = 0; k < n; k++) {
                        printf("%d\n", rollno[k]);
                    }
                }
                break;

            case 3:
                if (n == 0) {
                    printf("\nNo roll numbers to display.\n");
                    break;
                }
                printf("\nSorted roll nos are:\n");
                for (i = 0; i < n; i++) {
                    printf("%d\n", rollno[i]);
                }
                break;

            case 4:
                printf("\nExit\n");
                break;

            default:
                printf("\nInvalid Number\n");
        }
    } while (choice != 4);

    return 0;
}

/*
OUTPUT 
student@TCOERCL-VI-25:~$ cc DSPractical2.c
student@TCOERCL-VI-25:~$ ./a.out
====== MENU ======
1. Insert Roll No
2. Sort Roll No
3. Display Roll No
4. Exit
Enter your Choice: 1
Enter no. of Students: 5
Enter roll no:
25
69
75
42
78
====== MENU ======
1. Insert Roll No
2. Sort Roll No
3. Display Roll No
4. Exit
Enter your Choice: 2
# Pass 1
25
69
42
75
78
Pass 2
25
42
69
75
78
Pass 3
25
42
69
75
78
Pass 4
25
42
69
75
78
====== MENU ======
1. Insert Roll No
2. Sort Roll No
3. Display Roll No
4. Exit
Enter your Choice: 3
Sorted roll nos are:
25
42
69
75
78
====== MENU ======
1. Insert Roll No
2. Sort Roll No
3. Display Roll No
4. Exit
Enter your Choice: 4
# Exit
student@TCOERCL-VI-25:~$
*/
