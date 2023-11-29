%{
#include <string.h>
int word_count = 0;
char target_word[] = "n";
%}

%%
[a-zA-Z]+ {
    if (strcmp(yytext, target_word) == 0) {
        word_count++;
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
    printf("Frequency of '%s': %d\n", target_word, word_count);
    return 0;
}