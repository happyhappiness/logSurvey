	}
    }
    fprintf(stderr, "%s:%d: scanned (size: %d bytes)\n", 
	fname, count, count*sizeof(CacheEntry));
    return count;
}

