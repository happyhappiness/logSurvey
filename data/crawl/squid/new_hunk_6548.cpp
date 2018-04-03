    fprintf(stderr, "%s: hash scan took: %f sec, %f sec/M\n",
	idx->name,
	tvSubDsec(t_start, t_end),
	(double) 1e6 * tvSubDsec(t_start, t_end) / idx->count);
}

static int
cacheIndexAddLog(CacheIndex * idx, const char *fname)
{
    FILE *file;
    int scanned_count = 0;
