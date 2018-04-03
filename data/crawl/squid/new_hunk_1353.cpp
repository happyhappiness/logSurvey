 * Perform follow_x_forwarded_for ACL tests on the
 * client which connected to PROXY protocol port.
 */
bool
ConnStateData::proxyProtocolValidateClient()
{
    ACLFilledChecklist ch(Config.accessList.followXFF, NULL, clientConnection->rfc931);
    ch.src_addr = clientConnection->remote;
    ch.my_addr = clientConnection->local;
    ch.conn(this);

    if (ch.fastCheck() != ACCESS_ALLOWED) {
        mustStop("PROXY client not permitted by ACLs");
        return false;
    }
    return true;
}

/**
