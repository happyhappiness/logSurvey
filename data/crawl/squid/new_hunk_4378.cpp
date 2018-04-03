    return fl;
}

struct SslErrorMapEntry
{
    const char *name;
    ssl_error_t value;
};

static SslErrorMapEntry TheSslErrorMap[] = {
    { "SQUID_X509_V_ERR_DOMAIN_MISMATCH", SQUID_X509_V_ERR_DOMAIN_MISMATCH },
    { "X509_V_ERR_UNABLE_TO_GET_ISSUER_CERT", X509_V_ERR_UNABLE_TO_GET_ISSUER_CERT },
    { "X509_V_ERR_CERT_NOT_YET_VALID", X509_V_ERR_CERT_NOT_YET_VALID },
    { "X509_V_ERR_ERROR_IN_CERT_NOT_BEFORE_FIELD", X509_V_ERR_ERROR_IN_CERT_NOT_BEFORE_FIELD },
    { "X509_V_ERR_CERT_HAS_EXPIRED", X509_V_ERR_CERT_HAS_EXPIRED },
    { "X509_V_ERR_ERROR_IN_CERT_NOT_AFTER_FIELD", X509_V_ERR_ERROR_IN_CERT_NOT_AFTER_FIELD },
    { "X509_V_ERR_UNABLE_TO_GET_ISSUER_CERT_LOCALLY", X509_V_ERR_UNABLE_TO_GET_ISSUER_CERT_LOCALLY },
    { "SSL_ERROR_NONE", SSL_ERROR_NONE },
    { NULL, SSL_ERROR_NONE }
};

ssl_error_t
sslParseErrorString(const char *name)
{
    assert(name);

    for (int i = 0; TheSslErrorMap[i].name; ++i) {
        if (strcmp(name, TheSslErrorMap[i].name) == 0)
            return TheSslErrorMap[i].value;
    }

    if (xisdigit(*name)) {
        const long int value = strtol(name, NULL, 0);
        if (SQUID_SSL_ERROR_MIN <= value && value <= SQUID_SSL_ERROR_MAX)
            return value;
        fatalf("Too small or too bug SSL error code '%s'", name);
    }

    fatalf("Unknown SSL error name '%s'", name);
    return SSL_ERROR_SSL; // not reached
}

const char *
sslFindErrorString(ssl_error_t value)
{
    for (int i = 0; TheSslErrorMap[i].name; ++i) {
        if (TheSslErrorMap[i].value == value)
            return TheSslErrorMap[i].name;
    }

    return NULL;
}

// "dup" function for SSL_get_ex_new_index("cert_err_check")
static int
ssl_dupAclChecklist(CRYPTO_EX_DATA *, CRYPTO_EX_DATA *, void *,
    int, long, void *) {
    // We do not support duplication of ACLCheckLists.
    // If duplication is needed, we can count copies with cbdata.
    assert(false);
    return 0;
}

// "free" function for SSL_get_ex_new_index("cert_err_check")
static void
ssl_freeAclChecklist(void *, void *ptr, CRYPTO_EX_DATA *,
    int, long, void *) {
    delete static_cast<ACLChecklist *>(ptr); // may be NULL
}

static void
ssl_initialize(void)
