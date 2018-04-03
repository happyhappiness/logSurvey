    return ok;
}

static struct ssl_option {
    const char *name;
    long value;
} ssl_options[] = {

    {
	"MICROSOFT_SESS_ID_BUG", SSL_OP_MICROSOFT_SESS_ID_BUG
    },
    {
	"NETSCAPE_CHALLENGE_BUG", SSL_OP_NETSCAPE_CHALLENGE_BUG
    },
    {
	"NETSCAPE_REUSE_CIPHER_CHANGE_BUG", SSL_OP_NETSCAPE_REUSE_CIPHER_CHANGE_BUG
    },
    {
	"SSLREF2_REUSE_CERT_TYPE_BUG", SSL_OP_SSLREF2_REUSE_CERT_TYPE_BUG
    },
    {
	"MICROSOFT_BIG_SSLV3_BUFFER", SSL_OP_MICROSOFT_BIG_SSLV3_BUFFER
    },
    {
	"MSIE_SSLV2_RSA_PADDING", SSL_OP_MSIE_SSLV2_RSA_PADDING
    },
    {
	"SSLEAY_080_CLIENT_DH_BUG", SSL_OP_SSLEAY_080_CLIENT_DH_BUG
    },
    {
	"TLS_D5_BUG", SSL_OP_TLS_D5_BUG
    },
    {
	"TLS_BLOCK_PADDING_BUG", SSL_OP_TLS_BLOCK_PADDING_BUG
    },
    {
	"TLS_ROLLBACK_BUG", SSL_OP_TLS_ROLLBACK_BUG
    },
    {
	"SINGLE_DH_USE", SSL_OP_SINGLE_DH_USE
    },
    {
	"EPHEMERAL_RSA", SSL_OP_EPHEMERAL_RSA
    },
    {
	"PKCS1_CHECK_1", SSL_OP_PKCS1_CHECK_1
    },
    {
	"PKCS1_CHECK_2", SSL_OP_PKCS1_CHECK_2
    },
    {
	"NETSCAPE_CA_DN_BUG", SSL_OP_NETSCAPE_CA_DN_BUG
    },
    {
	"NON_EXPORT_FIRST", SSL_OP_NON_EXPORT_FIRST
    },
    {
	"NETSCAPE_DEMO_CIPHER_CHANGE_BUG", SSL_OP_NETSCAPE_DEMO_CIPHER_CHANGE_BUG
    },
    {
	"ALL", SSL_OP_ALL
    },
    {
	"NO_SSLv2", SSL_OP_NO_SSLv2
    },
    {
	"NO_SSLv3", SSL_OP_NO_SSLv3
    },
    {
	"NO_TLSv1", SSL_OP_NO_TLSv1
    },
    {
	"", 0
    },
    {
	NULL, 0
    }
};

static long 
ssl_parse_options(const char *options)
{
    long op = SSL_OP_ALL;
    char *tmp;
    char *option;

    if (!options)
	goto no_options;

    tmp = xstrdup(options);
    option = strtok(tmp, ":,");
    while (option) {
	struct ssl_option *opt = NULL, *opttmp;
	long value = 0;
	enum {
	    MODE_ADD, MODE_REMOVE
	} mode;
	switch (*option) {
	case '!':
	case '-':
	    mode = MODE_REMOVE;
	    option++;
	    break;
	case '+':
	    mode = MODE_ADD;
	    option++;
	    break;
	default:
	    mode = MODE_ADD;
	    break;
	}
	for (opttmp = ssl_options; opttmp->name; opttmp++) {
	    if (strcmp(opttmp->name, option) == 0) {
		opt = opttmp;
		break;
	    }
	}
	if (opt)
	    value = opt->value;
	else if (strncmp(option, "0x", 2) == 0) {
	    /* Special case.. hex specification */
	    value = strtol(option + 2, NULL, 16);
	} else {
	    fatalf("Unknown SSL option '%s'", option);
	    value = 0;		/* Keep GCC happy */
	}
	switch (mode) {
	case MODE_ADD:
	    op |= value;
	    break;
	case MODE_REMOVE:
	    op &= ~value;
	    break;
	}
	option = strtok(NULL, ":,");
    }

    safe_free(tmp);
  no_options:
    return op;
}

SSL_CTX *
sslCreateContext(const char *certfile, const char *keyfile, int version, const char *cipher, const char *options)
{
    int ssl_error;
    SSL_METHOD *method;
