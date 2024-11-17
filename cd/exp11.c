#include <stdio.h>
#define MAX 5

int stack[MAX], top = -1;

void push(int x) {
    if (top < MAX - 1) {
        stack[++top] = x;
        printf("Pushed %d onto stack\n", x);
    } else {
        printf("Stack Overflow\n");
    }
}

void pop() {
    if (top >= 0) {
        printf("Popped %d from stack\n", stack[top--]);
    } else {
        printf("Stack Underflow\n");
    }
}

void display() {
    if (top >= 0) {
        printf("Stack: ");
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    } else {
        printf("Stack is empty\n");
    }
}

int main() {
    push(10);
    push(20);
    display();
    pop();
    display();
    return 0;
}
