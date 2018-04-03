	    exit(-3);
	}
    }
    fprintf(stderr, "%s:%d: scanned (size: %d bytes)\n",
	fname, count, (int) (count * sizeof(CacheEntry)));
    return count;
}

static void
cacheIndexCmpReport(CacheIndex * idx, int shared_count)
{
    assert(idx && shared_count <= idx->count);

