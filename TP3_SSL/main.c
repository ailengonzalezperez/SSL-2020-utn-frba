/*Trabajo Práctico Nº 3 - Sintaxis y semántica de los lenguajes

Curso: K2053
Grupo: 07
Integrantes:
Ailén Y. González Pérez - 169.982-9
Daniel Bareiro - 153.667-9
Sofía Chamorro – 147.303-7
*/

#include "scanner.h"

char* nombreDeTokens[] = {"Fin de archivo", "Asignación","Programa","Declarar","Fin de programa","Leer","Escribir","Identificador","Operador","Constante", "Puntuación","Caracter"};

int esPalabraReservada(int token){
  return (token == FDT || token == ESCRIBIR || token == LEER || token == DECLARAR || token == ASIGNACION || token == PROGRAMA || token == FINPROG);
}

char* obtenerNombreToken(int token){
	return nombreDeTokens[token];
}

int main(){
  int tokenEncontrado = yylex();
  while (tokenEncontrado != FDT){
    char* yytext_encontrado = yytext;
    if(esPalabraReservada(tokenEncontrado)){
       printf("Token: %s\n",obtenerNombreToken(tokenEncontrado));
    } else if(tokenEncontrado==IDENTIFICADOR){
       printf("Token: %s / Lexema: %s\n",obtenerNombreToken(tokenEncontrado),yytext_encontrado);
    } else if(tokenEncontrado==CONSTANTE){
       printf("Token: %s / Lexema: %s\n",obtenerNombreToken(tokenEncontrado),yytext_encontrado);
     } else { //Puntuación, caracter, operador
        printf("Token: \'%c\'\n",tokenEncontrado);
      }
    tokenEncontrado = yylex();
  }
  printf("Token: %s\n",nombreDeTokens[tokenEncontrado]);

  return 0;
}


