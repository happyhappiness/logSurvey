    dumpOptions(&entry);
}

#if OLD_UNUSED_CODE
SwapDir *
storeCossDirPick(void)
{
    int i, choosenext = 0;
    SwapDir *SD;

    if (n_coss_dirs == 0)
        return NULL;

    for (i = 0; i < Config.cacheSwap.n_configured; i++) {
        SD = &Config.cacheSwap.swapDirs[i];

        if (SD->type == SWAPDIR_COSS) {
            if ((last_coss_pick_index == -1) || (n_coss_dirs == 1)) {
                last_coss_pick_index = i;
                return SD;
            } else if (choosenext) {
                last_coss_pick_index = i;
                return SD;
            } else if (last_coss_pick_index == i) {
                choosenext = 1;
            }
        }
    }

    for (i = 0; i < Config.cacheSwap.n_configured; i++) {
        SD = &Config.cacheSwap.swapDirs[i];

        if (SD->type == SWAPDIR_COSS) {
            if ((last_coss_pick_index == -1) || (n_coss_dirs == 1)) {
                last_coss_pick_index = i;
                return SD;
            } else if (choosenext) {
                last_coss_pick_index = i;
                return SD;
            } else if (last_coss_pick_index == i) {
                choosenext = 1;
            }
        }
    }

    return NULL;
}

#endif
CossSwapDir::CossSwapDir() : SwapDir ("coss"), fd (-1), swaplog_fd(-1), count(0), current_membuf (NULL), current_offset(0), numcollisions(0)
{
    membufs.head = NULL;
    membufs.tail = NULL;
    cossindex.head = NULL;
    cossindex.tail = NULL;
}

