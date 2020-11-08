#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "simulator.h"
#include "formatting.h"

//#############################################################################
char getCircuitType(void) {

        /* Function takes the circuit type from user and returns a character
         'S' for a series circuit and a 'P' for a parallel circuit*/

        char circuitType;
        border();
        printf("Select circuit type 'S' for series 'P' for parallel:\n");
        border();
        scanf("%c", &circuitType);
        return circuitType;

} // End getCircuitType
//#############################################################################

char getSourceType(void) {

        char sourceType;
        border();
        printf("What kind of source 'V' for voltage 'I' for current:\n");
        scanf("%c",&sourceType);
        getchar();
        return sourceType;
}
//#############################################################################

int getResistors(void) {
        /* Function takes the integer number of resistors that will be in the
        circuit and returns that number as an integer*/

        int resistors;
        border();
        printf("How many resistors will be in the circuit?:\n");
        scanf("%d", &resistors);
        getchar();
        return resistors;

} // End
//#############################################################################

float getVoltageLevel(void) {
        /* Function takes the float voltage level of the source that will be
        in the circuit*/

        float voltage;
        border();
        printf("What is the voltage of the source?:\n");
        scanf("%f", &voltage);
        return voltage;

} // End getVoltageLevel
//#############################################################################

float getCurrentLevel(void) {
        /* Function takes the float current level of the source that will be
        in the circuit*/

        float current;
        border();
        printf("What is the current of the source?:\n");
        scanf("%f", &current);
        return current;

} // End getCurrentLevel
//#############################################################################

void setSeriesCircuit(int resistors) {

         /* Function takes the number of resistors, the voltage of a V source
         and the current of I source then returns the calculated values of
         circuit current, circuit power, individual voltage drops of the
         resistors, and the individual power consumption of the resistors*/

         char sourceType;
         float voltage = 0.00;
         float current = 0.00;
         Resistor userResistors[resistors];
         VoltageSource userVoltageSource;
         CurrentSource userCurrentSource;
         float circuitResistance = 0.00;
         float circuitVoltage = 0.00;
         float circuitCurrent = 0.00;
         float circuitPower = 0.00;

         // Ask user for source type V for voltage I for current
         sourceType = getSourceType();

         // Set the voltage and current levels of the sources
              switch(sourceType) {

                      case 'V':
                        voltage = getVoltageLevel();
                        userVoltageSource.voltage = voltage;
                        break;

                      case 'I':
                        current = getCurrentLevel();
                        userCurrentSource.current = current;
                        break;

                       default:
                        printf("Invalid Choice\n");

              } // end switch

         // Ask the user to set the resistance of each resistor
         for(int i = 0; i < resistors; i++) {
                border();
                printf("Enter the resistance of R%d:\n", i+1);
                scanf("%f", &userResistors[i].reistance);
         } // end for

         /* Series Calculations */

         // Circuit resistance: Rcircuit = R1+R2+R3+...+Rn
         for(int j = 0; j < resistors; j++){
                circuitResistance += userResistors[j].reistance;
         } // end for

         // Circuit voltage calculation: Vcircuit = Isource * Rtotal

         if(sourceType == 'I') {
                circuitVoltage = (float)
                (circuitResistance)*(userCurrentSource.current);
                circuitCurrent = (float)  userCurrentSource.current;
                circuitPower = (float)
                (userCurrentSource.current)*(circuitVoltage);
         } else {
         // Circuit voltage is simply the value of the voltage source
                circuitVoltage = userVoltageSource.voltage;
         // Circuit current calculation: Icircuit = Vsource/total R
                circuitCurrent = (float)
                (userVoltageSource.voltage)/(circuitResistance);
         // Circuit power calculation: Pcircuit = Vsource * Icircuit
                circuitPower = (float)
                (userVoltageSource.voltage)*(circuitCurrent);
         } // end if else

          // Display table header
          formatTableHeader();

        // Individual voltage drops

        for(int k = 0; k < resistors; k++) {
                spacing();
                printf("Voltage across R%d is %f Volts\n", k+1,
                       (userResistors[k].reistance)*(circuitCurrent));
        } // end for

        newLine();
        border();

        // Individual power consumption
        for(int l = 0; l < resistors; l++) {
                spacing();
                printf("R%d is consuming %f Watts\n", l+1,
                pow(circuitCurrent, 2)*(userResistors[l].reistance));
        } // end for

        // Display circuit values
        newLine();
        border();
        newLine();

        // Circuit resistance
        spacing();
        printf("The circuit resistance is %f Ohms \n", circuitResistance);

        // Circuit voltage
        spacing();
        printf("The circuit voltage is %f Volts \n", circuitVoltage);

        // Circuit current
        spacing();
        printf("The circuit current is %f Amps \n", circuitCurrent);

        // Circuit power
        spacing();
        printf("The circuit is consuming %f Watts \n", circuitPower);

        newLine();

        // Display table footer
        formatTableFooter();


} // End setSeriesCircuit

