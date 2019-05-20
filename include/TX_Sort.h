#include <stddef.h>
#include <stdbool.h>

#include "TX_Anytype.h"
#include "TX_List.h"

#if !defined(TX_SORT)
#define TX_SORT

// Select different comparison functions by list type.
// if list type is TX_NONE, it can't be sorted.
typedef bool (*TX_Sort_Comparator)(TX_Anytype_AnytypeElement e1, TX_Anytype_AnytypeElement e2);

// Get comparator of type
TX_Sort_Comparator TX_Sort_GetComparator(TX_Anytype_Typenumber t);

// Select sort





#endif // TX_SORT
