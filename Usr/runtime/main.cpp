/*
 * main.cpp
 *
 *  Created on: 7 abr. 2018
 *      Author: VSPC-EternalStormV2
 */

#include "tasks.h"
#include "gpio.h"

void Tasks::StepMainTask(void)
{
	//Código a realzar en la tarea main
 	m_pruebagpio->Toggle();
	m_pruebaencoder->Step();
	m_adder->Step();
	m_PID->Step();
	m_pwm1->Step();
	m_pwm2->Step();
	//m_adder->Step();
}
