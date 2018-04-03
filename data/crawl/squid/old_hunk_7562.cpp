    storeAppendPrintf(sentry, close_bracket);
}

int memoryAccounted()
{
    return (int)
	meta_data.store_entries * sizeof(StoreEntry) +
