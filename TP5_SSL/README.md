# Trabajo práctico 5 - Sintaxis y semántica de los lenguajes

Ailén González Pérez

Daniel Bareiro

Sofía Chamorro

En base a lo hecho en TP4 agregaremos las rutinas semánticas para tener el compilador completo (en
realidad un front end si consideramos que nuestro seudo ensamblador es código intermedio)

Comandos

flex scanner.l 

bison parser.y 

gcc -Wall *.c -o compilador -lfl
