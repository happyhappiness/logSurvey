}

void
storeDirUpdateSwapSize(int fn, size_t size)
{
    int dirn = (fn >> SWAP_DIR_SHIFT) % ncache_dirs;
    int k = ((size + 1023) >> 10);
    SwapDirs[dirn].cur_size += k;
    store_swap_size += k;
}
