#include <stdio.h>
#include <string.h>

char stack[50];
int top = -1;

void push(char symbol) {
    stack[++top] = symbol;
}

void pop() {
    top--;
}

void display() {
    for (int i = 0; i <= top; i++) {
        printf("%c", stack[i]);
    }
}

void check() {
    if (stack[top] == 'b' && stack[top-1] == 'S' && stack[top-2] == 'a') {
        pop(); pop(); pop();
        push('S');
        printf(" Reduced by: S -> aSb\n");
        display();
    }
}

int main() {
    char input[20];
    printf("Enter the input string: ");
    scanf("%s", input);
    for (int i = 0; i < strlen(input); i++) {
        push(input[i]);
        printf(" Shift\n");
        check();
    }
    return 0;
}
