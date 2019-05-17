#include "TX_Anytype.h"

TX_Anytype_AnytypeElement TX_Anytype_NoneElement(){
    TX_Anytype_AnytypeElement e;
    e.data.bool_value = false;
    e.type = TX_NONE;
    return e;
}