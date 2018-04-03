    return (0);
}

static int
compareLastRef(StoreEntry ** e1, StoreEntry ** e2)
{
    if (!e1 || !e2)
	fatal_dump(NULL);
