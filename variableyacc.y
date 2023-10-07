%{/* YACC pgm to recognize valid variable, which starts with a letter, followed by any number of
letters or digits. */
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
%}
%token let dig
%%
TERM:XTERM'\n'{printf("\nAccepted\n");exit(0);}
|error {yyerror("\nRejected");
exit(0);
}
;
XTERM:XTERM let
|XTERM dig
|let
;
%%
main()
{
 printf("Enter a variable: ");
 yyparse();
 }
yylex()
{
 char ch;
 while((ch=getchar())==" ");
 if(isalpha(ch))
 return let;
 if(isdigit(ch))
 return dig;
 return ch;
 }
yyerror(char *s)
{
 printf("%s",s);
}
