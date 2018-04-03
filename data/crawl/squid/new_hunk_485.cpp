#endif

Security::ContextPtr
sslCreateClientContext(Security::PeerOptions &peer, const char *certfile, const char *keyfile, const char *cipher, long options, long fl)
{
    Security::ContextPtr sslContext(peer.createBlankContext());
    if (!sslContext)
        return nullptr;

    SSL_CTX_set_options(sslContext, options);

