    if (size <= 0)
	fatal("storeCossDirParse: invalid size value");

    if (size == (size_t)max_size)
	debug(3, 1) ("Cache COSS dir '%s' size remains unchanged at %d KB\n", path, size);
    else {
	debug(3, 1) ("Cache COSS dir '%s' size changed to %d KB\n", path, size);
	max_size = size;
    }
    parse_cachedir_options(this, NULL, 1);
    /* Enforce maxobjsize being set to something */
    if (max_objsize == -1)
	fatal("COSS requires max-size to be set to something other than -1!\n");
}

void
CossSwapDir::dump(StoreEntry &entry)const
{
    storeAppendPrintf(&entry, " %d",
	max_size >> 20);
    dump_cachedir_options(&entry, NULL, this);
}

#if OLD_UNUSED_CODE
