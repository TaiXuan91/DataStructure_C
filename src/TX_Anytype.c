#include <stdio.h>
#include <string.h>

#include "TX_Anytype.h"

void TX_Anytype_ShowElement(TX_Anytype_AnytypeElement e, char* buffer){
    switch (e.type)
    {
    case TX_BOOL:
        if (e.data.bool_value){
            strcpy(buffer, "true");
        }
        else
        {
            strcpy(buffer, "false");
        }
        break;
    case TX_CHAR:
        sprintf(buffer, "%c", e.data.char_value);
        break;
    case TX_FLOAT:
        sprintf(buffer, "%f", e.data.float_value);
        break;
    case TX_INTEGER:
        sprintf(buffer, "%d", e.data.integer_value);
        break;
    case TX_VOID_POINTER:
        // sprintf(buffer, "%x", e.data.void_pointer_value);
        sprintf(buffer, "(Pointer)");
        break;
    case TX_NONE:
        strcpy(buffer, "(None)");
        break;
    default:
        strcpy(buffer, "(ERROR!!!)");
        break;
    }
}