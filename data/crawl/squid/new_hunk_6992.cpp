}

static int
fqdncache_compareLastRef(const void *A, const void *B)
{
    fqdncache_entry *const *e1 = A;
    fqdncache_entry *const *e2 = B;
    assert(e1 != NULL && e2 != NULL);
    if ((*e1)->lastref > (*e2)->lastref)
	return (1);
    if ((*e1)->lastref < (*e2)->lastref)
