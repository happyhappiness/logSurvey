{
    int dirn = fn >> SWAP_DIR_SHIFT;
    int filn = fn & SWAP_FILE_MASK;
    return file_map_bit_test(SwapDirs[dirn].map, filn);
}

void
storeDirMapBitSet(int fn)
{
    int dirn = fn >> SWAP_DIR_SHIFT;
    int filn = fn & SWAP_FILE_MASK;
    file_map_bit_set(SwapDirs[dirn].map, filn);
    SwapDirs[dirn].suggest++;
}

void
storeDirMapBitReset(int fn)
{
    int dirn = fn >> SWAP_DIR_SHIFT;
    int filn = fn & SWAP_FILE_MASK;
    file_map_bit_reset(SwapDirs[dirn].map, filn);
    if (fn < SwapDirs[dirn].suggest)
	SwapDirs[dirn].suggest = fn;
}

int
storeDirMapAllocate(void)
{
    int dirn = storeMostFreeSwapDir();
    SwapDir *SD = &SwapDirs[dirn];
    int filn = file_map_allocate(SD->map, SD->suggest);
    return (dirn << SWAP_DIR_SHIFT) | (filn & SWAP_FILE_MASK);
}

char *
storeSwapDir(int dirn)
{
    if (dirn < 0 || dirn >= ncache_dirs)
	fatal_dump("storeSwapDir: bad index");
    return SwapDirs[dirn].path;
}

int
