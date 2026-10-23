// Write a c program to implement Queue using link list.
#include<stdio.h>
#include<stdlib.h>

struct student {
    int id;
    char name;
    struct student *next;
};

struct student *front = NULL;
struct student *rear = NULL;

void traverse(){
    printf("Traverse function call\n");

    struct student *i = front;

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

void insert(){
    printf("Insert function call\n");

    struct student *newnode = creat_node();

    if(front == NULL){
        front = newnode;
        rear = newnode;
    }
    else{
        rear -> next = newnode;
        rear = newnode;
    }
}

void delete(){
    printf("Delete function call\n");

    if(front == NULL){
        printf("Underflow\n");
    }
    else{
        struct student *i = front;
        front = front -> next;

        if(front == NULL){
            rear = NULL;
        }

        free(i);
    }
}

int main(){
    insert();
    insert();
    insert();

    traverse();

    delete();

    traverse();

    return 0;
}
