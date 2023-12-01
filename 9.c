#include<stdio.h>  
#include<string.h>  

int main() {
    char gram[20], part1[20], part2[20], modifiedGram[20], newGram[20], tempGram[20];
    int i, j = 0, k = 0, l = 0, pos;

    printf("Enter Production : A->");
    gets(gram);

    // Separating part1 and part2 based on the '|' symbol
    for(i = 0; gram[i] != '|'; i++, j++)
        part1[j] = gram[i];
    part1[j] = '\0';

    for(j = ++i, i = 0; gram[j] != '\0'; j++, i++)
        part2[i] = gram[j];
    part2[i] = '\0';

    // Identifying the common prefix and storing it in modifiedGram
    for(i = 0; i < strlen(part1) || i < strlen(part2); i++) {
        if(part1[i] == part2[i]) {
            modifiedGram[k] = part1[i];
            k++;
            pos = i + 1;
        }
    }

    // Creating newGram by combining the remaining parts of part1 and part2
    for(i = pos, j = 0; part1[i] != '\0'; i++, j++) {
        newGram[j] = part1[i];
    }
    newGram[j++] = '|';

    for(i = pos; part2[i] != '\0'; i++, j++) {
        newGram[j] = part2[i];
    }

    modifiedGram[k] = 'X'; // 'X' is a new non-terminal to replace the common prefix
    modifiedGram[++k] = '\0';
    newGram[j] = '\0';

    printf("\n A->%s", modifiedGram);
    printf("\n X->%s\n", newGram);
}
