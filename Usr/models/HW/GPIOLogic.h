/*
 * GPIOLogic.h
 *
 *  Created on: 10 abr. 2018
 *      Author: VSPC-EternalStormV2
 */

#ifndef MODELS_HW_GPIOLOGIC_H_
#define MODELS_HW_GPIOLOGIC_H

//Include de librerías estandar

//Include de librerías de proyecto
#include "gpio.h"

//Include de clases de usuario
#include "models/block.h"

//Declaración de tipo de variable
///Tipo de logica del pin
enum kLogic
{
	kLogicNormal = 0,
	kLogicInverted
};
///Tipo de pin
enum kType
{
	kTypeInput = 0,
	kTypeOutput
};
//Espacio para la declaracion de la clase
class GPIOLogic: public Block {
public:
	//Atributos
	bool* input;

	//Metodos
	///Constructor
	GPIOLogic(
			kType type,
			kLogic logic,
			GPIO_TypeDef* GPIOx,
			uint16_t pin);
	///Destructor
	virtual ~GPIOLogic();
	///Método de ejecución particular del bloque derivado
	void StepBlockNoError(void);
	///Método que comprueba si el bloque se puede ejecutar
	bool Safe2Run(void);
	///Metodo que pone el pin a nivel alto
	void Set(void);
	///Metodo que pone el pin a nivel bajo
	void Reset(void);
	///Metodo que alterna el estado del pin
	void Toggle(void);

protected:
	//Atributos

	//Metodos

private:
	//Atributos
	///Tipo de pin
	kType m_type;
	///Logica del pin
	kLogic m_logic;
	///Identificador del pin
	GPIO_TypeDef* m_GPIOx;
	///Numero de pin
	uint16_t m_pin;

	//Metodos
};

#endif /* MODELS_HW_GPIOLOGIC_H_ */
