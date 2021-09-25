/*
 * Menu.c
 *
 *  Created on: 12 sep. 2021
 *      Author: niqotery
 */
#include <stdio.h>
#include <stdlib.h>
#include "Menu.h"

int IniciarMenuCalculadora(float numeroX, float numeroY, int hayNumeroX, int hayNumeroY) {

	int opcion;

	printf("********************************************\n");
	if (hayNumeroX != 0) {
		printf("1. Ingresar 1er operando (A=%.2f)\n", numeroX);
	} else {
		printf("1. Ingresar 1er operando (A=x)\n");
	}
	if (hayNumeroY != 0) {
		printf("2. Ingresar 2do operando (B=%.2f)\n", numeroY);
	} else {
		printf("2. Ingresar 2do operando (B=y)\n");
	}

	printf("3. Calcular todas las operaciones \n");
	printf("    -Sumar  \n");
	printf("    -Restar  \n");
	printf("    -Dividir  \n");
	printf("    -Multiplicar  \n");
	printf("    -Factorial  \n");
	printf("4. Informar resultados\n");
	printf("5. Salir\n");
	printf("Ingrese una opcion: ");
	scanf("%d", &opcion);

	return opcion;
}
