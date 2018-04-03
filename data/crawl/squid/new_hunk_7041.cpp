	if (sm_stats.n_pages_in_use + pages_needed < store_pages_low)
	    break;
    }
    debug(20, 0) ("storeGetMemSpace stats:\n");
    debug(20, 0) ("  %6d HOT objects\n", meta_data.hot_vm);
    debug(20, 0) ("  %6d were purged\n", n_purged);
    debug(20, 0) ("  %6d were released\n", n_released);
}

static int
compareLastRef(StoreEntry ** e1, StoreEntry ** e2)
{
