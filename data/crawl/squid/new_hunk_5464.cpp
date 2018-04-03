 * done by the upper layers.
 */
int
CossSwapDir::canStore(StoreEntry const &e)const
{
    int loadav;

    /* Check if the object is a special object, we can't cache these */
    if (EBIT_TEST(e.flags, ENTRY_SPECIAL))
	return -1;

    /* Otherwise, we're ok */
    /* Return load, cs->aq.aq_numpending out of MAX_ASYNCOP */
    loadav = aq.aq_numpending * 1000 / MAX_ASYNCOP;
    return loadav;
}

/*
 * storeCossDirCallback - do the IO completions
 */
int
CossSwapDir::callback()
{
    return a_file_callback(&aq);
}

/* ========== LOCAL FUNCTIONS ABOVE, GLOBAL FUNCTIONS BELOW ========== */

void
CossSwapDir::statfs(StoreEntry & sentry) const
{
    storeAppendPrintf(&sentry, "\n");
    storeAppendPrintf(&sentry, "Maximum Size: %d KB\n", max_size);
    storeAppendPrintf(&sentry, "Current Size: %d KB\n", cur_size);
    storeAppendPrintf(&sentry, "Percent Used: %0.2f%%\n",
	100.0 * cur_size / max_size);
    storeAppendPrintf(&sentry, "Number of object collisions: %d\n", (int) numcollisions);
#if 0
    /* is this applicable? I Hope not .. */
    storeAppendPrintf(sentry, "Filemap bits in use: %d of %d (%d%%)\n",
	SD->map->n_files_in_map, SD->map->max_n_files,
	percent(SD->map->n_files_in_map, SD->map->max_n_files));
#endif
    storeAppendPrintf(&sentry, "Pending operations: %d out of %d\n", aq.aq_numpending, MAX_ASYNCOP);
    storeAppendPrintf(&sentry, "Flags:");
    if (flags.selected)
	storeAppendPrintf(&sentry, " SELECTED");
    if (flags.read_only)
	storeAppendPrintf(&sentry, " READ-ONLY");
    storeAppendPrintf(&sentry, "\n");
}

void
CossSwapDir::parse(int anIndex, char *aPath)
{
    unsigned int i;
    unsigned int size;

    i = GetInteger();
    size = i << 10;		/* Mbytes to Kbytes */
    if (size <= 0)
	fatal("storeCossDirParse: invalid size value");

    index = anIndex;
    path = xstrdup(aPath);
    max_size = size;

    parse_cachedir_options(this, NULL, 0);
    /* Enforce maxobjsize being set to something */
    if (max_objsize == -1)
	fatal("COSS requires max-size to be set to something other than -1!\n");
}


void
CossSwapDir::reconfigure(int index, char *path)
{
    unsigned int i;
    unsigned int size;
