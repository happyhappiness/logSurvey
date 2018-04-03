char *
storeSwapDir(int dirn)
{
    if (dirn < 0 || dirn >= Config.cacheSwap.n_configured)
	fatal_dump("storeSwapDir: bad index");
    return Config.cacheSwap.swapDirs[dirn].path;
}

