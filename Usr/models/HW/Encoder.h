/*
 * Encoder.h
 *
 *  Created on: 12 abr. 2018
 *      Author: VSPC-EternalStormV2
 */

#ifndef MODELS_HW_ENCODER_H_
#define MODELS_HW_ENCODER_H_

//Include de librerías estandar
#include <cstdint>
//Include de librerías de proyecto
#include "tim.h"

//Include de clases de usuario
#include "models/block.h"

//Espacio para la declaracion de la clase
class Encoder : public Block{
public:
	//Atributos
	uint32_t output;
	//Metodos
	///Constructor
	Encoder(TIM_HandleTypeDef *htim, uint8_t selector);
	///Destructor
	virtual ~Encoder();
	///Método de ejecución particular del bloque derivado
	void StepBlockNoError(void);
	///Método que comprueba si el bloque se puede ejecutar
	bool Safe2Run(void);

protected:
	//Atributos
	///Handler del timer asociado al encoder
	TIM_HandleTypeDef *m_htim;
	///Numero de selecion del timer
	uint8_t m_selector;
	//Metodos

private:
	//Atributos

	//Metodos;
};

#endif /* MODELS_HW_ENCODER_H_ */
