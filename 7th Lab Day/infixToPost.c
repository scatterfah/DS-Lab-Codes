#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

struct node {
    char data;
    struct node *next;
};

struct node *start = NULL;

int precedence(char op){
    if(op == '+' || op == '-')
        return 1;
    if(op == '*' || op == '/')
        return 2;
    return 0;
}

void push(char a){
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));

    newnode -> data = a;
    newnode -> next = start;
    start = newnode;
}

char pop(){
    struct node *i = start;
    char a = i -> data;

    start = start -> next;
    free(i);

    return a;
}

char peek(){
    return start -> data;
}

char *infixToPostfix(char infix[]){
    static char postfix[100];
    int i = 0, j = 0;

    start = NULL;

    while(infix[i] != '\0'){

        char c = infix[i];

        if(isalnum((unsigned char)c)){
            postfix[j] = c;
            j++;
        }

        else if(c == '('){
            push(c);
        }

        else if(c == ')'){
            while(start != NULL && peek() != '('){
                postfix[j] = pop();
                j++;
            }

            if(start != NULL){
                pop();
            }
        }

        else{
            while(start != NULL && peek() != '(' &&
                  precedence(c) <= precedence(peek())){
                postfix[j] = pop();
                j++;
            }

            push(c);
        }

        i++;
    }

    while(start != NULL){
        postfix[j] = pop();
        j++;
    }

    postfix[j] = '\0';

    return postfix;
}

int main(){
    char infix[100];

    printf("Enter the infix expression: ");
    scanf("%99s", infix);

    printf("Infix Expression: %s\n", infix);
    printf("Postfix Expression: %s\n", infixToPostfix(infix));

    return 0;
}