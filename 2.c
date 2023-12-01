#include<stdio.h>
#include<string.h>
int main()
{
    char ip[100];

    printf("Enter any command: \n");
    gets(ip);
    
    if(ip[0]=='/' && ip[1]=='/'){
            printf("it's a comment \n");
        }
        else if(ip[0]=='/'&&ip[1]=='*')
        {
            printf("it's a comment \n");
        }
        else{
            printf("It's not a comment \n");
        }

    return 0;
}