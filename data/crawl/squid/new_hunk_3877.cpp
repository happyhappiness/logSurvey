
#include "config.h"

#if HAVE_STDIO_H
#include <stdio.h>
#endif
#if HAVE_STDLIB_H
#include <stdlib.h>
#endif

#if 0
#include "compat/assert.h"
#endif

void xassert(const char *expr, const char *file, int line)
{
