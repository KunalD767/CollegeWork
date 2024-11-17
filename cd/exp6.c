#include <stdio.h>
#include <string.h>
#include <stdbool.h>


bool checkGrammar(char *str, int grammarNumber); 
bool isValidStringA(char *str); 
bool isValidStringB(char *str); 
bool isValidStringC(char *str); 
bool isValidStringD(char *str); 

int main() { 
    int grammarNumber; 
    char str[100]; 

    printf("Available Grammar Rules:\n"); 
    printf("1. S -> aS | Sb | ab\n"); 
    printf("2. S -> aSa | bSb | a | b\n"); 
    printf("3. S -> aSbb | abb\n"); 
    printf("4. S -> aSb | ab\n"); 

    printf("Enter the grammar number (1-4): "); 
    scanf("%d", &grammarNumber); 

    printf("Enter the string to check: "); 
    scanf("%s", str); 

    if (checkGrammar(str, grammarNumber)) { 
        printf("The string belongs to Grammar %d.\n", grammarNumber); 
    } else { 
        printf("The string does not belong to Grammar %d.\n", grammarNumber); 
    } 

    return 0; 
} 

bool checkGrammar(char *str, int grammarNumber) { 
    switch (grammarNumber) { 
        case 1: return isValidStringA(str); // Grammar A 
        case 2: return isValidStringB(str); // Grammar B 
        case 3: return isValidStringC(str); // Grammar C 
        case 4: return isValidStringD(str); // Grammar D 
        default: return false; 
    } 
}

bool isValidStringA(char *str) { 
    int len = strlen(str); 
    int i = 0; 
    while (i < len && str[i] == 'a') { i++; } 
    while (i < len && str[i] == 'b') { i++; } 
    return i == len; 
} 

bool isPalindrome(char *str, int start, int end) { 
    while (start < end) { 
        if (str[start] != str[end]) { return false; } 
        start++; end--; 
    } 
    return true; 
} 

bool isValidStringB(char *str) { 
    int len = strlen(str); 
    if (len % 2 == 0) { return false; } 
    return isPalindrome(str, 0, len - 1); 
}

bool isValidStringC(char *str) { 
    int len = strlen(str); 
    if (len < 4) { return false; } 
    int a_count = 0; 
    int b_count = 0; 
    for (int i = 0; i < len; i++) { 
        if (str[i] == 'a') { a_count++; } 
        else if (str[i] == 'b') { b_count++; } 
        else { return false; } 
    } 
    return (b_count == 2 * a_count && a_count > 1); 
} 

bool isValidStringD(char *str) { 
    int len = strlen(str); 
    if (len < 2 || len % 2 != 0) { return false; } 
    int n = len / 2; 
    for (int i = 0; i < n; i++) { 
        if (str[i] != 'a' || str[len - i - 1] != 'b') { return false; } 
    } 
    return true; 
}



