/*
 * scanner.h
 */

#ifndef SCANNER_H
#define SCANNER_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

typedef enum{DIGITO, LETRA, NUMERAL, ESPACIO, OTRO, FDF} TIPO_CARACTER; //FDF fin de file
typedef enum{CONSTANTE_ENTERA, IDENTIFICADOR, TNUMERAL, ERROR, FDA} TOKEN; //TNUMERAL = TokenNumeral para diferenciar del otro

bool deboParar(int estado);
int nuevoEstado(char caracterLeido, int estadoActual);
TOKEN tokenAceptado(int estadoAceptor, char caracter);
TOKEN scannerElemental();




#endif // SCANNER_H



