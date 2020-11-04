#include "simulator.h"
#include <stdio.h>
#include <stdlib.h>

int main() {

    char circuitType;
    int numberOfResistors = 0;

    // Get the type of circuit
    circuitType = getCircuitType();

    // Get the number of resistors
    numberOfResistors = getResistors();

    // Build the circuit
    switch(circuitType) {

        case 'S':
                setSeriesCircuit(numberOfResistors);
                break;


        case 'P':

                setParallelCircuit(numberOfResistors);
                break;

        default:

                printf("Invalid choice!");
    }
    return EXIT_SUCCESS;
}
