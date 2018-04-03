		idx->bad_add_count++;
	    } else {
		CacheEntry *e = cacheEntryCreate(&s);
		hash_join(idx->hash, (hash_link *) e);
		idx->count++;
	    }
	} else if (s.op == SWAP_LOG_DEL) {
	    break;
	} else {
	    fprintf(stderr, "%s:%d: unknown swap log action\n", fname, count);
	    exit(-3);
	}
    }
    fprintf(stderr, "%s scanned %d entries, alloc: %d bytes\n",
	fname, count,
	(int) (count * sizeof(CacheEntry)));
    return count;
}

