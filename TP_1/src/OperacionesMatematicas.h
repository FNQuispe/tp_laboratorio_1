/*
 * OperacionesMatematicas.h
 *
 *  Created on: 12 sep. 2021
 *      Author: niqotery
 */

#ifndef OPERACIONESMATEMATICAS_H_
#define OPERACIONESMATEMATICAS_H_

/// @param Operador X
/// @param Operador Y
/// @brief Suma los operadores X+Y y muestra un mensaje en pantalla
float Sumar(float, float);

/// @param Operador X
/// @param Operador Y
/// @brief Resta los operadores X-Y y muestra un mensaje en pantalla
float Restar(float, float);

/// @param Operador X
/// @param Operador Y
/// @brief Divide los operadores X/Y y muestra un mensaje en pantalla
int Dividir(float, float, float*);

/// @param Operador X
/// @param Operador Y
/// @brief Multiplica los operadores X*Y y muestra un mensaje en pantalla
float Multiplicar(float, float);

/// @param Operador X
/// @param Operador Y
/// @brief Saca el factorial de los operadores X! Y! y muestra un mensaje en pantalla
float CalcularFactorial(float);

#endif /* OPERACIONESMATEMATICAS_H_ */
