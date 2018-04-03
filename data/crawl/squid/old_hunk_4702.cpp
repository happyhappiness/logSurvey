        return;

    if (EBIT_TEST(entry->flags, ENTRY_ABORTED)) {
        ftpState->transactionAbort();
        return;
    }

