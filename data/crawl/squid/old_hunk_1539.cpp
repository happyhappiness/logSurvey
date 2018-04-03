    return 0;
}

/*****************************************************************************
 * Max
 *****************************************************************************/

static void
dump_wordlist(StoreEntry * entry, wordlist *words)
{
    for (wordlist *word = words; word; word = word->next)
        storeAppendPrintf(entry, "%s ", word->key);
}

static void
