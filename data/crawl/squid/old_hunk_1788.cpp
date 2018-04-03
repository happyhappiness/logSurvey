    state->conn->local.SetPort(0);
    state->conn->remote.SetPort(IDENT_PORT);

    ClientAdd(state, callback, data);
    hash_join(ident_hash, &state->hash);
