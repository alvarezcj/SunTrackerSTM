/*
 * tasks.h
 *
 *  Created on: 7 abr. 2018
 *      Author: VSPC-EternalStormV2
 */

#ifndef RUNTIME_TASKS_H_
#define RUNTIME_TASKS_H_

//Include de librerías estandar

//Include de librerías de proyecto

//Include de clases de usuario
#include "models/HW/GPIOLogic.h"
#include "models/HW/Encoder.h"
#include "models/HW/PWM.h"
#include "models/PID.h"
#include "models/Adder.h"
#include "utility/Logger.h"
#include "utility/SDDriver.h"
//Declaración de tipo de variable
//Declaración de la clase
class Tasks
{
public:
	//Atributos

	//Métodos
	///Constructor
	Tasks();
	///Destructor
	~Tasks();
	///Step de la tarea main
	void StepMainTask(void);

protected:
	//Atributos

	//Métodos

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
	//Métodos


};



#endif /* RUNTIME_TASKS_H_ */
