/*
 * OperacionesMatematicas.c
 *
 *  Created on: 12 sep. 2021
 *      Author: niqotery
 */

#include "OperacionesMatematicas.h"

float Sumar(float numeroX, float numeroY) {
	return numeroX + numeroY;
}
float Restar(float numeroX, float numeroY) {
	return numeroX - numeroY;
}
int Dividir(float numeroX, float numeroY, float* resultado) {
	int sePuedeDividir;

	if (numeroY == 0) {
		sePuedeDividir = 0;
	} else {
		sePuedeDividir = 1;
		*resultado = numeroX / numeroY;
	}

	return sePuedeDividir;
}
float Multiplicar(float numeroX, float numeroY) {
	return numeroX * numeroY;
}

float CalcularFactorial(float numero) {

	int factorial;

	if (numero == 0) {
		factorial = 1;
	} else if (numero - (int)numero > 0 || (numero > 10 || numero < 0)) {
        //El factorial del numero es demasiado grande , es un numero con coma o negativo.
        factorial = 0;
    }else {
		factorial = numero * CalcularFactorial(numero - 1);
	}

	return factorial;
}
