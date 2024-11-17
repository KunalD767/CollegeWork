%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylex();
extern int yylineno;
void yyerror(const char* s);

int temp_var = 0;
int label_count = 0;
%}

%union {
    int ival;
    char* sval;
    struct {
        char* code;
        char* place;
    } expr;
}

%token <sval> IDENTIFIER
%token <ival> NUMBER
%token INT PRINT
%token ASSIGN PLUS MINUS TIMES DIVIDE
%token LPAREN RPAREN SEMICOLON

%type <expr> expression statement statement_list

%left PLUS MINUS
%left TIMES DIVIDE

%%

program:
    statement_list {
        printf("%s", $1.code);
        free($1.code);
    }
    ;

statement_list:
    statement {
        $$.code = $1.code;
    }
    | statement_list statement {
        $$.code = (char*)malloc(strlen($1.code) + strlen($2.code) + 1);
        sprintf($$.code, "%s%s", $1.code, $2.code);
        free($1.code);
        free($2.code);
    }
    ;

statement:
    INT IDENTIFIER SEMICOLON {
        $$.code = (char*)malloc(100);
        sprintf($$.code, "DECLARE %s\n", $2);
        free($2);
    }
    | IDENTIFIER ASSIGN expression SEMICOLON {
        $$.code = (char*)malloc(strlen($3.code) + 100);
        sprintf($$.code, "%sMOV %s, %s\n", $3.code, $1, $3.place);
        free($1);
        free($3.code);
        free($3.place);
    }
    | PRINT expression SEMICOLON {
        $$.code = (char*)malloc(strlen($2.code) + 100);
        sprintf($$.code, "%sPRINT %s\n", $2.code, $2.place);
        free($2.code);
        free($2.place);
    }
    ;

expression:
    NUMBER {
        $$.place = (char*)malloc(20);
        sprintf($$.place, "%d", $1);
        $$.code = strdup("");
    }
    | IDENTIFIER {
        $$.place = strdup($1);
        $$.code = strdup("");
        free($1);
    }
    | expression PLUS expression {
        char* temp = (char*)malloc(20);
        sprintf(temp, "t%d", temp_var++);
        $$.place = temp;
        $$.code = (char*)malloc(strlen($1.code) + strlen($3.code) + 100);
        sprintf($$.code, "%s%sADD %s, %s, %s\n", $1.code, $3.code, temp, $1.place, $3.place);
        free($1.code);
        free($3.code);
        free($1.place);
        free($3.place);
    }
    | expression MINUS expression {
        char* temp = (char*)malloc(20);
        sprintf(temp, "t%d", temp_var++);
        $$.place = temp;
        $$.code = (char*)malloc(strlen($1.code) + strlen($3.code) + 100);
        sprintf($$.code, "%s%sSUB %s, %s, %s\n", $1.code, $3.code, temp, $1.place, $3.place);
        free($1.code);
        free($3.code);
        free($1.place);
        free($3.place);
    }
    ;

%%

void yyerror(const char* s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main(void) {
    printf("Enter your program (Ctrl+D to finish):\n");
    yyparse();
    return 0;
}
