
    // build our query from the original connection details
    state->queryMsg.init();
    state->queryMsg.appendf("%d, %d\r\n", conn->remote.port(), conn->local.port());

    ClientAdd(state, callback, data);
    hash_join(ident_hash, &state->hash);
