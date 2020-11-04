
#ifndef SIMULATOR_H_INCLUDED
#define SIMULATOR_H_INCLUDED

/* Structs */

typedef struct Resitor {
        float reistance;
}Resistor;

typedef struct VoltageSource {
        float voltage;
}VoltageSource;

typedef struct CurrentSource {
        float current;
}CurrentSource;

/* Functions*/

/*Getters*/

 // Gets the type of circuit from user
char getCircuitType(void);

// Gets the # of resistors from user
int getResistors(void);

// Get source type
char getSourceType(void);

// Gets the desired voltage of the voltage source
float getVoltageLevel(void);

// Gets the desired current of the current source
float getCurrentLevel(void);

// Builds the series circuit
void setSeriesCircuit(int resistors);

// Builds the parallel circuit
void setParallelCircuit(int resistors);


#endif // SIMULATOR_H_INCLUDED
