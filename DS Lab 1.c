/*
Title: Program to perform different operations on array
Roll No: CO2122
*/

#include <stdio.h>

int main() {
    int arr[20], n = 0, i, j, choice, pos, key, found, mid, temp;
    int low, high;

    do {
        printf("\nMENU\n");
        printf("1. Insert Marks\n");
        printf("2. Delete Mark from Given Position\n");
        printf("3. Display All Marks\n");
        printf("4. Linear Search\n");
        printf("5. Sorted Array and Binary Search\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of students: ");
                scanf("%d", &n);
                if (n < 1 || n > 20) {
                    printf("Invalid number of students (1 to 20).\n");
                    n = 0;
                    break;
                }
                printf("Enter %d marks:\n", n);
                for (i = 0; i < n; i++) {
                    scanf("%d", &arr[i]);
                }
                break;

            case 2:
                if (n == 0) {
                    printf("Array is empty.\n");
                    break;
                }
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                if (pos < 1 || pos > n) {
                    printf("Invalid position!\n");
                } else {
                    for (i = pos - 1; i < n - 1; i++) {
                        arr[i] = arr[i + 1];
                    }
                    n--;
                    printf("Mark deleted successfully.\n");
                }
                break;

            case 3:
                if (n == 0) {
                    printf("No marks to display.\n");
                } else {
                    printf("Marks are:\n");
                    for (i = 0; i < n; i++) {
                        printf("%d ", arr[i]);
                    }
                    printf("\n");
                }
                break;

            case 4:
                if (n == 0) {
                    printf("Array is empty.\n");
                    break;
                }
                found = 0;
                printf("Enter mark to search: ");
                scanf("%d", &key);
                for (i = 0; i < n; i++) {
                    if (arr[i] == key) {
                        printf("Mark found at position %d.\n", i + 1);
                        found = 1;
                        break;
                    }
                }
                if (found == 0) {
                    printf("Mark not found.\n");
                }
                break;

            case 5:
                if (n == 0) {
                    printf("Array is empty.\n");
                    break;
                }
                for (i = 0; i < n - 1; i++) {
                    for (j = 0; j < n - i - 1; j++) {
                        if (arr[j] > arr[j + 1]) {
                            temp = arr[j];
                            arr[j] = arr[j + 1];
                            arr[j + 1] = temp;
                        }
                    }
                }
                printf("Sorted Marks:\n");
                for (i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");

                low = 0;
                high = n - 1;
                found = 0;
                printf("Enter mark to search: ");
                scanf("%d", &key);

                while (low <= high) {
                    mid = (low + high) / 2;
                    if (arr[mid] == key) {
                        printf("Mark found at position %d in sorted array.\n", mid + 1);
                        found = 1;
                        break;
                    } else if (key < arr[mid]) {
                        high = mid - 1;
                    } else {
                        low = mid + 1;
                    }
                }
                if (found == 0) {
                    printf("Mark not found in sorted array.\n");
                }
                break;

            case 6:
                printf("Exit\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 6);

    return 0;
}

/*
OUTPUT:
MENU
1. Insert Marks
2. Delete Mark from Given Position
3. Display All Marks
4. Linear Search
5. Sorted Array and Binary Search
6. Exit
Enter your choice: 1
Enter number of students: 5
Enter 5 marks:
50
78
99
45
66

MENU
1. Insert Marks
2. Delete Mark from Given Position
3. Display All Marks
4. Linear Search
5. Sorted Array and Binary Search
6. Exit
Enter your choice: 2
Enter position to delete: 3
Mark deleted successfully.

MENU
1. Insert Marks
2. Delete Mark from Given Position
3. Display All Marks
4. Linear Search
5. Sorted Array and Binary Search
6. Exit
Enter your choice: 3
Marks are:
50 78 45 66

MENU
1. Insert Marks
2. Delete Mark from Given Position
3. Display All Marks
4. Linear Search
5. Sorted Array and Binary Search
6. Exit
Enter your choice: 4
Enter mark to search: 66
Mark found at position 4.

MENU
1. Insert Marks
2. Delete Mark from Given Position
3. Display All Marks
4. Linear Search
5. Sorted Array and Binary Search
6. Exit
Enter your choice: 5
Sorted Marks:
45 50 66 78
Enter mark to search: 45
Mark found at position 1 in sorted array.

MENU
1. Insert Marks
2. Delete Mark from Given Position
3. Display All Marks
4. Linear Search
5. Sorted Array and Binary Search
6. Exit
Enter your choice: 6
Exit
*/

