        appendSuccessHeader();

    if (EBIT_TEST(entry->flags, ENTRY_ABORTED)) {
	/*
	 * probably was aborted because content length exceeds one
	 * of the maximum size limits.
	 */
        abortTransaction("entry aborted after calling appendSuccessHeader()");
        return;
    }
