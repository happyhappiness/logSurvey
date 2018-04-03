    }
}

void
Auth::Config::dump(StoreEntry *entry, const char *name, Auth::Config *scheme)
{
    storeAppendPrintf(entry, "%s %s realm " SQUIDSBUFPH "\n", name, scheme->type(), SQUIDSBUFPRINT(realm));

    storeAppendPrintf(entry, "%s %s children %d startup=%d idle=%d concurrency=%d\n",
