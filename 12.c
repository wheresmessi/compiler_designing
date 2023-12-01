#include<stdio.h>
#include<string.h>

void pm(char exp1[], char exp[], int i, int l);
void div(char exp1[], char exp[], int i);
void plus(char exp1[], char exp[], int i);

int main() {
    char exp[10], exp1[10], id1[5], op[5], id2[5];
    int ch, l, i, addr = 100;

    while (1) {
        printf("\n1. Assignment\n2. Arithmetic\n3. Relational\n4. Exit\nEnter the choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("\nEnter the expression with assignment operator: ");
                scanf("%s", exp);
                l = strlen(exp);
                exp1[0] = '\0';
                i = 0;

                while (exp[i] != '=') {
                    i++;
                }

                strncat(exp1, exp, i);
                strrev(exp);
                exp1[0] = '\0';
                strncat(exp1, exp, l - (i + 1));
                strrev(exp1);
                printf("Three address code:\ntemp=%s\n%s=temp\n", exp1, exp);
                break;

            case 2:
                printf("\nEnter the expression with arithmetic operator: ");
                scanf("%s", exp);
                l = strlen(exp);
                exp1[0] = '\0';

                for (i = 0; i < l; i++) {
                    if (exp[i] == '+' || exp[i] == '-') {
                        if (exp[i + 2] == '/' || exp[i + 2] == '*') {
                            pm(exp1, exp, i, l);
                            break;
                        } else {
                            plus(exp1, exp, i);
                            break;
                        }
                    } else if (exp[i] == '/' || exp[i] == '*') {
                        div(exp1, exp, i);
                        break;
                    }
                }
                break;

            case 3:
                printf("Enter the expression with relational operator: ");
                scanf("%s %s %s", id1, op, id2);

                if (strcmp(op, "<") == 0 || strcmp(op, ">") == 0 || strcmp(op, "<=") == 0 ||
                    strcmp(op, ">=") == 0 || strcmp(op, "==") == 0 || strcmp(op, "!=") == 0) {
                    printf("\n%d\tif %s%s%s goto %d", addr, id1, op, id2, addr + 3);
                    addr++;
                    printf("\n%d\t T:=0", addr);
                    addr++;
                    printf("\n%d\t goto %d", addr, addr + 2);
                    addr++;
                    printf("\n%d\t T:=1", addr);
                } else {
                    printf("Expression is error");
                }
                break;

            case 4:
                return 0;
        }
    }
}

void pm(char exp1[], char exp[], int i, int l) {
    strrev(exp);
    int j = l - i - 1;
    strncat(exp1, exp, j);
    strrev(exp1);
    printf("Three address code:\ntemp=%s\ntemp1=%c%c%s\n", exp1, exp[j + 1], exp[j], exp);
}

void div(char exp1[], char exp[], int i) {
    strncat(exp1, exp, i + 2);
    printf("Three address code:\ntemp=%s\ntemp1=temp%c%c\n", exp1, exp[i + 2], exp[i + 3]);
}

void plus(char exp1[], char exp[], int i) {
    strncat(exp1, exp, i + 2);
    printf("Three address code:\ntemp=%s\ntemp1=temp%c%c\n", exp1, exp[i + 2], exp[i + 3]);
}
