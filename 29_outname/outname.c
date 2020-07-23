#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "outname.h"

char *computeOutputFileName(const char *inputName)
{
    //we need to append ".counts" to the end of the input name to get the output name
    //therefore we add 8 to the length of the input name, 7 letters for ".counts" and the last for the null terminator
    char *outputName = malloc((strlen(inputName) + 8) * sizeof(*outputName));
    strcpy(outputName, inputName);
    strcat(outputName, ".counts");
    return outputName;
}