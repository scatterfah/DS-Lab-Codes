#include<stdio.h>
#include<stdlib.h>

struct student { 
    int id; 
    char name;
    struct student *next;
    };

    struct student *start = NULL;

    void traverse(){
        printf("Tranverse function call\n");
    struct student *i = start;
    while(i != NULL){
        printf("%d %c\n", i->id, i->name);
        i = i->next;
    }
    }

    struct student *creat_node(){
        int a;
        char b;
        printf("Enter the id: \n");
        scanf("%d",&a);
        printf("Enter the name: \n");
        scanf(" %c",&b);

        struct student *newnode;
        newnode = (struct student*)malloc(sizeof(struct student));
        newnode -> id = a;
        newnode -> name = b;
        newnode -> next = NULL;
        return newnode;
    }

    void insert_last(){
        printf("Insert Last function call\n");
        struct student *newnode = creat_node();
        if(start == NULL){
            start = newnode;
        }
        else {
            struct student *i = start;
            while(i -> next != NULL){
                i = i->next; 
            }
            i -> next = newnode;
        }
    } 
    
    void insert_first(){
        printf("Insert Fist function call\n");
        struct student *newnode = creat_node();
        if(start == NULL){
            start = newnode;
        }
        else {
            newnode -> next = start;
            start = newnode;
        }
    }
    void insert_any(){
        printf("Insert any function call\n");
        struct student *newnode = creat_node();
        int search;
        printf("After which you want to insert: ");
        scanf("%d",&search);
        if(start == NULL){
            start = newnode;
        }
        else{
            struct student *i = start;
            while(i != NULL){
                if(i -> id == search){
                    newnode -> next = i -> next;
                    i -> next = newnode;
                }
                i = i -> next;
            }
        }
    }
    void delete_first(){
        printf("Delete Fist function call\n");
        if(start == NULL){
            printf("Underflow\n");
        }
        else{
            start = start -> next;
        }
    }
    void delete_last(){
        printf("Delete last function call\n");
        if(start == NULL){
            printf("Underflow\n");
        }
        else if(start -> next == NULL){
            start = NULL;
        }
        else{
            struct student *i = start;
            while(i -> next -> next != NULL){
                i = i -> next;
            }
            i -> next = NULL;
        }
        
    }
int main() { 
    insert_last();
    traverse();
    delete_last();
    traverse();
    
    return 0;
    }