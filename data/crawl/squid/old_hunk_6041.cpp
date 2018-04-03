    }
}

static void
parse_cachedir(cacheSwap * swap)
{
    char *type_str;
    if ((type_str = strtok(NULL, w_space)) == NULL)
	self_destruct();
    if (0 == strcasecmp(type_str, "ufs")) {
	storeUfsDirParse(swap);
#if USE_ASYNC_IO
    } else if (0 == strcasecmp(type_str, "asyncufs")) {
	storeAufsDirParse(swap);
#endif
#if USE_DISKD
    } else if (0 == strcasecmp(type_str, "diskd")) {
	storeDiskdDirParse(swap);
#endif
    } else {
	fatalf("Unknown cache_dir type '%s'\n", type_str);
    }
}

static void
