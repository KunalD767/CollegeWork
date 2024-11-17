%{
#include "exp2.tab.h"
%}

%%

[0-9]+      { yylval = atoi(yytext); return NUMBER; }
"+"          { return PLUS; }
"-"          { return MINUS; }
"*"          { return TIMES; }
"/"          { return DIVIDE; }
"("          { return LPAREN; }
")"          { return RPAREN; }
[ \t]        ;  // Ignore whitespace
\n           { return '\n'; }

%%

int yywrap() {
    return 1;
}
