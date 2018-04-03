        return;

    if (EBIT_TEST(ftpState->entry->flags, ENTRY_ABORTED)) {
	ftpState->transactionAbort();
        return;
    }

