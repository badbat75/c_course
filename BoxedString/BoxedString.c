#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "BoxedString_plot.h"
#include "BoxedString.h"

int main(int argc, char **argv) {
    char inputstr[INPUT_MAX + 1]; 
    char hline[INPUT_MAX + 1] = "o";
    char vline[INPUT_MAX + 1] = "o";
    if ( argc == 1)
    {
       printf ("\nInsert your string here: ");
        #ifdef _MSC_VER
            scanf_s ("%" INPUT_MAX_S "[^\n]", &inputstr, INPUT_MAX + 1);
        #else
            scanf ("%" INPUT_MAX_S "[^\n]", inputstr);
        #endif
    }
    for (int i = 0; i < argc; ++i)
    {
        //printf("%s ", argv[i]);
        switch (i) {
        case 1:
            #ifdef _MSC_VER
                strcat_s (inputstr, sizeof(inputstr) -1, argv[1]);
            #else
                strncpy (inputstr, argv[1], sizeof(inputstr) -1);
            #endif
            break;
        case 2:
            #ifdef _MSC_VER
                strcat_s (hline, sizeof(hline) -1, argv[2]);
            #else
                strncpy (hline, argv[2], sizeof(hline) - 1);
            #endif
            break;
        case 3:
            #ifdef _MSC_VER
                strcat_s (vline, sizeof(vline) -1, argv[3]);
            #else
                strncpy (vline, argv[3], sizeof(vline) -1);
            #endif
            break;
        }  
    }
    printf("\n");

    plotString (inputstr, hline, vline);

    return 0;
}