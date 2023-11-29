%{
#include<stdio.h>
%}

%% 
((http)|(ftp))s?:\/\/[a-zA-Z0-9]{2,}(\.[a-z]{2,})+(\/[a-zA-Z0-9+=?]*)* {printf("\nURL Valid\n");}
.+ {printf("\nURL Invalid\n");} 

%%

int yywrap() {
    return 1;
} 

int main() {
    printf("\nEnter URL : "); 
    yylex();
    return 0; 
}
