    }

    storeAppendPrintf(sentry, "\t%s:\n", label);
    storeAppendPrintf(sentry, "\t\tMax: %"PRId64"\n", max_bytes);
    storeAppendPrintf(sentry, "\t\tRestore: %d\n", restore_bps);
}

void
DelaySpec::dump (StoreEntry *entry) const
{
    storeAppendPrintf(entry, " %d/%"PRId64"", restore_bps, max_bytes);
}

void
DelaySpec::parse()
{
    int r;
    char *token;
    token = strtok(NULL, "/");

    if (token == NULL)
        self_destruct();

    if (sscanf(token, "%d", &r) != 1)
        self_destruct();

    restore_bps = r;

    max_bytes = GetInteger64();
}

#endif