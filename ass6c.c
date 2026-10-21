#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 100

char buffer [MAX*20];  
int bufTop = 0;

int stack[MAX];          
int top = -1;

void push(char str[]) {
    int start = bufTop;
    int j = 0;
    while (str[j] != '\0') {
        buffer[bufTop] = str[j];
        bufTop++;
        j++;
    }
    buffer[bufTop] = '\0';
    bufTop++;

    top++;
    stack[top] = start;
}

void pop(char result[]) {
    int start = stack[top];
    top--;
    int j = 0;
    while (buffer[start + j] != '\0') {
        result[j] = buffer[start + j];
        j++;
    }
    result[j] = '\0';
}

int isOperand(char ch) {
    return isalnum(ch);
}

int main() {
    char postfix[MAX], infix[MAX];
    char tk, op1[MAX], op2[MAX], temp[MAX], opStr[2];
    int i = 0;

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    tk = postfix[i];

    while (tk != '\0') {
        if (isOperand(tk)) {
            temp[0] = tk;
            temp[1] = '\0';
            push(temp);
        }
        else {
            pop(op2);   
            pop(op1);   

            strcpy(temp, "(");
            strcat(temp, op1);

            opStr[0] = tk;
            opStr[1] = '\0';
            strcat(temp, opStr);

            strcat(temp, op2);
            strcat(temp, ")");

            push(temp);
        }
        i++;
        tk = postfix[i];
    }

    pop(infix);
    printf("Infix Result: %s\n", infix);

    return 0;
}