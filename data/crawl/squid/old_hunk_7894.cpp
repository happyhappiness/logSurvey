    int i;

    if (!e)
	fatal_dump("storeFreeEntry: NULL Entry\n");

    debug(20, 5, "storeFreeEntry: Freeing %s\n", e->url);

