#include <stdio.h>
#include <string.h>

void removeLeftRecursion(char* nonTerminal, char* production) {
    char alpha[100], beta[100], newProduction[100];

    // Check for left recursion
    if (nonTerminal[0] == production[0]) {
        printf("Grammar has left recursion");
        // Extract alpha and beta
        strcpy(alpha, production + 1);
        printf("%s -> %s%s", nonTerminal, beta, nonTerminal);
        printf("%s' -> %s%s' | ε", nonTerminal, alpha, nonTerminal);
    } else {
        printf("Grammar does not have left recursion.");
    }
}

int main() {
    char nonTerminal[100], production[100];

    // Input the grammar (non-terminal and production rule)
    printf("Enter Non-Terminal: ");
    scanf("%s", nonTerminal);
    printf("Enter Production: ");
    scanf("%s", production);

    removeLeftRecursion(nonTerminal, production);
    return 0;
}