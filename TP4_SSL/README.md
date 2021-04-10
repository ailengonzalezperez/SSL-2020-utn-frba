# Trabajo práctico 4 - Sintaxis y semántica de los lenguajes

Ailén González Pérez

Daniel Bareiro

Sofía Chamorro


En base a la gramática Sintáctica hecha en el TP2 y la implementación de la gramática léxica hecha en
el TP3 armar un programa que usando la herramientas flex y bison reconozca un fuente en lenguaje
mini.
En este TP queremos reconocer la sintaxis sin generar el código de seudo ensamblador ni reconocer los
posibles errores semánticos.

Comandos

flex scanner.l
bison parser.y
gcc -Wall *.c -o compilador -lfl