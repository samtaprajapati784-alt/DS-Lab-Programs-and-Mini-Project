/*
Name: Samta Prajapati
Roll No: CO2122
*/
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a BST node
struct Node {
    int rollNo;
    char name[50];
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int rollNo, const char* name) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->rollNo = rollNo;
    snprintf(newNode->name, sizeof(newNode->name), "%s", name);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// a. Add a new student record into the tree
struct Node* insert(struct Node* root, int rollNo, const char* name) {
    if (root == NULL) {
        return createNode(rollNo, name);
    }
    if (rollNo < root->rollNo) {
        root->left = insert(root->left, rollNo, name);
    } else if (rollNo > root->rollNo) {
        root->right = insert(root->right, rollNo, name);
    } else {
        printf("Roll Number %d already exists!\n", rollNo);
    }
    return root;
}

// Find the minimum roll number
struct Node* findMin(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// b. Remove a student record
struct Node* deleteNode(struct Node* root, int rollNo) {
    if (root == NULL) {
        return root;
    }
    if (rollNo < root->rollNo) {
        root->left = deleteNode(root->left, rollNo);
    } else if (rollNo > root->rollNo) {
        root->right = deleteNode(root->right, rollNo);
    } else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = findMin(root->right);
        root->rollNo = temp->rollNo;
        snprintf(root->name, sizeof(root->name), "%s", temp->name);
        root->right = deleteNode(root->right, temp->rollNo);
    }
    return root;
}

// c. Search for a student
struct Node* search(struct Node* root, int rollNo) {
    if (root == NULL || root->rollNo == rollNo) {
        return root;
    }
    if (root->rollNo < rollNo) {
        return search(root->right, rollNo);
    }
    return search(root->left, rollNo);
}

// d. Inorder traversal
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("Roll No: %d | Name: %s\n", root->rollNo, root->name);
        inorder(root->right);
    }
}

// Preorder traversal
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("Roll No: %d | Name: %s\n", root->rollNo, root->name);
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder traversal
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("Roll No: %d | Name: %s\n", root->rollNo, root->name);
    }
}

// Main function
int main() {
    struct Node* root = NULL;
    int choice, rollNo;
    char name[50];

    while (1) {
        printf("\n--- Student BST Management System ---\n");
        printf("1. Add a new student record (Insert)\n");
        printf("2. Remove a student record (Delete)\n");
        printf("3. Search for a student record\n");
        printf("4. Display records (Inorder - Sorted)\n");
        printf("5. Display records (Preorder)\n");
        printf("6. Display records (Postorder)\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1)
            break;

        switch (choice) {
            case 1:
                printf("Enter Roll Number: ");
                scanf("%d", &rollNo);
                printf("Enter Student Name: ");
                scanf("%49s", name);
                root = insert(root, rollNo, name);
                break;
            case 2:
                printf("Enter Roll Number to remove: ");
                scanf("%d", &rollNo);
                root = deleteNode(root, rollNo);
                printf("Record removed (if it existed).\n");
                break;
            case 3:
                printf("Enter Roll Number to search: ");
                scanf("%d", &rollNo);
                {
                    struct Node* found = search(root, rollNo);
                    if (found != NULL) {
                        printf("Student Found -> Roll No: %d | Name: %s\n",
                               found->rollNo, found->name);
                    } else {
                        printf("Student with Roll No %d not found.\n", rollNo);
                    }
                }
                break;
            case 4:
                printf("\n--- Inorder Traversal ---\n");
                inorder(root);
                break;
            case 5:
                printf("\n--- Preorder Traversal ---\n");
                preorder(root);
                break;
            case 6:
                printf("\n--- Postorder Traversal ---\n");
                postorder(root);
                break;
            case 7:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

/*OUTPUT
--- Student BST Management System ---
1. Add a new student record (Insert)
2. Remove a student record (Delete)
3. Search for a student record
4. Display records (Inorder - Sorted)
5. Display records (Preorder)
6. Display records (Postorder)
7. Exit
Enter your choice: 1
Enter Roll Number: 30
Enter Student Name: Rahul
Enter your choice: 1
Enter Roll Number: 20
Enter Student Name: Amit
Enter your choice: 1
Enter Roll Number: 40
Enter Student Name: Priya
Enter your choice: 1
Enter Roll Number: 10
Enter Student Name: Neha
Enter your choice: 1
Enter Roll Number: 25
Enter Student Name: Riya
Enter your choice: 4
--- Inorder Traversal ---
Roll No: 10 | Name: Neha
Roll No: 20 | Name: Amit
Roll No: 25 | Name: Riya
Roll No: 30 | Name: Rahul
Roll No: 40 | Name: Priya
Enter your choice: 5
--- Preorder Traversal ---
Roll No: 30 | Name: Rahul
Roll No: 20 | Name: Amit
Roll No: 10 | Name: Neha
Roll No: 25 | Name: Riya
Roll No: 40 | Name: Priya
Enter your choice: 6
--- Postorder Traversal ---
Roll No: 10 | Name: Neha
Roll No: 25 | Name: Riya
Roll No: 20 | Name: Amit
Roll No: 40 | Name: Priya
Roll No: 30 | Name: Rahul
Enter your choice: 3
Enter Roll Number to search: 25
Student Found -> Roll No: 25 | Name: Riya
Enter your choice: 2
Enter Roll Number to remove: 20
Record removed (if it existed).
Enter your choice: 4
--- Inorder Traversal ---
Roll No: 10 | Name: Neha
Roll No: 25 | Name: Riya
Roll No: 30 | Name: Rahul
Roll No: 40 | Name: Priya
Enter your choice: 7
Exiting program.
*/

