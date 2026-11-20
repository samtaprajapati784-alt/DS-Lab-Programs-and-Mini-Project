/* Title: Browser Navigation System using Stack
Name: Samta Prajapati
Roll No: CO2122
*/
#include <stdio.h>
#include <string.h>
#define MAX 50
#define SIZE 100

int main() {
    char Backstack[MAX][SIZE];
    char Forwardstack[MAX][SIZE];
    int Backtop = -1;
    int Forwardtop = -1;
    char currentpage[SIZE] = "Home";
    char newpage[SIZE];
    int choice;

    do {
        printf("\n\n----- MENU ------");
        printf("\n1. Visit New Page");
        printf("\n2. Back");
        printf("\n3. Forward");
        printf("\n4. Display Current Page");
        printf("\n5. Exit");
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                /* Visit New Page */
                if (Backtop == MAX - 1) {
                    printf("\nBack Stack Overflow!");
                } else {
                    printf("\nEnter New Page: ");
                    scanf("%99s", newpage);

                    /* Push current page into Back Stack */
                    Backtop++;
                    strcpy(Backstack[Backtop], currentpage);

                    /* Make new page current */
                    strcpy(currentpage, newpage);

                    /* Clear Forward Stack */
                    Forwardtop = -1;

                    printf("\nCurrent Page: %s", currentpage);
                }
                break;

            case 2:
                /* Back */
                if (Backtop == -1) {
                    printf("\nNo Previous Page Available");
                } else {
                    /* Push current page into Forward Stack */
                    Forwardtop++;
                    strcpy(Forwardstack[Forwardtop], currentpage);

                    /* Pop page from Back Stack */
                    strcpy(currentpage, Backstack[Backtop]);
                    Backtop--;

                    printf("\nCurrent Page: %s", currentpage);
                }
                break;

            case 3:
                /* Forward */
                if (Forwardtop == -1) {
                    printf("\nNo Forward Page Available");
                } else {
                    /* Push current page into Back Stack */
                    Backtop++;
                    strcpy(Backstack[Backtop], currentpage);

                    /* Pop page from Forward Stack */
                    strcpy(currentpage, Forwardstack[Forwardtop]);
                    Forwardtop--;

                    printf("\nCurrent Page: %s", currentpage);
                }
                break;

            case 4:
                /* Display Current Page */
                printf("\nCurrent Page: %s", currentpage);
                break;

            case 5:
                printf("\nExit\n");
                break;

            default:
                printf("\nInvalid Choice");
        }
    } while (choice != 5);

    return 0;
}

/*OUTPUT
MENU
1. Visit New Page
2. Back
3. Forward
4. Display Current Page
5. Exit
Enter your choice: 1
Enter New Page: Google
Current Page: Google

MENU
1. Visit New Page
2. Back
3. Forward
4. Display Current Page
5. Exit
Enter your choice: 1
Enter New Page: YouTube
Current Page: YouTube

MENU
1. Visit New Page
2. Back
3. Forward
4. Display Current Page
5. Exit
Enter your choice: 1
Enter New Page: GitHub
Current Page: GitHub

MENU
1. Visit New Page
2. Back
3. Forward
4. Display Current Page
5. Exit
Enter your choice: 2
Current Page: YouTube

MENU
1. Visit New Page
2. Back
3. Forward
4. Display Current Page
5. Exit
Enter your choice: 2
Current Page: Google

MENU
1. Visit New Page
2. Back
3. Forward
4. Display Current Page
5. Exit
Enter your choice: 3
Current Page: YouTube

MENU
1. Visit New Page
2. Back
3. Forward
4. Display Current Page
5. Exit
Enter your choice: 4
Current Page: YouTube

MENU
1. Visit New Page
2. Back
3. Forward
4. Display Current Page
5. Exit
Enter your choice: 5
Exit
*/
