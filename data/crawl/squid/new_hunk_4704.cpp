        return;

    if (EBIT_TEST(ftpState->entry->flags, ENTRY_ABORTED)) {
        ftpState->abortTransaction("entry aborted when accepting data conn");
        return;
    }

