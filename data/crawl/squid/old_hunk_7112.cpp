static void
dumpMallocStats()
{
#if HAVE_MALLINFO
    struct mallinfo mp;
    int t;
    if (!do_mallinfo)
