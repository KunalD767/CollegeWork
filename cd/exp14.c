#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isOperatorPrecedence(char* grammar) {
    for (int i = 0; grammar[i] != '\0'; i++) {
        if ((grammar[i] == '+' || grammar[i] == '*') && grammar[i + 1] == grammar[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    char grammar[100];
    printf("Enter the grammar rules: ");
    scanf("%s", grammar);
    if (isOperatorPrecedence(grammar)) {
        printf("The grammar is operator precedence.\n");
    } else {
        printf("The grammar is not operator precedence.\n");
    }
    return 0;
}
