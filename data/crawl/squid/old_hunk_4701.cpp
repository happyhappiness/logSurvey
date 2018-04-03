#endif

    if (EBIT_TEST(entry->flags, ENTRY_ABORTED)) {
        transactionAbort();
        return;
    }

