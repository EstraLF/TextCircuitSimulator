#include <stdlib.h>
#include <stdio.h>
#include "formatting.h"



void formatTableHeader(void) {

        /* Function that prints the header of the data display table*/

        char spacing[18] = "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t";
        char headerBorder[80] =
        "/==================================================================/";

        printf("%s\n", headerBorder);
        printf("%sCircuit Simulation Data\n\n", spacing);
        printf("%s\n", headerBorder);

} // end formatTableHeader
//#############################################################################
void formatTableFooter(void) {

        /* Function that prints the footer of the data display table*/
        char spacing[18] = "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t";
        char footerBorder[80] =
        "/==================================================================/";

        printf("%s\n", footerBorder);
        printf("%s\n", footerBorder);

} // end formatTableFooter
//#############################################################################
void spacing(void) {

        /* Prints appropriate space */
        char space[18] = "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t";

        printf("%s",space);
}

//#############################################################################
void formatValue(float value) {

        /* Formats the values of the circuit using appropriate engineering
        notation */

        if((value >= THOUSANDTH) || (value <= TENTH)) {
                value *= THOUSAND;
        }
        else if((value >= BILLIONTH) || (value <= MILLIONTH)) {
                value *= MILLION;
        }
        else if((value >= QUINTILLIONTH) || (value <= BILLIONTH )) {
                value *= BILLION;
        }
        else if((value <= THOUSAND) || (value >= HUNDRED)) {
                value /= THOUSAND;
        }
        else if((value <= MILLION) || (value >= THOUSAND)) {
                value /= MILLION;
        }
        else if((value <= BILLION) || (value >= MILLION)) {
                value /= BILLION;
        }
        else if((value <= QUINTILLION) || (value >= BILLION)) {
                value /= QUINTILLION;
        }
}
//#############################################################################
void border(void) {

        char borderDesign[80] =
        "====================================================================";

        printf("%s\n",borderDesign);
}
//#############################################################################
void newLine(void) {

        printf("\n");

}
//#############################################################################
