/*
 * tasks.h
 *
 *  Created on: 7 abr. 2018
 *      Author: VSPC-EternalStormV2
 */

#ifndef RUNTIME_TASKS_H_
#define RUNTIME_TASKS_H_

//Include de librer�as estandar

//Include de librer�as de proyecto

//Include de clases de usuario
#include "models/HW/GPIOLogic.h"
#include "models/HW/Encoder.h"
#include "models/HW/PWM.h"
#include "models/PID.h"
#include "models/Adder.h"
#include "utility/Logger.h"
#include "utility/SDDriver.h"
//Declaraci�n de tipo de variable
//Declaraci�n de la clase
class Tasks
{
public:
	//Atributos

	//M�todos
	///Constructor
	Tasks();
	///Destructor
	~Tasks();
	///Step de la tarea main
	void StepMainTask(void);

protected:
	//Atributos

	//M�todos

private:
	//Atributos
	Encoder* m_pruebaencoder;
	GPIOLogic* m_pruebagpio;
	PID<uint32_t>* m_PID;
	Adder<uint32_t>* m_adder;
	PWM* m_pwm1;
	PWM* m_pwm2;
	SDDriver* prueba;

	Logger* m_logger;
	//M�todos


};



#endif /* RUNTIME_TASKS_H_ */
