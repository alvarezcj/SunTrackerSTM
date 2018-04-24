/*
 * SDDriver.h
 *
 *  Created on: 22 abr. 2018
 *      Author: VSPC-EternalStormV2
 */

#ifndef UTILITY_SDDRIVER_H_
#define UTILITY_SDDRIVER_H_
//Include de librerías estandar
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

//Include de librerías de proyecto

//Include de clases de usuario
#include "fatfs.h"

//Declaración de tipo de variable
//Declaración de la clase
class SDDriver {
public:
	//Atributos

	//Metodos
	///Constructor
	SDDriver(void);
	///Destructor
	virtual ~SDDriver(void);

protected:
	//Atributos

	//Metodos

private:
	//Atributos
	/* File system object structure (FATFS) */
	FATFS m_fs;
	/* File object structure (FIL) */
	FIL m_fil;
	/* File function return code (FRESULT) */
	FRESULT m_fres;

	uint8_t m_SD_Buffer[15];

	//Metodos

};

#endif /* UTILITY_SDDRIVER_H_ */
