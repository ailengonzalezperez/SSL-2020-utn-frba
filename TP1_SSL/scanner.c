/*
 * scanner.c
 */

/*
Tabla de transiciones
 	 Dígito		Letra	#	Espacio*	Otro	eof
0-		1		2		6		0		3		8
1		1		4		4		4		4		4
2		2		2		5		5		5		5
3		7		7		7		7		3		7
4+		-		-		-		-		-		-
5+		-		-		-		-		-		-
6+		-		-		-		-		-		-
7+		-		-		-		-		-		-
8+		-		-		-		-		-		-
 *
 */


#include "scanner.h"

static int tablaTransiciones[4][6] = {
    { 1, 2, 6, 0, 3, 8}, // Inicial > Directamente Numeral se acepta con 6 y FDA con 8.Los otros derivan a los otros estados
	{ 1, 4, 4, 4, 4, 4}, // Constante entera > se acepta con 4
	{ 2, 2, 5, 5, 5, 5}, // Identificador > se acepta con 5
	{ 7, 7, 7, 7, 3, 7}, // Error > se acepta con 7
};


bool deboParar(int estado){
	return (estado > 3); //Los estados 4 en adelante son aceptores y debo parar la lectura
}


int nuevoEstado(char caracterLeido,int estadoActual){

	if(isalpha(caracterLeido)){
		return tablaTransiciones[estadoActual][LETRA];
		//Entre por fila de estado actual y columna de letras

	}	else if(isdigit(caracterLeido)){
			return tablaTransiciones[estadoActual][DIGITO];
			//Entre por fila de estado actual y columna de dígitos

	}	else if(isspace(caracterLeido)){
			return tablaTransiciones[estadoActual][ESPACIO];
			//Entre por fila de estado actual y columna de espacios

	}	else if (caracterLeido == EOF ){
			return tablaTransiciones[estadoActual][FDF];
		//Entre por fila de estado actual y columna de fin de archivo

	}	else if (caracterLeido == '#'){
			return tablaTransiciones[estadoActual][NUMERAL];
			//Entre por fila de estado actual y columna de NUMERAL
	}

	return tablaTransiciones[estadoActual][OTRO];
	//Entre por fila de estado actual y columna de otros
}

TOKEN tokenAceptado(int estadoAceptor, char caracter){
	//Defino que token encontre según estado aceptor

    switch(estadoAceptor){
		case 4:
			ungetc(caracter,stdin); //Contante entera tiene centinela
			return CONSTANTE_ENTERA;
		case 5:
			ungetc(caracter,stdin); //Identificador tiene centinela
			return IDENTIFICADOR;

		case 6:
			return TNUMERAL; //Numeral no tiene centinela
		case 7:
			ungetc(caracter,stdin); //Error tiene centinela
			return ERROR;
	}
    return FDA; //Case 8 -> no tiene centinela el fin de archivo
}

TOKEN scannerElemental(){
	int estadoActual = 0; //Estado inicial
	char caracter;
	while (!deboParar(estadoActual)){ //Si es aceptor, debo parar. Si no, sigo leyendo.
		caracter  = getchar(); //tomo siguiente caracter
        estadoActual = nuevoEstado(caracter,estadoActual); //Actualizo el estado según el actual y el leido
	}
	return tokenAceptado(estadoActual,caracter); //Analizo el estado aceptor y miro que token reconoci
}
