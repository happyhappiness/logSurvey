 *  
 */

/*
 * To-Do: uses memory pools for .buf recycling @?@
 */

/*
    Rationale:
    ----------

    Here is how one would comm_write an object without MemBuffer:

    {
	-- allocate:
	buf = malloc(big_enough);

        -- "pack":
	snprintf object(s) piece-by-piece constantly checking for overflows
	    and maintaining (buf+offset);
	...

	-- write
	comm_write(buf, free, ...);
    }

    The whole "packing" idea is quite messy: We are given a buffer of fixed
    size and we have to check all the time that we still fit. Sounds logical.
    However, what happens if we have more data? If we are lucky to be careful
    to stop before we overrun any buffers, we still may have garbage (e.g.
    half of ETag) in the buffer.

    MemBuffer:
    ----------

    MemBuffer is a memory-resident buffer with printf()-like interface. It
    hides all offest handling and overflow checking. Moreover, it has a
    build-in control that no partial data has been written.

    MemBuffer is designed to handle relatively small data. It starts with a
    small buffer of configurable size to avoid allocating huge buffers all the
    time.  MemBuffer doubles the buffer when needed. It assert()s that it will
    not grow larger than a configurable limit. MemBuffer has virtually no
    overhead (and can even reduce memory consumption) compared to old
    "packing" approach.

    MemBuffer eliminates both "packing" mess and truncated data:

    {
	-- setup
	MemBuf buf;

	-- required init with optional size tuning (see #defines for defaults)
        memBufInit(&buf, initial-size, absolute-maximum);

	-- "pack" (no need to handle offsets or check for overflows)
	memBufPrintf(&buf, ...);
	...

	-- write
	comm_write(buf.buf, memBufFreeFunc(&buf), ...);

	-- *iff* you did not give the buffer away, free it yourself
	-- memBufFree(&buf);
    }
*/


#include "squid.h"

/* local constants */

/* default values for buffer sizes, used by memBufDefInit */
#define MEM_BUF_INIT_SIZE   (2*1024)
#define MEM_BUF_MAX_SIZE   (32*1024)


/* local routines */
static void memBufGrow(MemBuf *mb, mb_size_t min_cap);


/* init with defaults */
void
memBufDefInit(MemBuf *mb)
{
    memBufInit(mb, MEM_BUF_INIT_SIZE, MEM_BUF_MAX_SIZE);
}


/* init with specific sizes */
void
memBufInit(MemBuf *mb, mb_size_t szInit, mb_size_t szMax)
{
