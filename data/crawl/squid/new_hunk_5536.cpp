void
storeAufsDirDump(StoreEntry * entry, SwapDir * s)
{
    commonUfsDirDump (entry, s);
    dump_cachedir_options(entry, options, s);
}

/*
 * storeAufsDirParse *
 * Called when a *new* fs is being setup.
