	}
}

static int ssl_socket_connect(struct imap_socket *sock, int use_tls_only, int verify)
{
#ifdef NO_OPENSSL
	fprintf(stderr, "SSL requested but SSL support not compiled in\n");
	return -1;
#else
#if (OPENSSL_VERSION_NUMBER >= 0x10000000L)
	const SSL_METHOD *meth;
#else
	SSL_METHOD *meth;
#endif
	SSL_CTX *ctx;
	int ret;

	SSL_library_init();
	SSL_load_error_strings();
