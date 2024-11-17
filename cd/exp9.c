#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 10

void findLeading(char nonTerminal, char productions[MAX][MAX], int productionCount) {
    int i, j;
    printf("Leading(%c) = { ", nonTerminal);

    for (i = 0; i < productionCount; i++) {
        if (productions[i][0] == nonTerminal) {
            if (isupper(productions[i][2])) {
                for (j = 0; j < productionCount; j++) {
                    if (productions[j][0] == productions[i][2]) {
                        printf("%c ", productions[j][2]);
                    }
                }
            } else {
                printf("%c ", productions[i][2]);
            }
        }
    }
    printf("}\n");
}

int main() {
    int i, productionCount;
    char nonTerminal;
    char productions[MAX][MAX];

    printf("Enter the number of productions: ");
    scanf("%d", &productionCount);

    for (i = 0; i < productionCount; i++) {
        printf("Enter production %d: ", i + 1);
        scanf("%s", productions[i]);
    }

    printf("Enter the non-terminal to find leading: ");
    scanf(" %c", &nonTerminal);

    findLeading(nonTerminal, productions, productionCount);

    return 0;
}
