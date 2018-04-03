    dumpOptions(&entry);
}


CossSwapDir::CossSwapDir() : SwapDir ("coss"), fd (-1), swaplog_fd(-1), count(0), current_membuf (NULL), current_offset(0), numcollisions(0)
{
    membufs.head = NULL;
    membufs.tail = NULL;
    cossindex.head = NULL;
    cossindex.tail = NULL;
    blksz_mask = (1 << blksz_bits) - 1;
}

bool
CossSwapDir::optionBlockSizeParse(const char *option, const char *value, int reconfiguring)
{
    int blksz = atoi(value);

    if (blksz == (1 << blksz_bits))
        /* no change */
        return true;

    if (reconfiguring) {
        debug(47, 0) ("WARNING: cannot change COSS block-size while"
                      " Squid is running\n");
        return false;
    }

    int nbits = 0;
    int check = blksz;

    while (check > 1) {
        nbits++;
        check >>= 1;
    }

    check = 1 << nbits;

    if (check != blksz)
        fatal("COSS block-size must be a power of 2\n");

    if (nbits > 13)
        fatal("COSS block-size must be 8192 or smaller\n");

    blksz_bits = nbits;

    blksz_mask = (1 << blksz_bits) - 1;

    return true;
}

void
CossSwapDir::optionBlockSizeDump(StoreEntry * e) const
{
    storeAppendPrintf(e, " block-size=%d", 1 << blksz_bits);
}

SwapDirOption *
CossSwapDir::getOptionTree() const
{
    SwapDirOption *parentResult = SwapDir::getOptionTree();

    SwapDirOptionVector *result = new SwapDirOptionVector();

    result->options.push_back(parentResult);

    result->options.push_back(
        new SwapDirOptionAdapter<CossSwapDir>(*const_cast<CossSwapDir *>(this),
                                              &CossSwapDir::optionBlockSizeParse,
                                              &CossSwapDir::optionBlockSizeDump));

    return result;
}
