{
    debugs(9, 3, HERE);

    if (EBIT_TEST(entry->flags, ENTRY_ABORTED)) {
        abortAll("entry aborted when accepting data conn");
        data.listenConn->close();
        data.listenConn = NULL;
        return;
    }

