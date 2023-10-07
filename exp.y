%{ /* validate simple arithmetic expression */
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
%}
%token num let
%left '+' '-'
%left '*' '/'
%%
stmt: stmt '\n' {printf("\n Valid \n");exit(0);}
| expr
|
|error '\n' {printf("\n Invlaid \n");exit(0);}
;
expr: num
| let
| expr '+' expr
| expr '-' expr
| expr '*' expr
| expr '/' expr
| '('expr')'
%%
main()
{
printf(" Enter an expression to validate: ");
yyparse();
}
yylex()

{
int ch;
while((ch=getchar())==' ');
if(isdigit(ch))
return num;
if(isalpha(ch))
return let;
return ch;
}
yyerror(char *s)
{
printf("%s",s);
}
