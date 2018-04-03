}

void
storeCossDirDump(StoreEntry * entry, const char *name, SwapDir * s)
{
    storeAppendPrintf(entry, "%s %s %s %d\n",
	name,
	s->type,
	s->path,
	s->max_size >> 20);
}

#if OLD_UNUSED_CODE
