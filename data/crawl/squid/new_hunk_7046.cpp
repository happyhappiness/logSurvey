    assert(e->mem_status == NOT_IN_MEMORY);
    if (!BIT_TEST(e->flag, ENTRY_VALIDATED)) {
	/* Invoke a store abort that should free the memory object */
	(ctrlp->callback) (-1, ctrlp->callback_data);
	xfree(ctrlp);
	return;
    }
    ctrlp->path = xstrdup(storeSwapFullPath(e->swap_file_number, NULL));
    file_open(ctrlp->path, O_RDONLY, storeSwapInFileOpened, ctrlp);
}

static void
storeSwapInFileOpened(void *data, int fd)
{
    swapin_ctrl_t *ctrlp = (swapin_ctrl_t *) data;
    StoreEntry *e = ctrlp->e;
    assert(e->mem_obj != NULL);
    assert(e->mem_status == NOT_IN_MEMORY);
    assert(e->swap_status == SWAPOUT_DONE);
    if (fd < 0) {
	debug(20, 0) ("storeSwapInStartComplete: Failed for '%s'\n", e->url);
	/* Invoke a store abort that should free the memory object */
	(ctrlp->callback) (-1, ctrlp->callback_data);
	xfree(ctrlp->path);
	xfree(ctrlp);
	return;
    }
    debug(20, 5) ("storeSwapInStart: initialized swap file '%s' for '%s'\n",
	ctrlp->path, e->url);
    (ctrlp->callback) (fd, ctrlp->callback_data);
    xfree(ctrlp->path);
    xfree(ctrlp);
}

/* recreate meta data from disk image in swap directory */
/* Add one swap file at a time from disk storage */
static void
