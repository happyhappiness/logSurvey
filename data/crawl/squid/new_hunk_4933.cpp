}

void *
LeakFinder::free(void *p, const char *file, int line)
{
    assert(p);
    LeakFinderPtr *c = (LeakFinderPtr *) hash_lookup(table, p);
    assert(c);
    hash_remove_link(table, c);
    count--;
    delete c;
    dump();
    return p;
}

/* ========================================================================= */

int
LeakFinder::cmp(const void *p1, const void *p2)
{
    return (char *) p1 - (char *) p2;
}

unsigned int
LeakFinder::hash(const void *p, unsigned int mod)
{
    return ((unsigned long) p >> 8) % mod;
}


void
LeakFinder::dump()
{
    if (0 == count)
        return;

    if (squid_curtime == last_dump)
        return;

    last_dump = squid_curtime;

    debug(45,1)("Tracking %d pointers\n", count);

    hash_first(table);

    LeakFinderPtr *c;

    while ((c = (LeakFinderPtr *)hash_next(table))) {
        debug(45,1)("%20p last used %9d seconds ago by %s:%d\n",
                    c->key, (int)(squid_curtime - c->when), c->file, c->line);
    }
}
