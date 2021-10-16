#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayEmployees.h"
#include "utn_quispe.h"

#define TRUE 1
#define FALSE 0
#define LEN_STRINGS 51
#define RETRY 3

static int AutogenerateId(void);

/// @brief Lista todos los empleados
/// @param Employee* vec: vectores de empleados
/// @param  int len: tamaño del vector
/// @return  1 si se hay impreso correctamente los empleados o 0 si no hay empleados a imprimir
int printEmployees(Employee *vec, int len) {
	int flag = 0;
	system("cls");
	printf(
			"  |---------------------------------------------------------------------|\n");
	printf(
			"  |                    ****** Listado de Empleados *****                 \n\n");
	printf(
			"  |    id       Nombre     Apellido     Sueldo            Sector\n");
	if (vec != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			if (vec[i].isEmpty == 0) {
				listEmployee(&vec[i]);
				flag = 1;
			}
		}
	}

	return flag;

}

/// @brief Lista un empleado
/// @param Employee* vec: vector de empleado
void listEmployee(Employee *vec) {
	printf("  |  %d   %10s   %10s    %.2f    %13d\n", vec->id, vec->name,
			vec->lastName, vec->salary, vec->sector);
}

/// @brief Busca un lugar libre en la estructura de empleados
/// @param Employee* vec: vectores de empleados
/// @param int len: tamaño del vector
/// @return el indice del primer elemento libre que encuentre
int searchFree(Employee *vec, int len) {
	int indice = -1;

	if (vec != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			if (vec[i].isEmpty == TRUE) {
				indice = i;
				break;
			}
		}
	}

	return indice;
}

/// @brief Busca si hay al menos un empleado cargado
/// @param Employee* vec: vectores de empleados
/// @param int len: tamaño del vector
/// @return -1 si no hay empleados cargados, 0 si encontro uno.
int checkCreatedEmployees(Employee vec[], int len) {
	int retorno = -1;

	if (vec != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			if (vec[i].isEmpty == FALSE) {
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}

/// @brief Indica que todas las posiciones del vector estan vacias.
///        Esta funcion pone la bandera isEmpty en TRUE en todas las posiciones del vector.
/// @param list Employee* Puntero al vectorer Employees.
/// @param tam int Longitud del vector.
/// @return int Retorna (-1) si hay ERROR (longitud invalida o puntero NULL)
///         (0) si esta todo bien.
int initEmployees(Employee *vec, int len) {
	int retorno = -1;
	if (vec != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			vec[i].isEmpty = TRUE;
		}
		retorno = 0;
	}
	return retorno;
}

/// @brief Agrega un empleado al sistema
/// @param int idx: es el proximo numero de id
/// @param Employee* list: vectores de empleados
/// @param int len: tamaño del vector
/// @return Retorna 0 si no pudo dar de alta, 1 si se pudo de dar de alta al empleado
int addEmployee(Employee *list, int len, int id, char name[], char lastName[], float salary, int sector) {
	int retorno = FALSE;
	int indice = searchFree(list, len);

	if (indice == -1) {
		printf("  |   Sistema Completo\n\n");
	} else {
		list[indice].id = id;
		strncpy(list[indice].name, name, LEN_STRINGS);
		strncpy(list[indice].lastName, lastName, LEN_STRINGS);
		list[indice].salary = salary;
		list[indice].sector = sector;
		list[indice].isEmpty = FALSE;
		retorno = TRUE;
	}
	return retorno;
}

/// @brief Pide los datos correspondientes al empleado al usuario y los valida.
/// @param Employee* list: vectores de empleados
/// @param int len: tamaño del vector
/// @return Retorna 0 si no pasaron las validaciones, 1 si pasaron las validaciones ok
int getDataEmployee(Employee *list, int len) {
	int retorno = FALSE;
	char nameAux[LEN_STRINGS];
	char lastNameAux[LEN_STRINGS];
	float salaryAux;
	int sectorAux;

	system("cls");
	printf("  |------------------------------------|\n");
	printf("  |   ******Alta Empleado******        |\n");

	if (list != NULL) {
		if (utn_getNombre(nameAux, LEN_STRINGS, "Ingrese el nombre del empleado: ", "Error, reingrese nombre", RETRY) == 0) {
			if (utn_getNombre(lastNameAux, LEN_STRINGS, "Ingrese el apellido del empleado: ", "Error, reingrese apellido", RETRY) == 0) {
				if (utn_getNumeroFlotante(&salaryAux, "Ingrese el salario del empleado: ", "Error, reingrese salario ", 0, 999999, RETRY) == 0) {
					if (utn_getNumero(&sectorAux, "Ingrese el numero de sector en donde se encuentra el empleado: ", "Error, reingrese sector", 1, 100, RETRY) == 0) {
						retorno = TRUE;
						addEmployee(list, len, AutogenerateId(), nameAux, lastNameAux, salaryAux, sectorAux);
					}
				}
			}
		}
	}

	return retorno;
}

/// @brief Busca empleado por numero de id
/// @param int id: numero de id para buscar empleado
/// @param Employee* vec: vectores de empleados
/// @param int len: tamaño del vector
/// @return Retorna -1 si no encontro empleado con ese id o el indice de dicho empleado si lo encontro
int findEmployeeById(Employee *vec, int len, int id) {
	int indice = -1;
	if (vec != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			if (vec[i].id == id && vec[i].isEmpty == FALSE) {
				indice = i;
				break;
			}
		}
	}
	return indice;
}

