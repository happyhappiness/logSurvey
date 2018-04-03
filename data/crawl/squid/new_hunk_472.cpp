}

void
Store::Disk::optionReadOnlyDump(StoreEntry * e) const
{
    if (flags.read_only)
        storeAppendPrintf(e, " no-store");
}

bool
Store::Disk::optionObjectSizeParse(char const *option, const char *value, int isaReconfig)
{
    int64_t *val;
    if (strcmp(option, "max-size") == 0) {