//#############################################################################
void setParallelCircuit(int resistors) {

        /* Function takes the number of resistors, the voltage of a V source
         and the current of I source then returns the calculated values of
         circuit current, circuit power, individual voltage drops of the
         resistors, and the individual power consumption of the resistors*/

         char sourceType;
         float voltage = 0.00;
         float current = 0.00;
         Resistor userResistors[resistors];
         VoltageSource userVoltageSource;
         CurrentSource userCurrentSource;
         float circuitResistance = 0.00;
         float circuitVoltage = 0.00;
         float circuitCurrent = 0.00;
         float circuitPower = 0.00;

          // Ask user for source type V for voltage I for current
         sourceType = getSourceType();

         // Set the voltage and current levels of the sources
              switch(sourceType) {

                      case 'V':
                        voltage = getVoltageLevel();
                        userVoltageSource.voltage = voltage;
                        break;

                      case 'I':
                        current = getCurrentLevel();
                        userCurrentSource.current = current;
                        break;

                       default:
                        printf("Invalid Choice\n");

              } // end switch

         // Ask the user to set the resistance of each resistor
         for(int i = 0; i < resistors; i++) {
                border();
                printf("Enter the resistance of R%d:\n", i+1);
                scanf("%f", &userResistors[i].reistance);
         } // end for

         /* Parallel Calculations */

         // Circuit resistance (parallel):
         // Rtotal = (1/R1) + (1/R2) + (1/R3) + ... + (1/Rn)
         for(int j = 0; j < resistors; j++){
                circuitResistance += (1)/(userResistors[j].reistance);
         } // end for

         // final step for total resistance Rt = 1/Rsum
         circuitResistance = (1)/(circuitResistance);

         if(sourceType == 'I') {

         // Circuit current is simply the value of the I source
         circuitCurrent = userCurrentSource.current;

         // To find circuit voltage with a current source
         // Vcircuit = Isource * Rcircuit
         circuitVoltage = (float)(userCurrentSource.current)*
                circuitResistance;

         // Circuit power can be found by
         // Pcircuit = (Icircuit)^(2) * Rcircuit
         circuitPower = (float)(pow(userCurrentSource.current, 2))*
                circuitResistance;

        } else {

         // Circuit voltage is simply the value of the V source
                circuitVoltage = userVoltageSource.voltage;

         // Circuit current is Icircuit = Vcircuit/Rcircuit
                circuitCurrent = circuitVoltage/(circuitResistance);

         // Circuit power is Pcircuit = (Vcircuit)^(2) / Rcircuit
                circuitPower = (float)(pow(userVoltageSource.voltage,2)/
                                circuitResistance);

        } // end if else

          // Display table header
        formatTableHeader();

           // Individual current draw
        for(int k= 0; k < resistors; k++) {
                printf("\tR%d is drawing %f Amps\n", k+1,
                circuitVoltage/(userResistors[k].reistance));
        } // end for

        border();

          // Individual power consumption
        for(int l = 0; l < resistors; l++) {
                printf("\tR%d is consuming %f Watts\n", l+1,
                pow(circuitVoltage, 2)/(userResistors[l].reistance));
        } // end for

         // Display circuit values

        border();
        newLine();

        // Circuit resistance
        spacing();
        printf("The circuit resistance is %f Ohms \n", circuitResistance);

        // Circuit voltage
        spacing();
        printf("The circuit voltage is %f Volts \n", circuitVoltage);

        // Circuit current
        spacing();
        printf("The circuit current is %f Amps \n", circuitCurrent);

        // Circuit power
        spacing();
        printf("The circuit is consuming %f Watts \n", circuitPower);

        newLine();

          // Display table footer
          formatTableFooter();

} // end setParallelCircuit
//#############################################################################
