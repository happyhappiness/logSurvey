    storeAppendPrintf(entry, "%s %"PRId64" %s\n", name, var, B_KBYTES_STR);
}

#if UNUSED_CODE
static void
parse_size_t(size_t * var)
{
    int i;
    i = GetInteger();
    *var = (size_t) i;
}
#endif

static void
parse_b_size_t(size_t * var)
