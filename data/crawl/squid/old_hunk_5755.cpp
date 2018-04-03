    return ok;
}

SSL_CTX *
sslLoadCert(const char *certfile, const char *keyfile)
{
    int ssl_error;
    SSL_METHOD *method;
