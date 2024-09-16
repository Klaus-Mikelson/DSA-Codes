#include <stdio.h>
#include <stdlib.h>

struct LL {
    int roll;
    char name[20];
    float marks;
    struct LL *next;
};

void display(struct LL *ptr) {
    int student_count = 1;

    if (ptr == NULL) {
        printf("No student data available.\n");
        return;
    }

    while (ptr != NULL) {
        printf("\nStudent %d Details:\n", student_count);
        printf("Name   : %s\n", ptr->name);
        printf("Roll No: %d\n", ptr->roll);
        printf("Marks  : %.2f\n", ptr->marks);
        ptr = ptr->next;
        student_count++;
    }
}

struct LL* createnode(){
    struct LL *new_node=(struct LL*)malloc(sizeof(struct LL));
    if(new_node==NULL){
        printf("Memory allocation failed\n");
        exit(1);
    }

    printf("Enter Name: ");
    scanf("%s", new_node->name);

    printf("Enter Roll No: ");
    scanf("%d", &new_node->roll);

    printf("Enter Marks: ");
    scanf("%f", &new_node->marks);

    new_node->next=NULL;
    return new_node;

}


struct LL* deleteStudent(struct LL *head,int rollno){
    struct LL* temp=head;
    struct LL* prev;

    if (temp!=NULL && temp->roll==rollno)
    {
        head=temp->next;
        free(temp);
        return head;
    }

    while (temp!=NULL && temp->roll!=rollno)
    {
        prev=temp;
        temp=temp->next;   
    }
    
    if(temp==NULL){
        printf("Student with roll no %d does not found\n",rollno);
        return head;
    }
    
    prev->next=temp->next;
    free(temp);
    printf("Deleted Successfully\n");
    return head;
    
}

void searchStudent(struct LL *head, int rollno) {
    struct LL* temp = head;

    while (temp != NULL) {
        if (temp->roll == rollno) {
            printf("\nStudent Details:\n");
            printf("Name   : %s\n", temp->name);
            printf("Roll No: %d\n", temp->roll);
            printf("Marks  : %.2f\n", temp->marks);
            return;
        }
        temp = temp->next;
    }

    printf("Student details with Roll No %d not found.\n", rollno);
}


int main(){
struct LL *head = NULL, *temp = NULL, *new_node = NULL;
    int choice, roll;

        printf("\nMenu:\n");
        printf("1) Add Student Details\n");
        printf("2) Delete Student Details\n");
        printf("3) Search Student Details\n");
        printf("4) Display All Records\n");
        printf("5) Exit\n");
    do {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                new_node = createnode();
                if (head == NULL) {
                    head = new_node;
                } else {
                    temp->next = new_node;
                }
                temp = new_node;
                break;

            case 2:
                printf("Enter Roll No of student to delete: ");
                scanf("%d", &roll);
                head = deleteStudent(head, roll);
                break;

            case 3:
                printf("Enter Roll No of student to search: ");
                scanf("%d", &roll);
                searchStudent(head, roll);
                break;

            case 4:
                display(head);
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}