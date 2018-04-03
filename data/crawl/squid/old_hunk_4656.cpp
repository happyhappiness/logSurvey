    }
}

#if UNUSED_CODE
static void
dump_ushortlist(StoreEntry * entry, const char *name, ushortlist * u)
{
    while (u) {
        storeAppendPrintf(entry, "%s %d\n", name, (int) u->i);
        u = u->next;
    }
}

static int
check_null_ushortlist(ushortlist * u)
{
    return u == NULL;
}

static void
parse_ushortlist(ushortlist ** P)
{
    char *token;
    u_short i;
    ushortlist *u;
    ushortlist **U;

    while ((token = strtok(NULL, w_space))) {
        i = GetShort();
        u = xcalloc(1, sizeof(ushortlist));
        u->i = i;

        for (U = P; *U; U = &(*U)->next)

            ;
        *U = u;
    }
}

static void
free_ushortlist(ushortlist ** P)
{
    ushortlist *u;

    while ((u = *P) != NULL) {
        *P = u->next;
        xfree(u);
    }
}

#endif

static void
dump_int(StoreEntry * entry, const char *name, int var)
{
