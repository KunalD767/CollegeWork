#include <stdio.h>
#include <string.h>

void removeLeftFactoring(char* nonTerminal, char* productions) {
    char commonPrefix[100], remaining1[100], remaining2[100];
    char* prod1 = strtok(productions, "|");
    char* prod2 = strtok(NULL, "|");

    int i = 0;
    // Find the common prefix
    while (prod1[i] == prod2[i] && prod1[i] != '\0' && prod2[i] != '\0') {
        commonPrefix[i] = prod1[i];
        i++;
    }
    commonPrefix[i] = '\0';  // Terminate commonPrefix string

    // Check if there's a common prefix
    if (strlen(commonPrefix) > 0) {
        printf("Grammar has left factoring.\n");

        // Remaining parts after the common prefix
        strcpy(remaining1, prod1 + i);
        strcpy(remaining2, prod2 + i);

        printf("%s -> %s%s'\n", nonTerminal, commonPrefix, nonTerminal);
        printf("%s' -> %s | %s\n", nonTerminal, strlen(remaining1) ? remaining1 : "ε", strlen(remaining2) ? remaining2 : "ε");
    } else {
        printf("Grammar does not have left factoring.\n");
    }
}

int main() {
    char nonTerminal[100], productions[100];

    // Input the grammar (non-terminal and production rules)
    printf("Enter Non-Terminal: ");
    scanf("%s", nonTerminal);
    printf("Enter Productions: ");
    scanf("%s", productions);

    removeLeftFactoring(nonTerminal, productions);
    return 0;
}
