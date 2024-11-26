#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}Node;

Node* create(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        printf("Memory allocation failed.\n");
        exit(0);
    }
    newNode -> data = data;
    newNode -> next = NULL;
    return newNode;
}

void insertBegin(Node** head, int data){
    Node* newNode = create(data);
    newNode -> next = *head;
    *head = newNode;
}

void insertEnd(Node** head, int data){
    Node* newNode = create(data);
    Node* temp = *head;
    if(*head == NULL){
        *head = newNode;
        return;
    }
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = newNode;
}

void insertAnywhere(Node** head, int data, int pos){
    Node* newNode = create(data);
    Node* temp = *head;
    if(pos < 1){
        printf("Invalid.\n");
        return;
    }
    if(pos == 1){
        insertBegin(head,data);
        return;
    }
    for(int i = 1; i < pos -1 && temp -> next != NULL; i++){
        temp = temp -> next;
    }
    newNode -> next = temp -> next;
    temp -> next = newNode;
}

void deleteBegin(Node** head){
    if(*head == NULL){
        printf("List is empty.\n");
        return;
    }
    Node* temp = *head;
    *head = (*head) -> next;
    free(temp);
}

void deleteEnd(Node** head){
    if(*head == NULL){
        printf("List is empty.\n");
        return;
    }
    if((*head) -> next == NULL){
        free(*head);
        *head = NULL;
        return;
    }
    Node* curr = *head;
    while(curr -> next -> next != NULL){
        curr = curr -> next;
    }
    free(curr -> next);
    curr -> next = NULL;
}

void deleteAnywhere(Node** head, int pos){
    if(*head == NULL){
        printf("List is empty.\n");
        return;
    }
    Node* curr = *head;
    Node* temp;
    if(pos == 1){
        *head = curr -> next;
        free(curr);
        return;
    }
    for(int i = 1; i < pos - 1 && curr != NULL; i++){
        curr = curr -> next;
    }
    if(curr == NULL || curr -> next == NULL) {
        printf("position invalid.\n");
        return;
    }
    temp = curr -> next;
    curr -> next = temp -> next;
    free(temp);
}


void middle(Node* head){
    if(head == NULL || head -> next == NULL){
        printf("Middle elements is :%d", head -> data);
        return;
    }
	Node* fast = head;
    Node* slow = head;
    while(fast != NULL && fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    printf("Middle elements is :%d", slow -> data);
}

int size(Node* head){
    int s = 0;
    for(int i = 0; head != NULL; i++){
        s++;
        head = head -> next;
    }
    return s;
}

void print(Node* head){
    Node* temp = head;
    if(temp == NULL){
        printf("Singly Linked list is found to be empty.\n");
        return;
    }
    while(temp != NULL){
        printf("%d -> ", temp -> data);
        temp = temp -> next;
    }
    printf("NULL\n");
}

int main(){
    Node* head = NULL;
    int choice, data, pos;
    while(1){
        printf("Enter your choices :\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
            printf("Insert at begin :\n");
            scanf("%d", &data);
            insertBegin(&head, data);
            break;
            case 2:
            printf("Insert at end :\n");
            scanf("%d", &data);
            insertEnd(&head, data);
            break;
            case 3:
            printf("Insert Position :\n");
            scanf("%d", &pos);
            printf("Insert data at that position :\n");
            scanf("%d", &data);
            insertAnywhere(&head, data, pos);
            break;
            case 4:  
            deleteBegin(&head);  
            break;  
            case 5:  
           deleteEnd(&head);  
            break;  
            case 6:  
            printf("Delete Position:\n");  
            scanf("%d", &pos);  
            deleteAnywhere(&head, pos);  
            break;
            case 7:
            middle(head);
            break;
            case 8:
            printf("Size of the linked list is: %d\n", size(head));
            break;
            case 9:
            printf("single Linked is :\n");
            print(head);
            break;
            case 10:
            printf("Exiting :\n");
            return 0;
            default:
            printf("Invalid choice.\n");
            break;
        }
    }
return 0;
}
