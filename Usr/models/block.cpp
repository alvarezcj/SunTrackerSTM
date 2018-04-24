/*
 * block.cpp
 *
 *  Created on: 10 abr. 2018
 *      Author: VSPC-EternalStormV2
 */

#include "models/block.h"

//Constructor
Block::Block()
{

}

//Destructor
Block::~Block()
{

}

///M�todo de ejecuci�n del bloque
void Block::Step(void)
{
	///Se comprueba si se puede ejcutar el bloque
	if(!Safe2Run())
	{
		///Tratamiento del error
		while(1)
		{
		}
	}
	else
		StepBlockNoError();
}

/////M�todo que comprueba si el bloque se puede ejecutar
//bool Block::Safe2Run(void)
//{
//	return true;
//}
/////M�todo de ejecuci�n particular del bloque derivado
//void Block::StepBlockNoError(void)
//{
//
//}
