    assert(io.fd == data.conn->fd);

    if (EBIT_TEST(entry->flags, ENTRY_ABORTED)) {
        abortOnData("entry aborted during dataRead");
        return;
    }

