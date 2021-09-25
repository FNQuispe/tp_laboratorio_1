/*
 * Calculadora.c
 *
 *  Created on: 12 sep. 2021
 *      Author: niqotery
 */
#include <stdio.h>
#include <stdlib.h>
#include "Calculadora.h"

#include "ManejoDatos.h"
#include "Menu.h"
#include "OperacionesMatematicas.h"

#define MIN -9999
#define MAX 9999

void IniciarCalculadora() {
	int opcion;
	int hayOperadorX = 0;
	int hayOperadorY = 0;
	int seRealizaronOperaciones = 0;
	int sePuedeDividir;
	float numeroX;
	float numeroY;
	float resultadoSuma;
	float resultadoResta;
	float resultadoDivision;
	float resultadoMultiplicacion;
	float resultadoFactorialX;
	float resultadoFactorialY;


	do {
		opcion = IniciarMenuCalculadora(numeroX, numeroY, hayOperadorX, hayOperadorY);
		switch (opcion) {
		case 1:
			numeroX = IngresarNumero("Ingrese el numero X", MIN, MAX);
			hayOperadorX = 1;
			break;
		case 2:
			numeroY = IngresarNumero("Ingrese el numero Y", MIN, MAX);
			hayOperadorY = 1;
			break;
		case 3:
			if (hayOperadorX == 0 || hayOperadorY == 0) {
				printf("Faltan numeros, ingreselos.\n");
			} else {
				seRealizaronOperaciones = 1;

				resultadoSuma = Sumar(numeroX, numeroY);
				resultadoResta = Restar(numeroX, numeroY);
				sePuedeDividir = Dividir(numeroX, numeroY, &resultadoDivision);
				resultadoMultiplicacion = Multiplicar(numeroX, numeroY);
				resultadoFactorialX = CalcularFactorial(numeroX);
				resultadoFactorialY = CalcularFactorial(numeroY);
			}
			break;
		case 4:
			if (hayOperadorX == 0 || hayOperadorY == 0) {
				printf("Faltan numeros para calcular, ingreselos... \n");
			} else if (seRealizaronOperaciones == 0) {
				printf("No se han calculado las operaciones. Por favor, realizar los calculos... \n");
			} else {
				printf("Los resultados de las operaciones son: \n");
				MostrarResultados("Suma: ", resultadoSuma);
				MostrarResultados("Resta: ", resultadoResta);
				MostrarResultadoDivision("Division: ", resultadoDivision, sePuedeDividir);
				MostrarResultados("Multiplicacion: ", resultadoMultiplicacion);
				MostrarResultadoFactorial("Factorial X:", resultadoFactorialX, numeroX);
				MostrarResultadoFactorial("Factorial Y:", resultadoFactorialY, numeroY);

				//Reinicio la bandera para volver a calcular en caso de que se cambien los operando
				seRealizaronOperaciones = 0;
			}
			break;
		case 5:
			printf("Gracias por usar la calculadora!!\n");
			break;
		default:
			printf("No se ha ingresado una opcion valida. Vuelva a intentar...\n");
			break;
		}
	} while (opcion != 5);
}

