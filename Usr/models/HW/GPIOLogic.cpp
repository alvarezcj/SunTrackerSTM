/*
 * GPIOLogic.cpp
 *
 *  Created on: 10 abr. 2018
 *      Author: VSPC-EternalStormV2
 */

#include <models/HW/GPIOLogic.h>

GPIOLogic::GPIOLogic(kType type,
		kLogic logic,
		GPIO_TypeDef* GPIOx,
		uint16_t pin):
		m_type(type),
		m_logic(logic),
		m_GPIOx(GPIOx),
		m_pin(pin)
{
	input = nullptr;
}

GPIOLogic::~GPIOLogic()
{
	// TODO Auto-generated destructor stub
}

///Método de ejecución particular del bloque derivado
void GPIOLogic::StepBlockNoError(void)
{
	//TODO: mejorar con gestion de errores en caso de que no se cumpla ninguna
	if(*input == true)
	{
		if(m_logic == kLogicNormal)
		{
			HAL_GPIO_WritePin(m_GPIOx, m_pin, GPIO_PIN_SET);
		}
		else
		{
			HAL_GPIO_WritePin(m_GPIOx, m_pin, GPIO_PIN_RESET);
		}
	}
	else
	{
		if(m_logic == kLogicNormal)
		{
			HAL_GPIO_WritePin(m_GPIOx, m_pin, GPIO_PIN_RESET);
		}
		else
		{
			HAL_GPIO_WritePin(m_GPIOx, m_pin, GPIO_PIN_SET);
		}
	}
}

///Método que comprueba si el bloque se puede ejecutar
bool GPIOLogic::Safe2Run(void)
{
	bool safe2run = true;
	safe2run &= (input != nullptr);
	return safe2run;
}

///Metodo que pone el pin a nivel alto
void GPIOLogic::Set(void)
{
	//TODO: mejorar con gestion de errores en caso de que no se cumpla ninguna
	if(m_logic == kLogicNormal)
	{
		HAL_GPIO_WritePin(m_GPIOx, m_pin, GPIO_PIN_SET);
	}
	else
	{
		HAL_GPIO_WritePin(m_GPIOx, m_pin, GPIO_PIN_RESET);
	}
}

///Metodo que pone el pin a nivel bajo
void GPIOLogic::Reset(void)
{
	if(m_logic == kLogicInverted)
	{
		HAL_GPIO_WritePin(m_GPIOx, m_pin, GPIO_PIN_SET);
	}
	else
	{
		HAL_GPIO_WritePin(m_GPIOx, m_pin, GPIO_PIN_RESET);
	}
}

///Metodo que alterna el estado del pin
void GPIOLogic::Toggle(void)
{
	HAL_GPIO_TogglePin(m_GPIOx, m_pin);
}
