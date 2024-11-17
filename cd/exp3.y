%{
#include <stdio.h>
#include <stdlib.h>

void yyerror(const char *s);
int yylex();
%}

%token NUMBER

%left '+' '-'
%left '*' '/'

%%

input: 
      /* empty */
    | input line
    ;

line: '\n'
    | expr '\n' { printf("Result = %d\n", $1); }
    ;

expr: NUMBER
    { $$ = $1; }
    | expr '+' expr
    { $$ = $1 + $3; }
    | expr '-' expr
    { $$ = $1 - $3; }
    | expr '*' expr
    { $$ = $1 * $3; }
    | expr '/' expr
    {
        if ($3 == 0) {
            yyerror("Division by zero");
            $$ = 0;
        } else {
            $$ = $1 / $3;
        }
    }
    | '(' expr ')'
    { $$ = $2; }
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


