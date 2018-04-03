 * Called when a *new* fs is being setup.
 */
void
UfsSwapDir::parse(int anIndex, char *aPath)
{
    UFSSwapDir::parse (anIndex, aPath);

    parse_cachedir_options(this, options, 1);
}

void
UFSSwapDir::parse (int anIndex, char *aPath)
{
    max_size = GetInteger() << 10;		/* Mbytes to kbytes */

    if (max_size <= 0)
        fatal("storeAufsDirParse: invalid size value");

    l1 = GetInteger();

    if (l1 <= 0)
        fatal("storeAufsDirParse: invalid level 1 directories value");

    l2 = GetInteger();

    if (l2 <= 0)
        fatal("storeAufsDirParse: invalid level 2 directories value");

    index = anIndex;

    path = xstrdup(aPath);

    /* Initialise replacement policy stuff */
    repl = createRemovalPolicy(Config.replPolicy);
}

/*
