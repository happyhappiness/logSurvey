                     path, size);

    max_size = size;

    l1 = GetInteger();

    if (l1 <= 0)
        fatal("UFSSwapDir::parseSizeL1L2: invalid level 1 directories value");

    l2 = GetInteger();

    if (l2 <= 0)
        fatal("UFSSwapDir::parseSizeL1L2: invalid level 2 directories value");
}

/*
 * storeUfsDirReconfigure
 *
 * This routine is called when the given swapdir needs reconfiguring 
 */

void
UFSSwapDir::reconfigure(int index, char *path)
{
    parseSizeL1L2();
    parseOptions(1);
}

/*
