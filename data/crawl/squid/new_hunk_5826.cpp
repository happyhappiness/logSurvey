}

void
storeCossDirDump(StoreEntry * entry, SwapDir * s)
{
    storeAppendPrintf(entry, " %d",
	s->max_size >> 20);
    dump_cachedir_options(entry, NULL, sd);
}

#if OLD_UNUSED_CODE
