        fatal("COSS requires max-size to be set to something other than -1!\n");
}

void
CossSwapDir::dump(StoreEntry &entry)const
{
    storeAppendPrintf(&entry, " %lu", (max_size >> 10));
    dumpOptions(&entry);
}

CossSwapDir::CossSwapDir() : SwapDir ("coss"), swaplog_fd(-1), count(0), current_membuf (NULL), current_offset(0), numcollisions(0),  blksz_bits(0), io (NULL), ioModule(NULL), currentIOOptions(new ConfigOptionVector()), stripe_path(NULL)
{
    membufs.head = NULL;
    membufs.tail = NULL;
