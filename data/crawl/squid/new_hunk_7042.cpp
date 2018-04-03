	}
	storeUnregister(http->old_entry, http);
	storeUnlockObject(http->old_entry);
    }
    http->old_entry = NULL;	/* done with old_entry */
    /* use clientCacheHit() here as the callback because we might
       be swapping in from disk, and the file might not really be
       there */
    storeClientCopy(entry,
	http->out.offset,
	http->out.offset,
	4096,
	get_free_4k_page(),
	clientCacheHit,
	http);
}
