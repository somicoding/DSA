#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char tkn) {
    if (top < MAX - 1) {
        stack[++top] = tkn;
    }
}

char pop() {
    if (top != -1) {
        return stack[top--];
    }
    return '\0';
}

int isOperand(char ch) {
    return isalnum(ch);
}

int icp(char ch) {
    if (ch == '+' || ch == '-') return 1;
    if (ch == '*' || ch == '/') return 2;
    if (ch == '^') return 4;
    if (ch == '(') return 5;
    return 0;
}

int isp(char ch) {
    if (ch == '+' || ch == '-') return 1;
    if (ch == '*' || ch == '/') return 2;
    if (ch == '^') return 3;
    return 0;
}

int main() {
    char infix[MAX], postfix[MAX];
    char tk, tkn;
    int i = 0, k = 0;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    tk = infix[i];

    while (tk != '\0') {
        if (isOperand(tk)) {
            postfix[k] = tk;
            k++;
        }
        else if (tk == '(') {
            push(tk);
        }
        else if (tk == ')') {
            while ((tkn = pop()) != '(' && tkn != '\0') {
                postfix[k] = tkn;
            }
        }
        else {
            while (top != -1 && stack[top] != '(' && isp(stack[top]) > icp(tk)) {
                postfix[k] = pop();
                k++;
            }
            push(tk);
        }
        i++;
        tk = infix[i];
    }

    while (top != -1) {
        postfix[k] = pop();
        k++;
    }

    postfix[k] = '\0';
    printf("Postfix Result: %s\n", postfix);

    return 0;
}