 *  
 */

/* see MemBuf.h for documentation */

/*
 * To-Do: uses memory pools for .buf recycling @?@
 */


#include "squid.h"

/* local routines */
static void memBufGrow(MemBuf *mb, mb_size_t min_cap);



void
memBufInit(MemBuf *mb, mb_size_t szInit, mb_size_t szMax)
{
