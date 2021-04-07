#include <stdio.h>
#include <cs50.h>
#include <float.h>

double myAbs (double a) {return (a > 0) ? a : -a;}

double myPower (double number, int exponent) {
    double toReturn = 1.0;

    for (int i = 0; i < exponent; i++){
        toReturn *= number;
    }

    return toReturn;
}

int main(void) {

    // Calcular a raíz de índice inteiro 'rootIndex' de 'myValue'.

    double lowerBound = 0.0;
    double upperBound = DBL_MAX;
    double myValue = get_double("\nValor a calcular a raíz: ");
    int exponent = get_int("\nValor de índice inteiro: ");

    int counter = 1;

    double previousNumber, currentNumber, interval;

    currentNumber = 0.0;

    do {
        previousNumber = currentNumber;
        printf("\nIteration number %d.", counter++);
        currentNumber = (lowerBound + upperBound) / 2.0;

        if (myPower(currentNumber, exponent) - myValue > 0.0) {
            upperBound = currentNumber;
        }
        else if (myPower(currentNumber, exponent) - myValue < 0.0) {
            lowerBound = currentNumber;
        }

        //  n          n
        // x  = v <=> x - v = 0

        interval = myAbs(previousNumber - currentNumber);

    } while (interval > 0.00000002);

    printf("\nRaíz de índice %d aproximada: %.8f \n\n", exponent, currentNumber);

}