/*
 * Logger.cpp
 *
 *  Created on: 19 abr. 2018
 *      Author: VSPC-EternalStormV2
 */

#include <utility/Logger.h>
#include <stdio.h>




Logger::Logger()
{
	FILE *fp;
	fp = fopen("log.txt", "w");
	//fprintf(fp, "This is testing for fprintf...\n");
	fputs("This is testing for fputs...\n", fp);
	fclose(fp);
}

Logger::~Logger()
{
}

void Logger::StepBlockNoError(void)
{

}
///Método que comprueba si el bloque se puede ejecutar
bool Logger::Safe2Run(void)
{
	return true;
}
