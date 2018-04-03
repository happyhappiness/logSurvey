	}
    }
    fprintf(stderr, "%s scanned %d entries, alloc: %d bytes\n",
	fname, count, 
	(int)(count*sizeof(CacheEntry)));
    return count;
}
#endif

static int
cacheIndexScanCleanPrefix(CacheIndex *idx, const char *fname, FILE *file)
{
    int count = 0;
    storeSwapLogData s;
