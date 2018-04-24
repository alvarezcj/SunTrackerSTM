/*
 * Logger.h
 *
 *  Created on: 19 abr. 2018
 *      Author: VSPC-EternalStormV2
 */

#ifndef UTILITY_LOGGER_H_
#define UTILITY_LOGGER_H_

#include <models/block.h>

class Logger: public Block {
public:
	//Atributos

	//Metodos
	///Constructor
	Logger();
	///Destructor
	virtual ~Logger();
	///Método de ejecución particular del bloque derivado
	void StepBlockNoError(void);
	///Método que comprueba si el bloque se puede ejecutar
	bool Safe2Run(void);

protected:

private:


};

#endif /* UTILITY_LOGGER_H_ */
