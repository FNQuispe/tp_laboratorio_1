/*
 * IngresoDatos.h
 *
 *  Created on: 12 sep. 2021
 *      Author: niqotery
 */

#ifndef MANEJODATOS_H_
#define MANEJODATOS_H_

/// @param Mensaje a mostrar al usuario
/// @return el numero flotante ingresado
/// @brief Pide al usuario un numero por pantalla y lo retorna
float IngresarNumero(char[], int, int);

/// @param Mensaje a mostrar
/// @param Resultado a mostrar
/// @brief Muestra un resultado en pantalla
void MostrarResultados(char[], float);

/// @param Mensaje a mostrar
/// @param Resultado a mostrar
/// @param Bandera de si se pudo dividir o no
/// @brief Muestra un resultado en pantalla. Si la division es por 0, entonces se le muestra al usuario un mensaje de error.
void MostrarResultadoDivision(char[], float, int);

/// @param Mensaje a mostrar
/// @param Resultado a mostrar
/// @param Numero ingresado
/// @brief Muestra un resultado en pantalla. Si el numero ingresado es negativo o muy grande, entonces se le muestra al usuario un mensaje de error.
void MostrarResultadoFactorial(char[], float, float);


#endif /* MANEJODATOS_H_ */
