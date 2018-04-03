}

static int
fqdncache_compareLastRef(fqdncache_entry ** e1, fqdncache_entry ** e2)
{
    if (!e1 || !e2)
	fatal_dump(NULL);
    if ((*e1)->lastref > (*e2)->lastref)
	return (1);
    if ((*e1)->lastref < (*e2)->lastref)
