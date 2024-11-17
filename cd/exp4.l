%{
#include "exp4.tab.h"
#include <stdio.h>
#include <stdlib.h>
%}

%%

[0-9]+                  { yylval.ival = atoi(yytext); return NUMBER; }
"+"                     { return PLUS; }
"-"                     { return MINUS; }
"*"                     { return MULTIPLY; }
"/"                     { return DIVIDE; }
"("                     { return '('; }   // Added support for left parenthesis
")"                     { return ')'; }   // Added support for right parenthesis
\n                      { return EOL; }
[ \t]+                  ;  // Skip whitespace
.                       { fprintf(stderr, "Invalid character: %c\n", *yytext); exit(1); }

%%

int yywrap() {
    return 1;
}
