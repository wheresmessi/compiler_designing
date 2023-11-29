%{
#include <string.h>
int max_length = 0;
char longest_word[100];
%}

%%
[a-zA-Z]+ {
    if (yyleng > max_length) {
        max_length = yyleng;
        strncpy(longest_word, yytext, yyleng);
        longest_word[yyleng] = '\0';  
    }
}
. ;  // Ignore any other characters
%%

int yywrap(void) {
    return 1;
}

int main() {
    printf("Enter a sentence: ");
    yylex();
    printf("Length of the longest word: %d\n", max_length);
    printf("Longest word: %s\n", longest_word);
    return 0;
}