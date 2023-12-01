#include <stdio.h>
#include <ctype.h>

int main() {
    char text[1000];
    char c;
    int charCount = 0, wordCount = 0, lineCount = 0;
    int inWord = 0;

    printf("Enter text (Ctrl+D or Ctrl+Z to end input):\n");

    while ((c = getchar()) != EOF) {
        charCount++;

        if (isspace(c)) {
            inWord = 0;
        } else {
            if (!inWord) {
                inWord = 1;
                wordCount++;
            }
        }

        if (c == '\n') {
            lineCount++;
        }
    }

    printf("\nNumber of characters: %d\n", charCount);
    printf("Number of words: %d\n", wordCount);
    printf("Number of lines: %d\n", lineCount);

    return 0;
}
