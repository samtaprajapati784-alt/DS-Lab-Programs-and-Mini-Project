/*
Name: Samta Prajapati
Roll No: CO2122
Title: Library book indexing using hashing
*/
#include <stdio.h>
#define TABLE_SIZE 10
#define EMPTY -1

int hashTable[TABLE_SIZE];

void initialize()
{
    int i;
    for (i = 0; i < TABLE_SIZE; i++)
        hashTable[i] = EMPTY;
}

void insert(int key)
{
    int index = key % TABLE_SIZE;
    int i, pos;
    for (i = 0; i < TABLE_SIZE; i++)
    {
        pos = (index + i) % TABLE_SIZE;
        if (hashTable[pos] == EMPTY)
        {
            hashTable[pos] = key;
            printf("Book ID inserted successfully\n");
            return;
        }
        if (hashTable[pos] == key)
        {
            printf("Book ID already exists\n");
            return;
        }
    }
    printf("Hash table is full\n");
}

void search(int key)
{
    int index = key % TABLE_SIZE;
    int i, pos;
    for (i = 0; i < TABLE_SIZE; i++)
    {
        pos = (index + i) % TABLE_SIZE;
        if (hashTable[pos] == EMPTY)
        {
            printf("Book ID not found\n");
            return;
        }
        if (hashTable[pos] == key)
        {
            printf("Book ID found at position %d\n", pos);
            return;
        }
    }
    printf("Book ID not found\n");
}

void display()
{
    int i;
    printf("\nHash Table:\n");
    printf("Index\tBook ID\n");
    for (i = 0; i < TABLE_SIZE; i++)
    {
        printf("%d\t", i);
        if (hashTable[i] == EMPTY)
            printf("EMPTY\n");
        else
            printf("%d\n", hashTable[i]);
    }
}

int main()
{
    int choice, key;
    initialize();
    do
    {
        printf("\n--- Library Book Indexing ---\n");
        printf("1. Insert Book ID\n");
        printf("2. Search Book ID\n");
        printf("3. Display Hash Table\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter Book ID: ");
                scanf("%d", &key);
                insert(key);
                break;
            case 2:
                printf("Enter Book ID to search: ");
                scanf("%d", &key);
                search(key);
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);
    return 0;
}

/*OUTPUT
--- Library Book Indexing ---
1. Insert Book ID
2. Search Book ID
3. Display Hash Table
4. Exit
Enter your choice: 1
Enter Book ID: 101
Book ID inserted successfully
Enter your choice: 1
Enter Book ID: 111
Book ID inserted successfully
Enter your choice: 1
Enter Book ID: 121
Book ID inserted successfully
Enter your choice: 3
Hash Table:
Index Book ID
0 EMPTY
1
101
2
111
3
121
4
EMPTY
5
EMPTY
6 EMPTY
7
EMPTY
8
EMPTY
9
EMPTY
Enter your choice: 2
Enter Book ID to search: 111
Book ID found at position 2
Enter your choice: 2
Enter Book ID to search: 150
Book ID not found
Enter your choice: 4
Exiting program
*/
