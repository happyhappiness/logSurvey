                          ae->name,
                          ae->typeString(),
                          ae->flags.flagsStr());
        wordlist *w = ae->dump();
        dump_wordlist(entry, w);

        storeAppendPrintf(entry, "\n");
        wordlistDestroy(&w);
        ae = ae->next;
    }
}
