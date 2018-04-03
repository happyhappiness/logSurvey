    return COMM_OK;
}

void httpReplyHeaderStats(entry)
     StoreEntry *entry;
{
    storeAppendPrintf(entry, open_bracket);
    storeAppendPrintf(entry, "{HTTP Reply Headers}\n");
