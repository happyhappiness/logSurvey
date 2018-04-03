	fprintf(stderr, "cannot open %s: %s\n", fname, strerror(errno));
	return 0;
    }

    scanned_count = cacheIndexScan(idx, fname, file);

    fclose(file);
    return scanned_count;
}

static void
cacheIndexInitReport(CacheIndex *idx)
{
    assert(idx);
    fprintf(stderr, "%s: bad swap_add:  %d\n",
	idx->name, idx->bad_add_count);
    fprintf(stderr, "%s: bad swap_del:  %d\n", 
	idx->name, idx->bad_del_count);
    fprintf(stderr, "%s: scanned lines: %d\n", 
	idx->name, idx->scanned_count);
}

static int
cacheIndexScan(CacheIndex *idx, const char *fname, FILE *file)
{
    int count = 0;
    storeSwapLogData s;
