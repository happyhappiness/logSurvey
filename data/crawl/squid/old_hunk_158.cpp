        storeDirSwapLog(this, SWAP_LOG_ADD);
}

StoreEntry *
storeCreatePureEntry(const char *url, const char *log_url, const RequestFlags &flags, const HttpRequestMethod& method)
{
