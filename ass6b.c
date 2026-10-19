#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char s1[MAX], s2[MAX], s3[MAX], s4[MAX], s5[MAX];
int top = -1;

void push(char str[]) {
    top++;
    if (top == 0) strcpy(s1, str);
    else if (top == 1) strcpy(s2, str);
    else if (top == 2) strcpy(s3, str);
    else if (top == 3) strcpy(s4, str);
    else if (top == 4) strcpy(s5, str);
}

void pop(char dest[]) {
    if (top == 0) strcpy(dest, s1);
    else if (top == 1) strcpy(dest, s2);
    else if (top == 2) strcpy(dest, s3);
    else if (top == 3) strcpy(dest, s4);
    else if (top == 4) strcpy(dest, s5);
    top--;
}

int isOperand(char ch) {
    return isalnum(ch);
}

int main() {
    char prefix[MAX], postfix[MAX];
    char op1[MAX], op2[MAX], temp[MAX];
    char tk;
    int i, len;

    printf("Enter prefix expression: ");
    scanf("%s", prefix);

    len = strlen(prefix);

    for (i = len - 1; i >= 0; i--) {
        tk = prefix[i];

        if (isOperand(tk)) {
            char str[2];
            str[0] = tk;
            str[1] = '\0';
            push(str);
        }
        else {
            pop(op1);
            pop(op2);
            strcpy(temp, op1);
            strcat(temp, op2);
            char opStr[2];
            opStr[0] = tk;
            opStr[1] = '\0';
            strcat(temp, opStr);
            push(temp);
        }
    }

    pop(postfix);
    printf("Postfix Result: %s\n", postfix);

    return 0;
}