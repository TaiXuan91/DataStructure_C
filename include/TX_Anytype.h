#include <stdbool.h>

#ifndef TX_ANYTYPE
#define TX_ANYTYPE

typedef enum TX_Anytype_Typenumber{
    /*
    Types of supported datas.
    */
    TX_BOOL,
    TX_INTEGER,
    TX_FLOAT,
    TX_CHAR,
    TX_VOID_POINTER,
    TX_NONE,
}TX_Anytype_Typenumber;

typedef union TX_Anytype_Metadata
{
    /*
    On type that can't be less than any type.
    */
    bool bool_value;
    int integer_value;
    float float_value; //
    char char_value;
    void *void_pointer_value;
}TX_Anytype_Metadata;


typedef struct TX_Anytype_AnytypeElement{
    /*
    An anytype data unit.
    */
    TX_Anytype_Metadata data;
    TX_Anytype_Typenumber type;
}TX_Anytype_AnytypeElement;

// be used to show anytype element
void TX_Anytype_ShowElement(TX_Anytype_AnytypeElement e, char* buffer);


#endif