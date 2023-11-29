%{
#include <stdio.h>
%}

%%
[0-9]+           { printf("Number\n"); }
[a-zA-Z][a-zA-Z0-9]* { printf("Word\n"); }
">"|"<"|"<="|">="|"=="|"!=" { printf("Relational Operator\n"); }
%%

int yywrap() {
    return 1;
}

int main() {
    yylex();
    return 0;
}
