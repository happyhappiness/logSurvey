    return 0;
}

static int compareSize(e1, e2)
     StoreEntry **e1, **e2;
{
    if (!e1 || !e2)
	fatal_dump(NULL);
