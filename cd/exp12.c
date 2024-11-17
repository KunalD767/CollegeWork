#include <stdio.h>
#include <string.h>

void findLeading(char nonTerminal, char productions[10][10], int count) {
    printf("Leading(%c) = {", nonTerminal);
    for (int i = 0; i < count; i++) {
        if (productions[i][0] == nonTerminal) {
            if (productions[i][2] >= 'a' && productions[i][2] <= 'z') {
                printf(" %c", productions[i][2]);
            }
        }
    }
    printf(" }\n");
}

int main() {
    char productions[10][10];
    int count;
    char nonTerminal;

    printf("Enter the number of productions: ");
    scanf("%d", &count);
    printf("Enter the productions:\n");
    for (int i = 0; i < count; i++) {
        scanf("%s", productions[i]);
    }
    printf("Enter the non-terminal to find leading: ");
    scanf(" %c", &nonTerminal);

    findLeading(nonTerminal, productions, count);
    return 0;
}
