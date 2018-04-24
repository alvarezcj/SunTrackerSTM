/*
 * Encoder.cpp
 *
 *  Created on: 12 abr. 2018
 *      Author: VSPC-EternalStormV2
 */

#include <models/HW/Encoder.h>

///Constructor
Encoder::Encoder(TIM_HandleTypeDef *htim, uint8_t selector):
output(0),
m_htim(htim),
m_selector(selector)
{
	if(HAL_OK != HAL_TIM_Encoder_Start(m_htim, TIM_CHANNEL_ALL))
	{
		//Tratamiento de error
		while(1);
	}
}

///Destructor
Encoder::~Encoder()
{
}
///Método de ejecución particular del bloque derivado
void Encoder::StepBlockNoError(void)
{
	switch(m_selector)
	{
	case 2:
		output = (float)TIM2->CNT;
		break;
	case 3:
		output = (float)TIM3->CNT;
		break;
	default:
		//Error
		while(1);
	}

}
///Método que comprueba si el bloque se puede ejecutar
bool Encoder::Safe2Run(void)
{
	return true;
}