/// @brief Elimina empleado de el sistema
/// @param Employee* vec: vectores de empleados
/// @param int len: tamaño del vector
/// @return -1 si no encuentra empleado con el id ingresado, 0 si encontro el empleado y pudo removerlo con exito
int removeEmployee(Employee *list, int len) {
	int id;
	int existe;
	int retorno = -1;
	system("cls");
	printf("  |------------------------------------|\n");
	printf("  |  ******Baja Empleado******         |\n");
	printf("  |  Ingrese id: \n");
	scanf("%d", &id);
	existe = findEmployeeById(list, len, id);
	if (existe != -1) {
		retorno = 0;
		printf("\n  |  Se ha encontrado el empleado con id: %d\n", id);
		listEmployee(&list[existe]);
		list[existe].isEmpty = TRUE;
		printf("\n  |  Se ha realizado la baja con exito.\n\n");
	}

	return retorno;
}

/// @brief Ordena los empleados por apellido y por sector
/// @param Employee* list: vectores de empleados
/// @param int len: tamaño del vector
/// @param int order: manera de ordenar. 1 ascendente 0 descendente
/// @return int Retorna (-1) si hay ERROR (longitud invalida o puntero NULL)
///         (0) si esta todo bien.
int sortEmployees(Employee *list, int len, int order) {
	int retorno = -1;
	Employee auxEmployee;

	if (list != NULL && len > 0) {
		retorno = 0;
		for (int i = 0; i < len; i++) {
			for (int j = i + 1; j < len; j++) {
				if (order == 1) {
					if (strcmp(list[i].lastName, list[j].lastName) > 0) {
						auxEmployee = list[i];
						list[i] = list[j];
						list[j] = auxEmployee;
					} else if (strcmp(list[i].lastName, list[j].lastName) == 0
							&& list[i].sector > list[j].sector) {
						auxEmployee = list[i];
						list[i] = list[j];
						list[j] = auxEmployee;
					}
				} else if (order == 0) {
					if (strcmp(list[i].lastName, list[j].lastName) < 0) {
						auxEmployee = list[i];
						list[i] = list[j];
						list[j] = auxEmployee;
					} else if (strcmp(list[i].lastName, list[j].lastName) == 0
							&& list[i].sector < list[j].sector) {
						auxEmployee = list[i];
						list[i] = list[j];
						list[j] = auxEmployee;
					}
				}
			}
		}
		printf("  |  Se ordenaron los empleados por apellido y por sector.\n");
	}

	return retorno;
}

/// @brief  Informes de empleados
/// @param Employee* vec: vectores de empleados
/// @param int len: tamaño del vector
void reportEmployees(Employee *vec, int len) {
	char seguir = 's';
	char confirma;
	int opcionOrdenar;
	do {
		switch (menuReports()) {
			case 'a': {
				if(printEmployees(vec, len) == 0) {
					printf("  |  ******No hay empleados que listar******\n");
				}
				break;
			}
			case 'b': {
				printf("  |  1-Ascendente.\n");
				printf("  |  0-Descendente.\n");
				printf("  |  Como ordenar los datos?: ");
				scanf("%d", &opcionOrdenar);
				if (opcionOrdenar == 1 || opcionOrdenar == 0) {
					sortEmployees(vec, len, opcionOrdenar);
				} else {
					printf("  |   Error. Opcion incorrecta.\n");
				}
				break;
			}
			case 'c': {
				reportSalaryTotalAverage(vec, len);
				break;
			}
			case 'o': {
				printf("  |  Confirma salir de menu informes?(s/n): ");
				fflush(stdin);
				scanf("%c", &confirma);
				if (confirma == 's') {
					seguir = 'n';
				}
				break;
			}
			default: {
				printf("  |   Error. Opcion incorrecta.\n");
			}
		}
		system("pause");
	} while (seguir == 's');
}

