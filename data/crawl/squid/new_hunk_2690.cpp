    *var = 0;
}

static void
dump_time_msec(StoreEntry * entry, const char *name, time_msec_t var)
{
    if (var % 1000)
        storeAppendPrintf(entry, "%s %"PRId64" milliseconds\n", name, var);
    else
        storeAppendPrintf(entry, "%s %d seconds\n", name, (int)(var/1000) );
}

void
parse_time_msec(time_msec_t * var)
{
    parseTimeLine(var, T_SECOND_STR);
}

static void
free_time_msec(time_msec_t * var)
{
    *var = 0;
}

#if UNUSED_CODE
static void
dump_size_t(StoreEntry * entry, const char *name, size_t var)
