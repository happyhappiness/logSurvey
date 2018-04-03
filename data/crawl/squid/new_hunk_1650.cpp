    mb->Printf("\t%s\n", storeEntryFlags(e));
    mb->Printf("\t%s\n", describeTimestamps(e));
    mb->Printf("\t%d locks, %d clients, %d refs\n",
               (int) e->locks(),
               storePendingNClients(e),
               (int) e->refcount);
    mb->Printf("\tSwap Dir %d, File %#08X\n",
