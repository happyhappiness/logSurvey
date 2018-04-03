    return s == NULL;
}

void
allocate_new_swapdir(cacheSwap * swap)
{
    if (swap->swapDirs == NULL) {
	swap->n_allocated = 4;
	swap->swapDirs = xcalloc(swap->n_allocated, sizeof(SwapDir));
    }
    if (swap->n_allocated == swap->n_configured) {
	SwapDir *tmp;
	swap->n_allocated <<= 1;
	tmp = xcalloc(swap->n_allocated, sizeof(SwapDir));
	xmemcpy(tmp, swap->swapDirs, swap->n_configured * sizeof(SwapDir));
	xfree(swap->swapDirs);
	swap->swapDirs = tmp;
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
    } else {
	fatalf("Unknown cache_dir type '%s'\n", type_str);
    }
}

static void
