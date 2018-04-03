    }
}

void
dump_cachedir_options(StoreEntry * entry, struct cache_dir_option *options, SwapDir * sd)
{
    struct cache_dir_option *option;
    if (!options)
	return;
    for (option = options; option->name; option++)
	option->dump(entry, option->name, sd);
}

static void
dump_cachedir(StoreEntry * entry, const char *name, cacheSwap swap)
{
    SwapDir *s;
    int i;
    for (i = 0; i < swap.n_configured; i++) {
	s = swap.swapDirs + i;
	storeAppendPrintf(entry, "%s %s %s", name, s->type, s->path);
	if (s->dump)
	    s->dump(entry, s);
	dump_cachedir_options(entry, common_cachedir_options, s);
	storeAppendPrintf(entry, "\n");
    }
}

