#include<stdio.h>
#include<string.h>
int main()
{
    char ip[100]="a+b=c;";
    int len = strlen(ip);

    for(int i=0;i<len;i++){
        if(ip[i]==' '||ip[i]=='+'||ip[i]=='-'||ip[i]=='*'||
        ip[i]==','||ip[i]=='/'||ip[i]==';'||ip[i]=='='||ip[i]=='>'||ip[i]=='<'||ip[i]=='('||ip[i]==')'||ip[i]=='['||ip[i]==']'||ip[i]=='{'
        ||ip[i]=='}')
        {
            printf("%c is an operator \n",ip[i]);
        }
        else if(ip[i]>='a'&& ip[i]<='z'||ip[i]>='A'&&ip[i]<='Z'){
            printf("%c is an identifier\n",ip[i]);
        }
        else if (ip[i] >= '0' && ip[i] <= '9' || ip[i] == '-' && ip[i+1] >= '0' && ip[i+1] <= '9')
                    printf("%c IS AN INTEGER\n", ip[i]);
        
        else{
            printf("%c is not valid \n",ip[i]);
        }            
    }

    return 0;
}