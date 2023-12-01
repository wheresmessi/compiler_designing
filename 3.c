#include <stdio.h>
#include <ctype.h>

int main() {
    char input[100];
    printf("Enter an arithmetic expression: ");
    fgets(input, sizeof(input), stdin);

    printf("Operators found: ");
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/') {
            printf("%c ", input[i]);
        }
    }

    return 0;
}