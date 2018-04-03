    e->mem_obj = NULL;
}

void
storeLockObject(StoreEntry * e)
{
    e->lock_count++;
    debug(20, 3, "storeLockObject: key '%s' count=%d\n",
	e->key, (int) e->lock_count);
    e->lastref = squid_curtime;
}

void
