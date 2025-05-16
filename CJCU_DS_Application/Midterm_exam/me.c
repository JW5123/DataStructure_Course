#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}Node;
Node *head, *new_node, *current;
Node *pre = NULL;
int value, insert, i, Index;
void Create(){
    printf("\nPlease enter the data of the 1-th node:");
    scanf("%d", &value);
    
    new_node = (Node*)malloc(sizeof(Node));
    new_node -> data = value;
    if(head == NULL){
        head = new_node;
    }
    else{
        current = head;
        while (current -> next != NULL){
            current = current -> next;
        }
        current -> next = new_node;
    }
    printf("\n\n");
}
int CurSize(Node *node){
    int size = 0;
    while (node != NULL){
        node = node -> next;
        size++;
    }
    return size;
}
void Insert(){
    current = head;
    printf("\nPlease enter the position to insert data:");
    scanf("%d", &Index);
    int size = CurSize(current);
    if(Index <= 0 || Index > size){
        printf("\nPosition error!!");
    }else{
        printf("\nPlease enter the data to insert:");
        scanf("%d", &value);
        if(Index == 1){
            new_node = (Node*)malloc(sizeof(Node));
            new_node -> data = value;
            new_node -> next = head;
            head = new_node;
        }
        else{
            i = 1;
            current = head;
            while (current != NULL){
                if (i + 1 == Index){
                    new_node = (Node*)malloc(sizeof(Node));
                    new_node -> data = value;
                    new_node -> next = current -> next;
                    current -> next = new_node;
                    break;
                }
                current = current -> next;
                i++;
            }
        }
    }
    printf("\n\n");
}
void Delete(){
    current = head;
    printf("\nPlease enter the data to delete:");
    scanf("%d", &value);
    while (current != NULL && current -> data != value){
        pre = current;
        current = current -> next;
    }
    if(current == NULL){
        printf("Not found");
    }
    else if(current == head){
        head = head -> next;
        free(current);
        current = NULL;
    }
    else{
        pre -> next = current -> next;
        free(current);
        current = NULL;
    }
    printf("\n\n");
}
void Printout(){
    current = head;
    printf("Data:\n");
    while (current != NULL){
        printf("%d", current -> data);
        if(current -> next == NULL)
            printf("");
        else
            printf("->");
        current = current -> next;
    }
    printf("\n\n");
}
int main(){
    int select;
    while(1){
        printf("\u2554\u2550\u2550  Linkedlist Operation  \u2550\u2550\u2557\n");
        printf("\u2551     1. Create Operation    "
                "\u2551\n\u2551     2. Insert Operation    "
                "\u2551\n\u2551     3. Delete Operation    "
                "\u2551\n\u2551     4. Printout Operation  "
                "\u2551\n\u2551     0. Quit\t\t     \u2551\n");
        printf("\u255A\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550"
                "\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550"
                "\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u255D\n\n");
        printf("   Please Choose [0-4] : ");
        scanf("%d", &select);
        switch (select){
        case 1:
            Create();
            break;
        case 2:
            Insert();
            break;
        case 3:
            Delete();
            break;
        case 4:
            Printout();
            break;
        case 0:
            exit(0);
            break;
        default:
            printf("\n\n=== Error input (0-4) !!\n\n");
            break;
        }
    }
    return 0;
}
