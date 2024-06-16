#include <stdio.h>
#include <stdlib.h>
#include "format_longnum.h"

char testin[] = "11188719610782480504630258070757734324011354208865721592720336801";

int main()
{
printf("%s\n%s\n",testin,format_longnum(testin));
return(EXIT_SUCCESS);
}
