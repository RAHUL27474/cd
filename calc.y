%{
#include <stdio.h>
#include <stdlib.h>

int yylex(void);
int yyerror(char *s);
%}

%token NUM

%%

input:
      input expr '\n' { printf("Result: %d\n", $2); }
    | /* empty */
    ;

expr:
      expr '+' term   { $$ = $1 + $3; }
    | expr '-' term   { $$ = $1 - $3; }
    | term
    ;

term:
      term '*' factor { $$ = $1 * $3; }
    | term '/' factor {
                        if ($3 == 0) {
                            yyerror("Division by zero");
                            exit(1);
                        }
                        $$ = $1 / $3;
                      }
    | factor
    ;

factor:
      '(' expr ')'    { $$ = $2; }
    | NUM             { $$ = $1; }
    ;

%%

int yyerror(char *s) {
    fprintf(stderr, "Error: %s\n", s);
    return 0;
}

int main(void) {
    printf("Enter an arithmetic expression:\n");
    yyparse();
    return 0;
}
