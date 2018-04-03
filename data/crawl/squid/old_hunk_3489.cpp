#if !(HAVE_MSTATS && HAVE_GNUMALLOC_H) && HAVE_MALLINFO && HAVE_STRUCT_MALLINFO

    storeAppendPrintf(sentry, "\tTotal accounted:       %6d KB %3d%%\n",
                      statMemoryAccounted() >> 10, percent(statMemoryAccounted(), t));

#else

