	}
	storeUnregister(http->old_entry, http);
	storeUnlockObject(http->old_entry);
#if DONT_USE_VM
	file_close(http->swapin_fd);
	http->swapin_fd = storeOpenSwapFileRead(entry);
	if (http->swapin_fd < 0)
	    fatal_dump("icpHandleIMSReply: storeOpenSwapFileRead() failed\n");
#endif
    }
    http->old_entry = NULL;	/* done with old_entry */
    storeClientCopy(entry,
	http->out.offset,
	http->out.offset,
	4096,
	get_free_4k_page(),
	icpSendMoreData,
	http);
}
