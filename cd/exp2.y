%{
#include <stdio.h>
#include <stdlib.h>

void yyerror(const char *s);
int yylex();
%}

%token NUMBER PLUS MINUS TIMES DIVIDE LPAREN RPAREN

%left PLUS MINUS
%left TIMES DIVIDE

%%

input: 
      /* empty */
    | input line
    ;

line: '\n'
    | expr '\n' { /* Do nothing */ }
    ;

expr: NUMBER
    { printf("NUMBER "); }
    | expr PLUS expr
    { printf("PLUS "); }
    | expr MINUS expr
    { printf("MINUS "); }
    | expr TIMES expr
    { printf("TIMES "); }
    | expr DIVIDE expr
    { printf("DIVIDE "); }
    | LPAREN expr RPAREN
    { printf("LPAREN RPAREN "); }
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main() {
    printf("Enter arithmetic expressions (or press Ctrl+D to end):\n");
    yyparse();
    return 0;
}
