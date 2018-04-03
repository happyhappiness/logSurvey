    refcount = from.refcount;
    flags = from.flags;
}


/* MapStats */

Rock::MapStats::MapStats()
{
    memset(this, 0, sizeof(*this));
}
 
void
Rock::MapStats::dump(StoreEntry &e) const
{
    storeAppendPrintf(&e, "Available slots: %9d\n", capacity);

    if (!capacity)
        return;

    storeAppendPrintf(&e, "Readable slots:  %9d %6.2f%%\n",
        readable, (100.0 * readable / capacity));
    storeAppendPrintf(&e, "Filling slots:   %9d %6.2f%%\n",
        writeable, (100.0 * writeable / capacity));
    storeAppendPrintf(&e, "Empty slots:     %9d %6.2f%%\n",
        empty, (100.0 * empty / capacity));

    if (readers || writers) {
        const int locks = readers + writers;
        storeAppendPrintf(&e, "Readers:         %9d %6.2f%%\n",
            readers, (100.0 * readers / locks));
        storeAppendPrintf(&e, "Writers:         %9d %6.2f%%\n",
            writers, (100.0 * writers / locks));
    }

    if (readable + writeable) {
        storeAppendPrintf(&e, "Marked slots:    %9d %6.2f%%\n",
            marked, (100.0 * marked / (readable + writeable)));
    }
}
