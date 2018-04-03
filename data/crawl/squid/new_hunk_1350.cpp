    ch.my_addr = clientConnection->local;
    ch.conn(this);

    if (ch.fastCheck() != ACCESS_ALLOWED)
        return proxyProtocolError("PROXY client not permitted by ACLs");

    return true;
}

