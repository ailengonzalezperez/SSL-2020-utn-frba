%{
#include <stdio.h>
#include "scanner.h"
%}

%code provides {
extern int errlex; 	/*el de scanner.l*/

}

%define api.value.type{char *}

%defines "parser.h"
%output "parser.c"

%start program
%define parse.error verbose

%token PROGRAMA FINPROG DECLARAR LEER ESCRIBIR CONSTANTE IDENTIFICADOR 
%token ASIGNACION "<-"

%left  '-'  '+'
%left  '*'  '/'
%precedence NEG  /*apunte bison*/

%%

program: PROGRAMA contenidoPrograma FINPROG {if (errlex > 0 || yynerrs > 0) YYABORT; else YYACCEPT;};

contenidoPrograma: 		contenidoPrograma sentencia
						| sentencia;

				

sentencia:				DECLARAR IDENTIFICADOR ';' {printf("declarar %s\n",$2);}
						| LEER '('listaDeIdentificadores')' ';' 	{printf("leer\n");}
                        | ESCRIBIR '('listaDeExpresiones')' ';' {printf("escribir\n");}
                        | IDENTIFICADOR ASIGNACION unaExpresion ';'{printf("asignacion\n");}
						| error';';

listaDeIdentificadores: IDENTIFICADOR
                        | IDENTIFICADOR','listaDeIdentificadores;
                        
listaDeExpresiones: unaExpresion
					| unaExpresion',' listaDeExpresiones;  
  
unaExpresion : 		  	valor
                        | '-'valor %prec NEG			{printf("inversión\n");}
                        | '('unaExpresion')' 			{printf("paréntesis\n");}
                        | unaExpresion '+' unaExpresion {printf("suma\n");}
                        | unaExpresion '-' unaExpresion {printf("resta\n");}
                        | unaExpresion '*' unaExpresion {printf("multiplicación\n");}
                        | unaExpresion '/' unaExpresion {printf("división\n");}
						| '(' error ')';
						
valor : 		  		IDENTIFICADOR
                        | CONSTANTE;

%%

/* Informa la ocurrencia de un error */
void yyerror(const char *s){
	printf("línea #%d: %s\n", yylineno, s);
	return;
}


