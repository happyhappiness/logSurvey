	* will cause an assertion in storeDiskdShmGet().
	*/
       debug(3, 1) ("WARNING: cannot increase cache_dir '%s' Q1 value while Squid is running.\n", sd->path);
       IO->magic1 = old_magic1;
       return;
    }
    if (old_magic1 != IO->magic1)
	debug(3, 1) ("cache_dir '%s' new Q1 value '%d'\n",
	    sd->path, IO->magic1);
}

static void
storeDiskdDirDumpQ1(StoreEntry * e, const char *option, SwapDir const * sd)
{
    DiskdIO *IO = dynamic_cast<DiskdIO *>(((DiskdSwapDir *)sd)->IO);
    storeAppendPrintf(e, " Q1=%d", IO->magic1);
}

static void
storeDiskdDirParseQ2(SwapDir * sd, const char *name, const char *value, int reconfiguring)
{
    DiskdIO *IO = dynamic_cast<DiskdIO *>(((DiskdSwapDir *)sd)->IO);
    assert (IO);
    int old_magic2 = IO->magic2;
    IO->magic2 = atoi(value);
    if (!reconfiguring)
       return;
    if (old_magic2 < IO->magic2) {
       /* See comments in Q1 function above */
       debug(3, 1) ("WARNING: cannot increase cache_dir '%s' Q2 value while Squid is running.\n", sd->path);
       IO->magic2 = old_magic2;
       return;
    }
    if (old_magic2 != IO->magic2)
	debug(3, 1) ("cache_dir '%s' new Q2 value '%d'\n",
	    sd->path, IO->magic2);
}

static void
storeDiskdDirDumpQ2(StoreEntry * e, const char *option, SwapDir const * sd)
{
    DiskdIO *IO = dynamic_cast<DiskdIO *>(((DiskdSwapDir *)sd)->IO);
    storeAppendPrintf(e, " Q2=%d", IO->magic2);
}

struct cache_dir_option options[] =
