{
    LOCAL_ARRAY(char, logmsg, MAX_URL << 1);
    int dirn;
    assert(e->swap_file_number >= 0);
    dirn = e->swap_file_number >> SWAP_DIR_SHIFT;
    assert(dirn < Config.cacheSwap.n_configured);
    assert(!BIT_TEST(e->flag, KEY_PRIVATE));