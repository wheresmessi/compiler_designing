%{
#include <stdio.h>
%}

%%
[a-zA-Z0-9._%+-]+@gmail.com   { printf("%s is a valid email\n", yytext); }
.+                             { printf("%s is an invalid email\n", yytext); }
%%

int main() {
    printf("\nEnter the email: ");
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}
