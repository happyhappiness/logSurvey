    }

    if (EBIT_TEST(entry->flags, ENTRY_ABORTED)) {
        // TODO: should we call abortTransaction() here?
        return;
    }
