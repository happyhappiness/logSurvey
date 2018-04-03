#include "cache.h"
#include "quote.h"

/* Get a trace file descriptor from GIT_TRACE env variable. */
static int get_trace_fd(int *need_close)
{
