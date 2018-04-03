    *var = 0;
}

#if UNUSED_CODE
static void
dump_size_t(StoreEntry * entry, const char *name, size_t var)
{
    storeAppendPrintf(entry, "%s %d\n", name, (int) var);
}
#endif

static void
dump_b_size_t(StoreEntry * entry, const char *name, size_t var)
