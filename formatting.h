#ifndef FORMATTING_H_INCLUDED
#define FORMATTING_H_INCLUDED

//#############################################################################
/* Engineering notation constants*/
#define HUNDRED 100
#define THOUSAND 1000
#define MILLION  1000000
#define BILLION  1000000000
#define QUINTILLION 100000000000
#define TENTH 0.1
#define THOUSANDTH 0.0001
#define MILLIONTH 0.000001
#define BILLIONTH 0.000000001
#define QUINTILLIONTH 0.000000000001
//#############################################################################

// Prints header of data display table
void formatTableHeader(void);

// Prints the footer of the data display table
void formatTableFooter(void);

// Displays circuit values with appropriate figures
void formatValue(float value);

// Prints space
void spacing(void);

// Prints new line
void newLine(void);

// Prints a border pattern for table
void border(void);

#endif // FORMATTING_H_INCLUDED
