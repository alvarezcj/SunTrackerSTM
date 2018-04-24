/*
 * PID.h
 *
 *  Created on: 11 abr. 2018
 *      Author: VSPC-EternalStormV2
 */

#ifndef MODELS_PID_H_
#define MODELS_PID_H_

//Seccion para incluir archivos de proyecto
#include <models/block.h>

//Seccion para la declaracion de variables
#define SAMPLETIME 2000 //Que coincida con cada cuanto se ejecuta la tarea en ms
//TODO: realizar el define del tiempo de ejecucion en el cube freertos

//Seccion para la declaracion de la clase
template<class T>
class PID: public Block {
public:
	//Atributos
	///Entrada al pid (error del sistema)
	T* input;
	///Salida del PID
	T output;

	//Metodos
	///Constructor
	PID():
		input(nullptr),
		output(0),
		m_kp(1.0f),
		m_ki(0.0f),
		m_kd(0.0f),
		m_errorInt(0),
		m_errorDeriv(0),
		m_prevInput(0)
	{

	}
	///Constructor copia
	PID(float kp, float ki, float kd):
		input(nullptr),
		output(0),
		m_kp(kp),
		m_ki(ki),
		m_kd(kd),
		m_errorInt(0),
		m_errorDeriv(0),
		m_prevInput(0)
	{
	}
	///Destructor
	virtual ~PID()
	{

	}
	///Método que comprueba si el bloque se puede ejecutar
	bool Safe2Run(void)
	{
		bool safe2run = true;
		safe2run &= (input !=  nullptr);
		return safe2run;
	}

	///Método de ejecución particular del bloque derivado
	void StepBlockNoError(void)
	{
		//Error integral acumulativo
		m_errorInt += *input*SAMPLETIME/1000.;
		//Error derivativo en funcion de la anterior entrada
		m_errorDeriv = (*input - m_prevInput)/(SAMPLETIME/1000.);
		//Actuializacion de la anterior entrada
		m_prevInput = *input;
		//Calculo ponderado del error total
		output = m_kp * *input + m_ki * m_errorInt + m_kd * m_errorDeriv;
	}

protected:
	//Atributos

	//Metodos

private:
	//Atributos
	///Ganancia proporcional
	float m_kp;
	///Ganancia integral
	float m_ki;
	///Ganancia derivada
	float m_kd;
	///Error integral
	float m_errorInt;
	///Error derivada
	float m_errorDeriv;
	///Error iteracion anterior
	double m_prevInput;

	//Metodos
};

#endif /* MODELS_PID_H_ */
