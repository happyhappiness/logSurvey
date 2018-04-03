    }

    if (EBIT_TEST(entry->flags, ENTRY_ABORTED)) {
        maybeReadVirginBody();
        return;
    }
