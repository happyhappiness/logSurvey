 * Perform follow_x_forwarded_for ACL tests on the
 * client which connected to PROXY protocol port.
 */
void
ConnStateData::proxyProtocolValidateClient()
{
    ACLFilledChecklist ch(Config.accessList.followXFF, NULL, clientConnection->rfc931);
    ch.src_addr = clientConnection->remote;
    ch.my_addr = clientConnection->local;
    // TODO: we should also pass the port details for myportname here.

    if (ch.fastCheck() != ACCESS_ALLOWED) {
        // terminate the connection. invalid input.
        stopReceiving("PROXY client not permitted by ACLs");
        stopSending("PROXY client not permitted by ACLs");
    }
}

/**
