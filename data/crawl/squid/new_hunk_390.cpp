     * trying to write to the client.
     */
    if (EBIT_TEST(entry->flags, ENTRY_ABORTED)) {
        abortAll("entry aborted while processing HEAD");
        return;
    }

