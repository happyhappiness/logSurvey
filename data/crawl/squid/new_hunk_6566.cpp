	}
    }
    fprintf(stderr, "%s:%d: scanned (size: %d bytes)\n", 
	fname, count, (int)(count*sizeof(CacheEntry)));
    return count;
}

