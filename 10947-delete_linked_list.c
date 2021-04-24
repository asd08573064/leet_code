
#include <stdlib.h>
#include <stdio.h>

typedef struct _Node {
    int data;
    struct _Node *next;
} Node;

void deleteNode(Node ** nd, int data);
Node* createList();


void deleteNode(Node ** nd, int data){
    Node* tmp = *nd;
    if(data == 1){
        *nd = (*nd)->next;
    }
    else{
        for(int i = 0; i < data-2; i++){
            tmp = tmp->next;
        }
        tmp->next = tmp->next->next;
    }
}




Node* createList(){
    Node *head = NULL;
    Node *tmp = NULL;
    while(1){
        int data;
        scanf("%d", &data);
        if(data>-1){
            if(head == NULL){
                head = (Node*)malloc(sizeof(Node)); 
                head->next = NULL;
                head->data = data;
                tmp = head;
            }
            else{
                Node *newnode = (Node*)malloc(sizeof(Node));
                newnode->data = data;
                newnode->next = NULL;
                tmp->next = newnode;
                tmp = newnode;
            }
        }else break;
    }
    return head;
}