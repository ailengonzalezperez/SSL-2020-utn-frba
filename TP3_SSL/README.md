# Trabajo práctico 3 - Sintaxis y semántica de los lenguajes

Ailén González Pérez

Daniel Bareiro

Sofía Chamorro


En base a la gramática léxica hecha en el TP1 armar un programa que la reconozca usando la herramienta flex.


Comandos: En consola, estando parados en el directorio con los archivos del TP y suponiendo que a la
especificación de flex la llamó scanner.l debería bastar con: flex scanner.l ya que el nombre de
archivo de salida debe estar indicado en las directivas.
Suponiendo que generó el archivo scanner.c para compilar puede usar:
gcc -g -Wall scanner.c main.c -o scantest -lfl
Alternativa
gcc -Wall -D_GNU_SOURCE -std=c17 -pedantic-errors -o scantest -lfl
Para ejecutar: ./scantest <entrada.txt >salida.txt