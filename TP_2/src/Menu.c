/*
 * Menu.c
 *
 *  Created on: 16 oct. 2021
 *      Author: niqotery
 */

#include "Menu.h"

int generarMenu(void) {
	int opcion;
	system("cls");
	printf("  |------------------------------------|\n");
	printf("  |  *****Gestion de Empleados*****    |\n");
	printf("  |  1- Alta                           |\n");
	printf("  |  2- Modificar                      |\n");
	printf("  |  3- Baja                           |\n");
	printf("  |  4- Informes                       |\n");
	printf("  |  5- Salir                          |\n\n");
	printf("  |  Ingrese numero de opcion: ");
	scanf("%d", &opcion);
	while (opcion > 5 || opcion < 1) {
		printf("  |   Error. Opcion incorrecta.\n");
		printf("  |   Ingrese numero de opcion: ");
		scanf("%d", &opcion);
	}
	return opcion;
}
