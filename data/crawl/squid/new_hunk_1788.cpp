    state->conn->local.SetPort(0);
    state->conn->remote.SetPort(IDENT_PORT);

    // build our query from the original connection details
    state->queryMsg.init();
    state->queryMsg.printf("%d, %d\r\n", conn->remote.GetPort(), conn->local.GetPort());

    ClientAdd(state, callback, data);
    hash_join(ident_hash, &state->hash);
