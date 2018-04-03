}

/**
 * Perform forwarded_access ACL tests on the client which
 * connected to PROXY protocol port to see if we trust the
 * sender enough to accept their PROXY header claim.
 */
bool
ConnStateData::proxyProtocolValidateClient()
{
    ACLFilledChecklist ch(Config.accessList.followXFF, NULL, clientConnection->rfc931);
    ch.src_addr = clientConnection->remote;
    ch.my_addr = clientConnection->local;
    ch.conn(this);