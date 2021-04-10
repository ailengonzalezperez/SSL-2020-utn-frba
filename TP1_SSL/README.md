# Trabajo Práctico 1 - Sintaxis y semántica de los lenguajes


Ailén González Pérez

Daniel Bareiro

Sofía Chamorro

Programaremos un autómata finito determinístico (AFD) que reconozca tres lenguajes, el de las constantes enteras, el de los identificadores y el de numeral.
Lenguaje de las constantes enteras: son las cadenas formadas solamente por dígitos decimales
Lenguaje de los identificadores: son las cadenas que comienzan con una letra (no importa si mayúscula o minúscula) y siguen luego con letras o dígitos.
Lenguaje numeral: es un lenguaje formado solamente por un símbolo numeral

Vía Consola
gcc -std=c11 -pedantic-errors -Wall -o scannerElemental main.c scanner.c


Ejecución:
./scannerElemental < archivoDePrueba

Ej. ./scannerElemental < datosPrueba.txt  

Lo que hace el < es redirigir el standard input a un archivo. Si se ejecuta ./scannerElemental podemos ir ingresando por consola los datos
