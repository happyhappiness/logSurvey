    return 0;
}
static void
xmalloc_trace(void *p, int sign)
{
    int statMemoryAccounted();
    static size_t last_total = 0, last_accounted = 0, last_mallinfo = 0;
    struct mallinfo mp = mallinfo();
    size_t accounted = statMemoryAccounted();
    size_t mi = mp.uordblks + mp.usmblks + mp.hblkhd;
    size_t sz;
    static size_t total = 0;
    sz = mallocblksize(p) * sign;
    total += sz;
    xmalloc_count += sign>0;
    fprintf(stderr, "%c%8p size=%5d/%d acc=%5d/%d mallinfo=%5d/%d %s:%d %s",
	sign>0 ? '+':'-',p,
	(int) total - last_total, (int) total,
	(int) accounted - last_accounted, (int) accounted,
	(int) mi - last_mallinfo, (int) mi,
	xmalloc_file, xmalloc_line, xmalloc_func);
    if (sign<0)
	fprintf(stderr," (%d %s:%d)\n",malloc_number(p),malloc_file_name(p),malloc_line_number(p));
    else
	fprintf(stderr," %d\n",xmalloc_count);
    last_total = total;
    last_accounted = accounted;
    last_mallinfo = mi;
}

#endif /* XMALLOC_TRACE */

/*