/// @brief Modifica empleado del sistema
/// @param Employee* vec: vectores de empleados
/// @param int len: tamaño de vector
void modifyEmployee(Employee *vec, int len) {
	int id;
	int existe;
	int opcion;
	system("cls");
	printf("  |------------------------------------------|\n");
	printf("  |      ******Modificar Empleado******      |\n");
	printf("  |      Ingrese id: ");
	scanf("%d", &id);
	existe = findEmployeeById(vec, len, id);
	if (existe == -1) {
		printf("  |      No existe empleado con este id: %d\n", id);
	} else {
		listEmployee(&vec[existe]);
		printf("  |------------------------------------|\n");
		printf("  | *** Que dato desea modificar? ***  |\n");
		printf("  |  1- Nombre                         |\n");
		printf("  |  2- Apellido.                      |\n");
		printf("  |  3- Salario.                       |\n");
		printf("  |  4- Sector.                        |\n");
		printf("  |  Ingrese el numero de opcion: ");
		scanf("%d", &opcion);

		switch (opcion) {
			case 1: {
				printf("  |  Ingrese nuevo nombre: ");
				utn_getNombre(vec[existe].name, LEN_STRINGS, "Ingrese el nombre del empleado: ", "Error, reingrese nombre", RETRY);
				printf("  |  Se ha actualizado el nombre con exito.\n");
				break;
			}
			case 2: {
				printf("  |  Ingrese nuevo apellido: ");
				utn_getNombre(vec[existe].lastName, LEN_STRINGS, "Ingrese el apellido del empleado: ", "Error, reingrese nombre", RETRY);
				printf("  |  Se ha actualizado el apellido con exito.\n");
				break;
			}
			case 3: {
				utn_getNumeroFlotante(&vec[existe].salary, "Ingrese el nuevo salario del empleado: ", "Error, reingrese salario ", 0, 999999, RETRY);
				printf("  |  Se ha actualizado el salario con exito.\n");
				break;
			}
			case 4: {
				utn_getNumero(&vec[existe].sector, "Ingrese el numero de sector en donde se encuentra el empleado: ", "Error, reingrese sector", 1, 100, RETRY);
				printf("  |  Se ha actualizado el sector con exito.\n");
				break;
			}
			default: {
				printf("  |  Error. Opcion incorrecta.");
			}
		}
	}
}
/// @brief Informe de sueldos totales y promedio
/// @param Employee* vec: vectores de empleados
/// @param int len: tamaño de vector
void reportSalaryTotalAverage(Employee *vec, int len) {
	float sueldoAcumulado = 0;
	int cantSueldos = 0;
	float promedioSueldos;
	int cantEmpleadosSueldoMayorQuePromedio = 0;
	system("cls");
	printf("  |------------------------------------|\n");
	printf("  |   ******Informe de Sueldos******   |\n\n");
	for (int i = 0; i < len; i++) {
		if (vec[i].isEmpty == 0) {
			sueldoAcumulado = sueldoAcumulado + vec[i].salary;
			cantSueldos++;
		}
	}
	promedioSueldos = sueldoAcumulado / cantSueldos;
	for (int i = 0; i < len; i++) {
		if (vec[i].isEmpty == 0 && vec[i].salary > promedioSueldos) {
			cantEmpleadosSueldoMayorQuePromedio++;
		}
	}
	printf("  |  Total sueldos de empleados: $ %.2f\n", sueldoAcumulado);
	printf("  |  Promedio de sueldos: $ %.2f\n", promedioSueldos);
	printf("  |  Cantidad de empleados que superan el sueldo promedio: %d\n\n",
			cantEmpleadosSueldoMayorQuePromedio);
}

/// @brief Menu de informes
/// @return Retorna el caracter de la opcion elegida
char menuReports() {
	char opcion2;
	system("cls");
	printf("  |------------------------------------|\n");
	printf("  |  *****Informes de Empleados*****   |\n");
	printf("  |  a- Listar Empleados               |\n");
	printf("  |  b- Ordenar Empleados              |\n");
	printf("  |  c- Total Sueldos y Promedio       |\n");
	printf("  |  o- Salir                          |\n");
	printf("  |  Ingrese letra de opcion: ");
	fflush(stdin);
	scanf("%c", &opcion2);

	return opcion2;
}

/// @brief funcion estatica que va incrementando en 1 un id
/// @return un id autogenerado
static int AutogenerateId(void) {
	static int id = 0;
	id++;
	return id;
}
