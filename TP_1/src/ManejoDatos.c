/*
 * IngresoDatos.c
 *
 *  Created on: 12 sep. 2021
 *      Author: niqotery
 */
#include <stdio.h>
#include <stdlib.h>

#include "ManejoDatos.h"

float IngresarNumero(char mensaje[], int min, int max) {
	float numeroIngresado;

	printf("%s\n", mensaje);
	scanf("%f", &numeroIngresado);

	while (numeroIngresado < min || numeroIngresado > max) {
		printf("Error, el numero ingresado debe ser mayor a %d y menor a %d. Reingresar un numero:\n", min, max);
		scanf("%f", &numeroIngresado);
	}

	return numeroIngresado;
}

void MostrarResultados(char mensaje[], float resultado) {
	printf("%s %.2f\n", mensaje, resultado);
}

void MostrarResultadoDivision(char mensaje[], float resultado,
		int sePuedeDividir) {
	if (sePuedeDividir == 0) {
		printf("No es posible dividir por cero");
	} else {
		MostrarResultados(mensaje, resultado);
	}
}

void MostrarResultadoFactorial(char mensaje[], float resultado, float numeroIngresado) {
	if (resultado == 0) {
		printf("No es posible calcular el factorial del numero %.2f \n", numeroIngresado);
	} else {
		MostrarResultados(mensaje, resultado);
	}
}
