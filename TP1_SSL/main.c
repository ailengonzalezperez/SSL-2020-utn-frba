/*
 * main.c
 * Trabajo práctico 1: Escáner Elemental
 * Sintaxis y semántica de los lenguajes
 * Curso K2053
 * Ailén Y. González Pérez - 169.982-9
 * Sofía Chamorro - 147.303-7
 * Daniel Bareiro - 153.667-9
 */

#define SALIDA_EXITOSA 0
#include <stdio.h>
#include "scanner.h"

int main(){

	int totalIdentificadores = 0; //Contador de identificadores
	int totalConstantes = 0; //Contador de constantes
	int totalErrores = 0; //Contador de errores
	int totalNumerales = 0; //Contador de numerales

	TOKEN tokenReconocido; //Voy guardando aquí los token que leo

	while (tokenReconocido != FDA){ //El análisis termina cuando tengo el fin de archivo

		tokenReconocido = scannerElemental(); //Busco el token actual

		switch(tokenReconocido){

			case IDENTIFICADOR:
				printf("Identificador\n");
				totalIdentificadores++;
				break;

			case CONSTANTE_ENTERA:
				printf("Constante entera\n");
				totalConstantes++;
				break;

			case ERROR:
				printf("Error\n");
				totalErrores++;
				break;

			case TNUMERAL:
				printf("Numeral\n");
				totalNumerales++;

            case FDA:
            	break;
        }
	}

	//Cuando termina el archivo, no tengo más para leer
	//Muestro resultados finales

    printf("----\n");
    printf("Totales:\n");
    printf("  Identificadores %d\n", totalIdentificadores);
    printf("  Constantes enteras %d\n", totalConstantes);
    printf("  Numerales %d\n", totalNumerales);
    printf("  Errores %d\n", totalErrores);


    return SALIDA_EXITOSA;
}
