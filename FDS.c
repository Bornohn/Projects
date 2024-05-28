

#include <stdio.h>

#include <string.h>

// Variable to keep track of number of students
int studentCount = 0;

// Structure to store the student information
struct student {
    char firstName[50];
    char lastName[50];
    int roll;
    float exp;
    int productID[10];
} st[55];

// Function to add a student
// We are using the studentCount to add student at the last position in our array.
void add_student() {
    printf("Add the Students Details\n");
    printf("-------------------------\n");
    printf("Enter the first name of student\n");
    scanf("%s", st[studentCount].firstName);
    printf("Enter the last name of student\n");
    scanf("%s", st[studentCount].lastName);
    printf("Enter the Roll Number\n");
    scanf("%d", &st[studentCount].roll);
    printf("Enter the Spent ammount\n");
    scanf("%f", &st[studentCount].exp);
    printf("Enter the product ID of each product\n");
    for (int j = 0; j < 5; j++) {
        scanf("%d", &st[studentCount].productID[j]);
    }
    studentCount++;
}

// Function to find the student by roll number
void find_rollnumber() {
    int x;
    printf("Enter the Roll Number of the student\n");
    scanf("%d", &x);
    for (int j = 0; j < studentCount; j++) {
        if (x == st[j].roll) {
            printf("The Students Details are\n");
            printf("The First name is %s\n", st[j].firstName);
            printf("The Last name is %s\n", st[j].lastName);
            printf("The Spent amount is %f\n", st[j].exp);
            printf("The product IDs are:\n");
            for (int k = 0; k < 5; k++) {
                printf("%d\n", st[j].productID[k]);
            }
            return;
        }
    }
    printf("Student with Roll Number %d not found\n", x);
}

// Function to find the student by first name
void find_firstname() {
    char a[50];
    printf("Enter the First Name of the student\n");
    scanf("%s", a);
    int c = 0;

    for (int j = 0; j < studentCount; j++) {
        if (strcmp(st[j].firstName, a) == 0) {
            printf("The Students Details are\n");
            printf("The First name is %s\n", st[j].firstName);
            printf("The Last name is %s\n", st[j].lastName);
            printf("The Roll Number is %d\n", st[j].roll);
            printf("The Spent ammount is %f\n", st[j].exp);
            printf("The product IDs are:\n");
            for (int k = 0; k < 5; k++) {
                printf("%d\n", st[j].productID[k]);
            }
            c = 1;
            return;
        }
    }
    if (c == 0) printf("Student with First Name %s not found\n", a);
}

// Function to find the students enrolled in a particular product
void find_product() {
    int id;
    printf("Enter the product ID\n");
    scanf("%d", &id);
    int c = 0;

    for (int j = 0; j < studentCount; j++) {
        for (int d = 0; d < 5; d++) {
            if (id == st[j].productID[d]) {
                printf("The Students Details are\n");
                printf("The First name is %s\n", st[j].firstName);
                printf("The Last name is %s\n", st[j].lastName);
                printf("The Roll Number is %d\n", st[j].roll);
                printf("The Spent ammount is %f\n", st[j].exp);
                c = 1;
                break;
            }
        }
    }
    if (c == 0) printf("No students bought the Product in ID %d\n", id);
}

// Function to print the total number of students
void total_student() {
    printf("The total number of Students is %d\n", studentCount);
    printf("You can have a maximum of 50 students\n");
    printf("You can add %d more students\n", 50 - studentCount);
}

// Function to delete a student by roll number
void delete_student() {
    int a;
    printf("Enter the Roll Number which you want to delete\n");
    scanf("%d", &a);
    for (int j = 0; j < studentCount; j++) {
        if (a == st[j].roll) {
            for (int k = j; k < studentCount - 1; k++) {
                st[k] = st[k + 1];
            }
            studentCount--;
            printf("The Roll Number %d is removed successfully\n", a);
            return;
        }
    }
    printf("Student with Roll Number %d not found\n", a);
}

// Function to update a student's data
void update_student() {
    printf("Enter the roll number to update the entry: ");
    int x;
    scanf("%d", &x);
    for (int j = 0; j < studentCount; j++) {
        if (st[j].roll == x) {
            printf("1. First name\n2. Last name\n3. Roll number\n4. Expendeture\n5. Products\n");
            int z;
            scanf("%d", &z);
            switch (z) {
                case 1:
                    printf("Enter the new first name:\n");
                    scanf("%s", st[j].firstName);
                    break;
                case 2:
                    printf("Enter the new last name:\n");
                    scanf("%s", st[j].lastName);
                    break;
                case 3:
                    printf("Enter the new roll number:\n");
                    scanf("%d", &st[j].roll);
                    break;
                case 4:
                    printf("Enter the new Ammount:\n");
                    scanf("%f", &st[j].exp);
                    break;
                case 5:
                    printf("Enter the new product IDs:\n");
                    for (int k = 0; k < 5; k++) {
                        scanf("%d", &st[j].productID[k]);
                    }
                    break;
                default:
                    printf("Invalid choice\n");
                    return;
            }
            printf("UPDATED SUCCESSFULLY.\n");
            return;
        }
    }
    printf("Student with Roll Number %d not found\n", x);
}

// Interface code
int main() {
    int choice;
    int ok = 1;
    while (ok) {
        printf("The Task that you want to perform\n");
        printf("1. Add the Student Details\n");
        printf("2. Find the Student Details by Roll Number\n");
        printf("3. Find the Student Details by First Name\n");
        printf("4. Find the Student Details by Product Id\n");
        printf("5. Find the Total number of Students\n");
        printf("6. Delete the Students Details by Roll Number\n");
        printf("7. Update the Students Details by Roll Number\n");
        printf("8. Exit\n");
        printf("Enter your choice:\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_student();
                break;
            case 2:
                find_rollnumber();
                break;
            case 3:
                find_firstname();
                break;
            case 4:
                find_product();
                break;
            case 5:
                total_student();
                break;
            case 6:
                delete_student();
                break;
            case 7:
                update_student();
                break;
            case 8:
                ok = 0;
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
