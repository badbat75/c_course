#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "BoxedString_plot.h"

extern char* repeatPattern (const int charqty, const char linedraw[])
{
    const size_t linedrawLen = strlen (linedraw);
    int count = (int)(charqty / (int)linedrawLen);
    int totalChar = count * (int)linedrawLen;
    if ( totalChar < charqty )
    {
        count += 1;
    }
    size_t strBufferSize = count * linedrawLen + 1;
    char* str = (char *)malloc(sizeof(char) * strBufferSize);
    #ifdef _MSC_VER
        strcpy_s (str, 1, "");
    #else
        strncpy (str, "", 1);
    #endif
    for (int i=0; i < count; i++ )
    {
    #ifdef _MSC_VER
            strcat_s (str, strBufferSize, linedraw);
    #else
            strncat (str, linedraw, linedrawLen);
    #endif
    }
    return str;
}

extern void plotString (const char inputstr[], const char hline[], const char vline[])
{
    int leftSpaces = 1;
    int rightSpaces = 1;
    int boxLength = (int)strlen(inputstr) + (int)strlen(vline) * 2 + 2;
    char* lineString = repeatPattern (boxLength, hline);
    if ( (int)strlen(lineString) > boxLength )
    {
        int addSpaces = (int)strlen(lineString) - boxLength;
        leftSpaces += (int)(addSpaces / 2);
        rightSpaces += addSpaces - (int)(addSpaces / 2);
    }

    printf ("\n%s\n", lineString);
    printf ("%s%s%s%s%s\n", vline, repeatPattern (leftSpaces, " "), inputstr, repeatPattern (rightSpaces, " "), vline);
    printf ("%s\n\n", lineString);
    free (lineString);
}