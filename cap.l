%{
	#include<stdio.h>
%}

%%
[A-Z]+ { printf("%s\n",yytext); }
.  ;
%%

int main( ) 
{
	printf("Enter some string with capital words in between\n");
	yylex();
}

int yywrap( )
{
	return 1;
}