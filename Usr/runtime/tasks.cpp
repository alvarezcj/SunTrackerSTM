/*
 * tasks.cpp
 *
 *  Created on: 7 abr. 2018
 *      Author: VSPC-EternalStormV2
 */

/* Definicion de los metodos de la clase tasks*/
#include "tasks.h"

//Constructor
Tasks::Tasks(void)
{
	///Objetos que se inicialicen
	m_pruebagpio = new GPIOLogic(kTypeOutput,kLogicNormal,GPIOD,GPIO_PIN_12);
	m_pruebaencoder = new Encoder(&htim2,(uint8_t)2);
	m_PID = new PID<uint32_t>();
	m_adder = new Adder<uint32_t>();
	m_pwm1 = new PWM(&htim4, TIM_CHANNEL_1);
	m_pwm2 = new PWM(&htim4, TIM_CHANNEL_2);

	//m_logger = new Logger();
	prueba = new SDDriver();

	///Relacion entre los objetos
	Connect( m_adder->output, m_PID->input);
	Connect(m_pruebaencoder->output, m_adder->inputs.at(0));
	Connect(m_PID->output, m_adder->inputs.at(1));
	Connect(m_PID->output, m_pwm1->input);
	Connect(m_PID->output, m_pwm2->input);

}

//Destructor
Tasks::~Tasks(void)
{

}

#include "tasks.h"

#ifdef __cplusplus
extern "C"
{
#endif

//Declaración de puntos de entrada C->C++

///Punto de entrada al constructor
void* tasksCreate(void)
{
	return new Tasks();
}

///Punto de entrada al destructor
void taskDelete(void* obj)
{
	delete static_cast<Tasks*>(obj);
}

///Punto de entrada a la tarea main
void StepMainTask(void* obj)
{
	static_cast<Tasks*>(obj)->StepMainTask();
}

#ifdef __cplusplus
}
#endif
