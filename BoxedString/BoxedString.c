#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "BoxedString.h"

int main() {
    char hline[] = H_LINE;
    char vline[] = V_LINE;
    char inputstr[INPUT_MAX + 1];

    printf ("\nInsert your string here: ");
    #ifdef _MSC_VER
        scanf_s ("%" INPUT_MAX_S "[^\n]", inputstr, INPUT_MAX + 1);
    #else
        scanf ("%" INPUT_MAX_S "[^\n]", inputstr);
    #endif
    plotString (inputstr, hline, vline);

    return 0;
}