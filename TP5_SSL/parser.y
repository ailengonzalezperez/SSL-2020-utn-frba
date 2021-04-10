%{
#include <stdio.h>
#include "scanner.h"
#include "symbol.h"
#include "semantic.h"

void mostrarError(char *id, int e);
void errorYaDeclarado(char* identificador);
void errorNoDeclarado(char* identificador);
extern int errlex; 	/* Contador de Errores Léxicos */
extern int semerrs;
%}

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

program: PROGRAMA {empezar();} contenidoPrograma FINPROG {finalizar(); if (errlex > 0 || yynerrs > 0 || semerrs > 0) YYABORT; else YYACCEPT;};

contenidoPrograma: 		contenidoPrograma sentencia
						| %empty;
	



sentencia:				DECLARAR IDENTIFICADOR ';' {if(!existeVariable($2)){
                                                                declarar($2);
                                                                agregarVariable($2);
                                                                } else {errorYaDeclarado($2); YYERROR;};}
						| LEER '('listaDeIdentificadores')' ';' 	
                        | ESCRIBIR '('listaDeExpresiones')' ';' 
                        | identificador ASIGNACION unaExpresion ';'{asignar($3,$1);}
						| error';';


listaDeIdentificadores: identificador 	{leer($1);}							
                        | listaDeIdentificadores','identificador  {leer($3);};	
                        
listaDeExpresiones: unaExpresion 							{escribir($1);}
					| listaDeExpresiones','unaExpresion  	{escribir($3);};  
  
unaExpresion : 		  	valor
                        | '-'valor %prec NEG			{$$ = menosUnario($2);}
                        | '('unaExpresion')' 			{$$ = $2;}
                        | unaExpresion '+' unaExpresion {$$ = sumar($1, $3);}
                        | unaExpresion '-' unaExpresion {$$ = restar($1, $3);}
                        | unaExpresion '*' unaExpresion {$$ = multiplicar($1, $3);}
                        | unaExpresion '/' unaExpresion {$$ = dividir($1, $3);}
						| '(' error ')';
						
valor : 		  		identificador
                        | CONSTANTE;

identificador: IDENTIFICADOR {if(!existeVariable($1)){errorNoDeclarado($1); YYERROR;}else $$ = $1;};

%%

/* Informa la ocurrencia de un error */
void yyerror(const char *s){
	printf("Línea #%d -> %s\n", yylineno, s);
	return;
}

void errorYaDeclarado(char* identificador){
	printf("Línea #%d -> Error semántico: El identificador %s ya ha sido declarado.\n",yylineno,identificador);
	semerrs++;
}

void errorNoDeclarado(char* identificador){
	printf("Línea #%d -> Error semántico: El identificador %s no ha sido declarado previamente.\n",yylineno,identificador);
	semerrs++;
}
