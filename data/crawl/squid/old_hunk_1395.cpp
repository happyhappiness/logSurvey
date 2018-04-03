void
Auth::Config::dump(StoreEntry *entry, const char *name, Auth::Config *scheme)
{
    if (keyExtrasLine.size() > 0)
        storeAppendPrintf(entry, "%s %s key_extras \"%s\"\n", name, scheme->type(), keyExtrasLine.termedBuf());
}
