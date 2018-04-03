}

void
store_client::dumpStats(StoreEntry * output, int clientNumber) const
{
    if (_callback.pending())
        return;

    storeAppendPrintf(output, "\tClient #%d, %p\n", clientNumber, _callback.callback_data);

    storeAppendPrintf(output, "\t\tcopy_offset: %lu\n",
                      (unsigned long) copyInto.offset);

    storeAppendPrintf(output, "\t\tcopy_size: %d\n",
                      (int) copyInto.length);

    storeAppendPrintf(output, "\t\tflags:");

    if (flags.disk_io_pending)
        storeAppendPrintf(output, " disk_io_pending");

    if (flags.store_copying)
        storeAppendPrintf(output, " store_copying");

    if (flags.copy_event_pending)
        storeAppendPrintf(output, " copy_event_pending");

    storeAppendPrintf(output, "\n");
}

bool