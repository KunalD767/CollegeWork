%{
#include <stdio.h>
#include <stdlib.h>

void yyerror(const char *s);
int yylex(void);
%}

%union {
    int ival;
}

%token <ival> NUMBER
%token PLUS MINUS MULTIPLY DIVIDE
%token EOL
%type <ival> expr term factor

%% 

program:
    expr EOL         { printf("Result = %d\n", $1); }
    | error EOL      { yyerror("Syntax error"); yyclearin; }
    ;

expr:
    expr PLUS term   { $$ = $1 + $3; }
    | expr MINUS term { $$ = $1 - $3; }
    | term            { $$ = $1; }
    ;

term:
    term MULTIPLY factor { $$ = $1 * $3; }
    | term DIVIDE factor { $$ = $1 / $3; }
    | factor            { $$ = $1; }
    ;

factor:
    NUMBER            { $$ = $1; }
    | '(' expr ')'    { $$ = $2; }
    ;

%% 

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main(void) {
    printf("Enter expressions to evaluate:\n");
    yyparse();
    return 0;
}


