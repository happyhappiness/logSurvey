	* will cause an assertion in storeDiskdShmGet().
	*/
       debug(3, 1) ("WARNING: cannot increase cache_dir '%s' Q1 value while Squid is running.\n", sd->path);
       diskdinfo->magic1 = old_magic1;
       return;
    }
    if (old_magic1 != diskdinfo->magic1)
	debug(3, 1) ("cache_dir '%s' new Q1 value '%d'\n",
	    sd->path, diskdinfo->magic1);
}

static void
storeDiskdDirDumpQ1(StoreEntry * e, const char *option, SwapDir * sd)
{
    diskdinfo_t *diskdinfo = (diskdinfo_t *)sd->fsdata;
    storeAppendPrintf(e, " Q1=%d", diskdinfo->magic1);
}

static void
storeDiskdDirParseQ2(SwapDir * sd, const char *name, const char *value, int reconfiguring)
{
    diskdinfo_t *diskdinfo = (diskdinfo_t *)sd->fsdata;
    int old_magic2 = diskdinfo->magic2;
    diskdinfo->magic2 = atoi(value);
    if (!reconfiguring)
       return;
    if (old_magic2 < diskdinfo->magic2) {
       /* See comments in Q1 function above */
       debug(3, 1) ("WARNING: cannot increase cache_dir '%s' Q2 value while Squid is running.\n", sd->path);
       diskdinfo->magic2 = old_magic2;
       return;
    }
    if (old_magic2 != diskdinfo->magic2)
	debug(3, 1) ("cache_dir '%s' new Q2 value '%d'\n",
	    sd->path, diskdinfo->magic2);
}

static void
storeDiskdDirDumpQ2(StoreEntry * e, const char *option, SwapDir * sd)
{
    diskdinfo_t *diskdinfo = (diskdinfo_t *)sd->fsdata;
    storeAppendPrintf(e, " Q2=%d", diskdinfo->magic2);
}

struct cache_dir_option options[] =
