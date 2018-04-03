    }

    storeAppendPrintf(sentry, "\t%s:\n", label);
    storeAppendPrintf(sentry, "\t\tMax: %d\n", max_bytes);
    storeAppendPrintf(sentry, "\t\tRestore: %d\n", restore_bps);
}

void
DelaySpec::dump (StoreEntry *entry) const
{
    storeAppendPrintf(entry, " %d/%d", restore_bps, max_bytes);
}

void
DelaySpec::parse()
{
    int i;
    char *token;
    token = strtok(NULL, "/");

    if (token == NULL)
        self_destruct();

    if (sscanf(token, "%d", &i) != 1)
        self_destruct();

    restore_bps = i;

    i = GetInteger();

    max_bytes = i;
}

#endif

