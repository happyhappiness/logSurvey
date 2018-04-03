 *
 * This routine is called when the given swapdir needs reconfiguring 
 */
void
DiskdSwapDir::reconfigure(int anIndex, char *aPath)
{
    UFSSwapDir::reconfigure (anIndex, aPath);

    parse_cachedir_options(this, options, 1);
}

void
DiskdSwapDir::dump(StoreEntry & entry)const
{
    UFSSwapDir::dump (entry);
    dump_cachedir_options(&entry, options, this);
}

/*
 * storeDiskdDirParse
 *
 * Called when a *new* fs is being setup.
 */
void
DiskdSwapDir::parse(int anIndex, char *aPath)
{
    UFSSwapDir::parse(anIndex, aPath);

    parse_cachedir_options(this, options, 0);
}

/*
