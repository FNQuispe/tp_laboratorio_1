/*
 ============================================================================
 Name        : TP_2.c
 Author      : Fernando Nicolás Quispe
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "ArrayEmployees.h"
#include "Menu.h"

#define ELEMENTS 3

int main(void) {
	setbuf(stdout, NULL);
	char seguir='s';
	char confirma;
	int opcion;
	Employee arrayEmployees[ELEMENTS];
	initEmployees(arrayEmployees, ELEMENTS);

	do {
		opcion = generarMenu();
		switch (opcion) {
			case 1: {
				getDataEmployee(arrayEmployees, ELEMENTS);
				break;
			}
			case 2: {
				if (checkCreatedEmployees(arrayEmployees, ELEMENTS) == -1) {
					printf("  |  No hay empleados cargados en el sistema.\n");
				} else {
					modifyEmployee(arrayEmployees, ELEMENTS);
				}
				break;
			}
			case 3: {
				if (checkCreatedEmployees(arrayEmployees, ELEMENTS) == -1) {
					printf("  |  No hay empleados cargados en el sistema.\n");
				} else if (removeEmployee(arrayEmployees, ELEMENTS) == -1){
					printf("\n  |  No existe empleado con el id ingresado: \n");
				}
				break;
			}
			case 4: {
				if (checkCreatedEmployees(arrayEmployees, ELEMENTS) == -1) {
					printf("  |  No hay empleados cargados en el sistema.\n");
				} else {
					reportEmployees(arrayEmployees, ELEMENTS);
				}
				break;
			}
			case 5: {
				printf("  |  Confirma salir de gestion de empleados?(s/n): ");
				fflush(stdin);
				scanf("%c", &confirma);
				if (confirma == 's') {
					seguir = 'n';
					printf("\n  |  Saliendo del sistema...  \n");
				}
				break;
			}
		}
		system("pause");
	} while (seguir == 's');
	return 0;
}


