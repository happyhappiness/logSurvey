    if (size <= 0)
	fatal("storeCossDirParse: invalid size value");

    if (size == (size_t)sd->max_size)
	debug(3, 1) ("Cache COSS dir '%s' size remains unchanged at %d KB\n", path, size);
    else {
	debug(3, 1) ("Cache COSS dir '%s' size changed to %d KB\n", path, size);
	sd->max_size = size;
    }
    parse_cachedir_options(sd, NULL, 1);
    /* Enforce maxobjsize being set to something */
    if (sd->max_objsize == -1)
	fatal("COSS requires max-size to be set to something other than -1!\n");
}

void
storeCossDirDump(StoreEntry * entry, SwapDir * s)
{
    storeAppendPrintf(entry, " %d",
	s->max_size >> 20);
    dump_cachedir_options(entry, NULL, s);
}

#if OLD_UNUSED_CODE
