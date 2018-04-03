static void
xmalloc_count(void *p, int sign)
{
    int statMemoryAccounted();
    static size_t last_total=0,last_accounted=0,last_mallinfo=0;
    struct mallinfo mp=mallinfo();
    size_t accounted=statMemoryAccounted();
    size_t mi = mp.uordblks + mp.usmblks + mp.hblkhd;
    size_t sz;
    static size_t total = 0;
    sz = mallocblksize(p) * sign;
    total += sz;
    fprintf(stderr, "xmalloc_count=%7d/%9d  accounted=%7d/%9d  mallinfo=%7d%9d\n",
	(int) total - last_total, (int) total,
	(int) accounted - last_accounted, (int) accounted,
	(int) mi - last_mallinfo, (int) mi);
    last_total=total;
    last_accounted=accounted;
    last_mallinfo=mi;
}

#endif /* XMALLOC_COUNT */
