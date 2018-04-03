    }
}

// XXX: make a GnuTLS variant
Security::ContextPointer
Security::PeerOptions::createClientContext(bool setOptions)
{
    Security::ContextPointer t = nullptr;

    updateTlsVersionLimits();

#if USE_OPENSSL
    // XXX: temporary performance regression. c_str() data copies and prevents this being a const method
    t = sslCreateClientContext(certFile.c_str(), privateKeyFile.c_str(), sslCipher.c_str(),
                               (setOptions ? parsedOptions : 0), parsedFlags);
#endif

    if (t) {
