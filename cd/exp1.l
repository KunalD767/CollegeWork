%{
#include <stdio.h>
#include <stdlib.h>
#define KEYWORD1 "int"
#define KEYWORD2 "float"
#define KEYWORD3 "return"
#define KEYWORD4 "if"
#define KEYWORD5 "else"
%}

%option noyywrap

%%

"int"      { printf("Keyword: %s\n", yytext); }
"float"    { printf("Keyword: %s\n", yytext); }
"return"   { printf("Keyword: %s\n", yytext); }
"if"       { printf("Keyword: %s\n", yytext); }
"else"     { printf("Keyword: %s\n", yytext); }

[a-zA-Z_][a-zA-Z0-9_]* { printf("Identifier: %s\n", yytext); }

[ \t\n]+   ;  // Skip whitespace

.          { printf("Other character: %s\n", yytext); }

%%

int main(int argc, char **argv) {
    yylex();
    return 0;
}
