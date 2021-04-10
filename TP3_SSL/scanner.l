%top{
	#include <stdio.h>
	#include "tokens.h"
}

%option header-file="scanner.h"
%option outfile="scanner.c"
%option noinput
%option nounput

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

{digito}+       			return CONSTANTE;
{letra}{letraDigito}*   	return IDENTIFICADOR;

"+"              return '+';
"-"              return '-';
"*"              return '*';
"/"              return '/';
"("              return '(';
")"              return ')';
";"              return ';';
","              return ',';


{otros}+			printf("Error léxico común por cadena inválida: %s\n",yytext);

{letra}{letraDigito}*{otros}+({letraDigito}|{otros})*	printf("Error léxico por identificador inválido: %s\n",yytext);

{digito}+{letra}+{letraDigito}*			printf("Error léxico por constante inválida: %s\n",yytext);

{espacios}+						|
{comentarios}					|
.																													;
%%