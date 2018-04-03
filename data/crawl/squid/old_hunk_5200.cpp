
    for (i = 0; i < swap.n_configured; i++) {
        s = swap.swapDirs[i];
        storeAppendPrintf(entry, "%s %s %s", name, s->type, s->path);
        s->dump(*entry);
        dump_cachedir_options(entry, common_cachedir_options, s);
        storeAppendPrintf(entry, "\n");
    }
}

static int
check_null_cachedir(_SquidConfig::_cacheSwap swap)
{
