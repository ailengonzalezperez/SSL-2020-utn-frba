%top{
	#include <stdio.h>
	#include "parser.h"
	int errlex;
	char msg[300];
	void yyerror(const char *);
}

%option header-file="scanner.h"
%option outfile="scanner.c"
%option noinput
%option nounput
%option noyywrap
%option yylineno

letra         	[a-zA-Z]
digito        	[0-9]
letraDigito   	[0-9a-zA-Z]
asignacion    	<-
otros			[[:punct:]]{-}[();,+\-*/]
comentarios		##.*
espacios  		[[:space:]]

%%

fin-prog			return FINPROG;
declarar			return DECLARAR;
leer				return LEER;
escribir 			return ESCRIBIR;
programa       		return PROGRAMA; 
{asignacion}    	return ASIGNACION;
{digito}+       			{yylval = strdup(yytext); return CONSTANTE;}
{letra}{letraDigito}*   	{yylval = strdup(yytext);return IDENTIFICADOR;}
"+"              return '+';
"-"              return '-';
"*"              return '*';
"/"              return '/';
"("              return '(';
")"              return ')';
";"              return ';';
","              return ',';

{otros}+			{sprintf(msg,"Error léxico común por cadena inválida: %s",yytext);yyerror(msg);errlex++;}

{letra}{letraDigito}*{otros}+({letraDigito}|{otros})*	{sprintf(msg,"Error léxico por identificador inválido: %s",yytext);yyerror(msg);errlex++;}

{digito}+{letra}+{letraDigito}*			{sprintf(msg,"Error léxico por constante inválida:: %s",yytext);yyerror(msg);errlex++;}

{espacios}+						|
{comentarios}					|
.																													;
%%