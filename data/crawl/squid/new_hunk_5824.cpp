    sd->max_objsize = size;
}

static void
dump_cachedir_option_maxsize(StoreEntry * e, const char *option, SwapDir * sd)
{
    if (sd->max_objsize != -1)
	storeAppendPrintf(e, " %s=%d", option, sd->max_objsize);
}

static struct cache_dir_option common_cachedir_options[] =
{
    {"read-only", parse_cachedir_option_readonly, dump_cachedir_option_readonly},
    {"max-size", parse_cachedir_option_maxsize, dump_cachedir_option_maxsize},
    {NULL, NULL}
};

