    return op;
}

SSL_CTX *
sslCreateContext(const char *certfile, const char *keyfile, int version, const char *cipher, const char *options)
{
    int ssl_error;
    SSL_METHOD *method;
    SSL_CTX *sslContext;
    static int ssl_initialized = 0;
    if (!ssl_initialized) {
	ssl_initialized = 1;
	SSL_load_error_strings();
	SSLeay_add_ssl_algorithms();
    }
    if (!keyfile)
	keyfile = certfile;
    if (!certfile)
	certfile = keyfile;

    debug(83, 1) ("Initialising SSL.\n");
    switch (version) {
