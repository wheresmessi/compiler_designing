%{
#include<stdio.h>
int flag = 0; 
%} 

%% 

[aeiouAEIOU].[a-zA-Z0-9.]+ flag=1; 
[a-zA-Z0-9]+ 

%% 
int yywrap(){
return 1;
}

int main() 
{ 
yylex(); 
if (flag == 1) 
	printf("Accepted"); 
else
	printf("Not Accepted"); 
return 0;
} 
