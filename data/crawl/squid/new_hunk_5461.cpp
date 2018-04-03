 *
 * This routine is called when the given swapdir needs reconfiguring 
 */
void
AUFSSwapDir::reconfigure(int anIndex, char *aPath)
{
    UFSSwapDir::reconfigure (anIndex, aPath);

    parse_cachedir_options(this, options, 0);
}

void
AUFSSwapDir::dump(StoreEntry & entry) const
{
    UFSSwapDir::dump(entry);
    dump_cachedir_options(&entry, options, this);
}

/*
 * storeAufsDirParse *
 * Called when a *new* fs is being setup.
 */
void
AUFSSwapDir::parse(int anIndex, char *aPath)
{
    UFSSwapDir::parse(anIndex, aPath);

    parse_cachedir_options(this, options, 0);
}

/*
