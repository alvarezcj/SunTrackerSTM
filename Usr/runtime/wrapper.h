
#ifndef RUNTIME_WRAPPER_H_
#define RUNTIME_WRAPPER_H_


#ifdef __cplusplus
extern "C"
{
#endif

//Declaración de puntos de entrada C->C++

///Punto de entrada al constructor
void* tasksCreate(void);

///Punto de entrada al destructor
void taskDelete(void* obj);

///Punto de entrada a la tarea main
void StepMainTask(void* obj);

#ifdef __cplusplus
}
#endif

#endif /* RUNTIME_WRAPPER_H_ */
