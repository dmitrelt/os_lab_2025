#include "revert_string.h"
#include <string.h>

void RevertString(char *str)
{
    int length = strlen(str);
    char temp;
    int i;
    
    for (i = 0; i < length / 2; i++)
    {
        temp = str[i];
        str[i] = str[length - 1 - i];
        str[length - 1 - i] = temp;
    }
}