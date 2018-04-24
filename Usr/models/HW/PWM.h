/*
 * PWM.h
 *
 *  Created on: 19 abr. 2018
 *      Author: VSPC-EternalStormV2
 */

#ifndef MODELS_HW_PWM_H_
#define MODELS_HW_PWM_H_

//Include de librerías estandar

//Include de librerías de proyecto
#include "tim.h"

//Include de clases de usuario
#include "models/block.h"

//Declaración de tipo de variable

//Espacio para la declaracion de la clase
class PWM: public Block {
public:
	//Atributos
	uint32_t* input;

	//Metodos
	///Constructor
	PWM(TIM_HandleTypeDef* htim,
			uint32_t channel);
	///Destructor
	virtual ~PWM();
	///Método de ejecución particular del bloque derivado
	void StepBlockNoError(void);
	///Método que comprueba si el bloque se puede ejecutar
	bool Safe2Run(void);
	///Metodo que establece el ciclo de trabajo del PWM
	void PWMSetValue(uint32_t value);


protected:
	//Atributos

	//Metodos

private:
	//Atributos
	///Ciclo de trabajo
	uint32_t m_duty;
	///Identificador del pin
	TIM_HandleTypeDef* m_htim;
	///Numero de pin
	uint32_t m_channel;

	//Metodos
};




#endif /* MODELS_HW_PWM_H_ */
