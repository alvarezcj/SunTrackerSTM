/*
 * block.h
 *
 *  Created on: 10 abr. 2018
 *      Author: VSPC-EternalStormV2
 */

#ifndef MODELS_BLOCK_H_
#define MODELS_BLOCK_H_

class Block {
public:
	//Atributos

	//Metodos
	///Constructor
	Block();
	///Destructor
	virtual ~Block();
	///Método de ejecución del bloque
	void Step(void);
	///Método de ejecución particular del bloque derivado
	virtual void StepBlockNoError(void) = 0;
	///Método que comprueba si el bloque se puede ejecutar
	virtual bool Safe2Run(void) = 0;


protected:
	//Atributos

	//Metodos

private:
	//Atributos

	//Metodos
};

///Metodo para conectar la salida de  un bloque con la entrada de otro
template<class T>
void Connect(T& output,T*& input)
{
	input = &output;
}
template<class T, class U>
void Connect(T& output, U*& input)
{
	input = static_cast<U*>(&output);
}
#endif /* MODELS_BLOCK_H_ */
