#ifndef MODELS_ADDER_H_
#define MODELS_ADDER_H_

//Sección para incluir librerías generales
#include <vector>

//Seccion para incluir archivos de proyecto
#include <models/block.h>

//Seccion para la declaracion de variables
#define SAMPLETIME 500 //Que coincida con cada cuanto se ejecuta la tarea en ms

///Tipo de operación a realizar
enum kOperation
{
	kOperationAdd = 0,
	kOperationSubtract
};

//Seccion para la declaracion de la clase
template<class T>
class Adder: public Block {
public:
	//Atributos
	///Entrada al pid (error del sistema)
	std::vector<T*> inputs;
	///Salida del PID
	T output;

	//Metodos
	///Constructor
	Adder()
	{
		inputs = std::vector<T*>(2);
	}
	///Destructor
	virtual ~Adder()
	{

	}
	///Método que comprueba si el bloque se puede ejecutar
	bool Safe2Run(void)
	{
		bool safe2run = true;
		for (size_t i= 0; i< inputs.size(); i++)
		{
			safe2run &= (inputs.at(i) != nullptr);
		}
		return safe2run;
	}

	///Método de ejecución particular del bloque derivado
	void StepBlockNoError(void)
	{
		T tmp = *inputs.at(0) - *inputs.at(1);
		output = tmp;
	}

protected:
	//Atributos

	//Metodos

private:
	//Atributos

	//Metodos
};

#endif /* MODELS_PID_H_ */
