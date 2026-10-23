//Write a c program to implement a stack using linked list.
#include<stdio.h>
#include<stdlib.h>

struct student {
    int id;
    char name;
    struct student *next;
};

struct student *start = NULL;

void traverse(){
    printf("Traverse function call\n");

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

void push(){
    printf("Push function call\n");

    struct student *newnode = creat_node();

    if(start == NULL){
        start = newnode;
    }
    else{
        newnode -> next = start;
        start = newnode;
    }
}

void pop(){
    printf("Pop function call\n");

    if(start == NULL){
        printf("Underflow\n");
    }
    else{
        struct student *i = start;
        start = start -> next;
        free(i);
    }
}

void peek(){
    printf("Peek function call\n");

    if(start == NULL){
        printf("Stack is empty\n");
    }
    else{
        printf("%d %c\n", start -> id, start -> name);
    }
}

int main(){
    push();
    push();
    push();

    traverse();

    pop();
    traverse();

    peek();

    return 0;
}
