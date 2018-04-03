	}
	storeUnregister(http->old_entry, http);
	storeUnlockObject(http->old_entry);
    }
    http->old_entry = NULL;	/* done with old_entry */
    storeRegister(http->entry, icpHandleStore, http, http->out.offset);
}

int
