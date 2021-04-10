#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "symbol.h"

struct tablaSimbolos {
	char* variables[200];
	int indice;
}tablaDeSimbolos =  {.indice = 0};

void agregarVariable(char* variable){
	tablaDeSimbolos.variables[tablaDeSimbolos.indice]=variable;
	tablaDeSimbolos.indice++;
}

bool existeVariable(char* variable){
  for(int i=0; i<tablaDeSimbolos.indice; i++){
    char* variableActual = tablaDeSimbolos.variables[i];
    if(strcmp(variableActual, variable) == 0 )
      return true;
  }
  return false;
}
