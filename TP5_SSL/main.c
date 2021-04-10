/*Trabajo Práctico Nº 5 - Sintaxis y semántica de los lenguajes

Curso: K2053
Grupo: 07
Integrantes:
Ailén Y. González Pérez - 169.982-9
Daniel Bareiro - 153.667-9
Sofía Chamorro – 147.303-7
*/

#include <stdio.h>
#include "parser.h"
#include "scanner.h"
#include "semantic.h"
#include "symbol.h"

int yynerrs = 0;
int semerrs = 0;

int main(){
	switch (yyparse()){
    case 0:
        puts("Compilación exitosa");
        printf("Errores sintácticos: %d, Errores léxicos %d y Errores semánticos: %d\n",yynerrs,errlex,semerrs);
        return 0;

    case 1:
        puts("Error de compilación");
        printf("Errores sintácticos: %d, Errores léxicos %d y Errores semánticos: %d\n",yynerrs,errlex,semerrs);
        return 1;

    case 2:
        puts("Memoria insuficiente\n");
        return 2;
    }
    return 0;
}
