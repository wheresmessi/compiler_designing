%{
#include <stdio.h>
%}

%%

[a-z]([a-z])* { printf("%s is an word", yytext); }
[0-9]+ { printf("%s is a number", yytext); }
. { printf("Invalid character: %s", yytext); }

%%

int main() {
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}

