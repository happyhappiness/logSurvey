{
    if (dirn < 0 || dirn >= ncache_dirs)
	fatal_dump("storeSwapDir: bad index");
    return SwapDirs[dirn].path;
}