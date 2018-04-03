	}
	return;
    } else {
	fatal_dump("fqdncache_nbgethostbyaddr: BAD fqdncache_entry status");
    }

    /* for HIT, PENDING, DISPATCHED we've returned.  For MISS we continue */
