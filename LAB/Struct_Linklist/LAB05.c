#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char name[10];
    int age;
    struct node *next;
}Node;
struct node *head;

int main(){
    
    Node *node1 = (Node*)malloc(sizeof(Node));
    strcpy(node1 -> name, "David");
    node1 -> age = 20;
    node1 -> next = NULL;
    head = node1;

    Node *node2 = (Node*)malloc(sizeof(Node));
    strcpy(node2 -> name , "Tom");
    node2 -> age = 24;
    node2 -> next = NULL;
    node1 -> next = node2;

    Node *node3 = (Node*)malloc(sizeof(Node));
    strcpy(node3 -> name, "Fred");
    node3 -> age = 30;
    node2 -> next = node3;
    node3 -> next = NULL;

    int i = 1;
    while(head != NULL) {
        printf("node %d ==> 姓名 : %s\t   年齡 : %d\n", i++, head -> name, head -> age);
        head = head ->next;   
    }
    printf("\n");
    //free(head);
    
    return 0;	
}




