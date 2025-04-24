%{
#include "y.tab.h"
%}

%%

[0-9]+      { yylval = atoi(yytext); return NUM; }
[+\-*/()]   { return yytext[0]; }
[\t ]+      { /* skip whitespace */ }
\n          { return '\n'; }

.           { printf("Invalid character: %s\n", yytext); }

%%
int yywrap(void) {
    return 1;
}
