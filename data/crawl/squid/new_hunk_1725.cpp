    // copy the conn details. We dont want the original FD to be re-used by IDENT.
    state->conn = conn->copyDetails();
    // NP: use random port for secure outbound to IDENT_PORT
    state->conn->local.port(0);
    state->conn->remote.port(IDENT_PORT);

    // build our query from the original connection details
    state->queryMsg.init();
    state->queryMsg.Printf("%d, %d\r\n", conn->remote.port(), conn->local.port());

    ClientAdd(state, callback, data);
    hash_join(ident_hash, &state->hash);
