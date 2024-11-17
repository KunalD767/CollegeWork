%{
#include <stdio.h>
#include <string.h>
#include "exp5.tab.h"
void yyerror(const char* s);
%}

%%

"int"       { return INT; }
"print"     { return PRINT; }

[a-zA-Z][a-zA-Z0-9]* {  
    yylval.sval = strdup(yytext); 
    return IDENTIFIER;  
}

[0-9]+      {  
    yylval.ival = atoi(yytext);  
    return NUMBER;  
}

"="         { return ASSIGN; }
"+"         { return PLUS; }
"-"         { return MINUS; }
"*"         { return TIMES; }
"/"         { return DIVIDE; }
"("         { return LPAREN; }
")"         { return RPAREN; }
";"         { return SEMICOLON; }

[ \t\n]     { /* Ignore whitespace */ }

.           {  
    char msg[100]; 
    snprintf(msg, sizeof(msg), "Unrecognized character: %s", yytext); 
    yyerror(msg); 
}

%%

int yywrap(void) { 
    return 1; 
}
