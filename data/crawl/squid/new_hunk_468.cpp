}
#endif

Security::ContextPtr
sslCreateClientContext(Security::PeerOptions &peer, long options, long fl)
{
    Security::ContextPtr sslContext(peer.createBlankContext());
    if (!sslContext)
        return nullptr;

    SSL_CTX_set_options(sslContext, options);

#if defined(SSL3_FLAGS_NO_RENEGOTIATE_CIPHERS)
    SSL_CTX_set_info_callback(sslContext, ssl_info_cb);
#endif

    if (!peer.sslCipher.isEmpty()) {
        debugs(83, 5, "Using chiper suite " << peer.sslCipher << ".");

        const char *cipher = peer.sslCipher.c_str();
        if (!SSL_CTX_set_cipher_list(sslContext, cipher)) {
            const int ssl_error = ERR_get_error();
            fatalf("Failed to set SSL cipher suite '%s': %s\n",
                   cipher, ERR_error_string(ssl_error, NULL));
        }
    }

    // TODO: support loading multiple cert/key pairs
    auto &keys = peer.certs.front();
    if (!keys.certFile.isEmpty()) {
        debugs(83, DBG_IMPORTANT, "Using certificate in " << keys.certFile);

        const char *certfile = keys.certFile.c_str();
        if (!SSL_CTX_use_certificate_chain_file(sslContext, certfile)) {
            const int ssl_error = ERR_get_error();
            fatalf("Failed to acquire SSL certificate '%s': %s\n",
                   certfile, ERR_error_string(ssl_error, NULL));
        }

        debugs(83, DBG_IMPORTANT, "Using private key in " << keys.privateKeyFile);
        const char *keyfile = keys.privateKeyFile.c_str();
        ssl_ask_password(sslContext, keyfile);

        if (!SSL_CTX_use_PrivateKey_file(sslContext, keyfile, SSL_FILETYPE_PEM)) {
