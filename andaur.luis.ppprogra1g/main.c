#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMNOT 5
/*1. Crear una funci�n llamada aplicarDescuento que reciba como par�metro el precio
de un producto y devuelva el valor del producto con un descuento del 5%. Realizar la llamada desde el main.

2. Crear una funci�n que se llame contarCaracteres que reciba una cadena de caracteres como primer par�metro
y un car�cter como segundo y devuelva la cantidad de veces que ese car�cter aparece en la cadena.

3. Dada la estructura Notebook(id, procesador, marca, precio) generar una funci�n que permita ordenar un array
de dicha estructura por marca. Ante igualdad de marca deber� ordenarse por precio. Hardcodear datos y mostrarlos desde el main. **/

typedef struct{
    int id;
    char procesador[21];
    char marca[21];
    float precio;
}eNotebook;

float aplicarDescuento(float precio);
int contarCaracteres(char cadena[], char caracter);

int main()
{
    //FUNCION 1
    float respuesta;
    respuesta = aplicarDescuento(100);
    printf("El precio con descuento es: $%.2f.\n\n", respuesta);

    //FUNCION 2
    char cadena[21] = {"alpargata"};
    int contador;
    contador = contarCaracteres(cadena,'a');
    printf("El caracter aparece %d veces.\n\n", contador);

    //FUNCION 3
    eNotebook noteboos[TAMNOT] = {
        {500,"Pentium","Intel",4500},
        {501,"Core i5","Intel",100},
        {502,"Corei7","Intel",2500},
        {503,"Ryzen 5","AMD",1000},
        {504,"Ryzen 7","AMD",2000},
    };

    ordenarEstructura(notebooks,TAMNOT);

    return 0;
}

float aplicarDescuento(float precio){
    float precioConDescuento;
    precioConDescuento = precio - (precio*5/100);

    return precioConDescuento;
}

int contarCaracteres(char cadena[], char caracter){
    int contador = 0;
    int tam;

    tam = strlen(cadena);
    if(cadena!=NULL){
        for(int i=0;i<tam;i++){
            if(cadena[i]==caracter){
                contador++;
            }
        }
    }
    return contador;
}

void ordenarEstructura(eNotebook notebooks[], int tamnot){
    eNotebook auxNotebook;
    for(int i=0;i<tam-1;i++){
        for(int j=i+1;j<tam;j++){
            if(strcmpi(notebooks[i].marca,notebooks[j].marca)<0 || (strcmpi(notebooks[i].marca,notebooks[j].marca)==0 && notebooks[i].precio>notebooks[j].precio){
                auxNotebook = notebooks[i];
                notebooks[i] = notebooks[j];
                notebooks[j] = auxNotebook;
            }
        }
    }
}
