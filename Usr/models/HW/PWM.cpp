/*
 * PWM.cpp
 *
 *  Created on: 19 abr. 2018
 *      Author: VSPC-EternalStormV2
 */

#include "PWM.h"

PWM::PWM(TIM_HandleTypeDef* htim, uint32_t channel):
		input(nullptr),
		m_duty(0),
		m_htim(htim),
		m_channel(channel)
{
	HAL_TIM_PWM_Start(m_htim, m_channel);
}
///Destructor
PWM::~PWM()
{

}
///Método de ejecución particular del bloque derivado
void PWM::StepBlockNoError(void)
{
	m_duty =  *input;
	PWMSetValue(m_duty);
}
///Método que comprueba si el bloque se puede ejecutar
bool PWM::Safe2Run(void)
{
	bool safe2run(true);
	safe2run &= (input != nullptr);
	return safe2run;
}
///Metodo que establece el ciclo de trabajo del PWM
void PWM::PWMSetValue(uint32_t value)
{
    TIM_OC_InitTypeDef sConfigOC;

    sConfigOC.OCMode = TIM_OCMODE_PWM1;
    sConfigOC.Pulse = value;
    sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
    sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
    HAL_TIM_PWM_ConfigChannel(m_htim, &sConfigOC, m_channel);
    HAL_TIM_PWM_Start(m_htim, m_channel);
}
