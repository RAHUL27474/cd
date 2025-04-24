%{
#include <stdio.h>
#include <stdlib.h>

int yylex(void);     // Declare yylex
int yyerror(char *s); // Declare yyerror
%}

%%

input: '0' body '0' { printf("Accepted\n"); }
     | '1' body '1' { printf("Accepted\n"); }
     |              { printf("Invalid string\n"); }
     ;

body:
     /* empty */
   | body '0'
   | body '1'
   ;

%%

int main(void) {
    printf("Enter a string: ");
    yyparse();
    return 0;
}

int yyerror(char *s) {
    printf("Error: %s\n", s);
    return 0;
}

// Simple lexer
int yylex(void) {
    char c = getchar();
    if (c == EOF || c == '\n') return 0;
    if (c == '0' || c == '1') return c;
    return 0;  // Invalid char ends input
}
