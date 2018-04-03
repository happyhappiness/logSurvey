    return SSL_ERROR_NONE;
}

Ssl::ssl_error_t
Ssl::ParseErrorString(const char *name)
{
    assert(name);

    const Ssl::ssl_error_t ssl_error = GetErrorCode(name);
    if (ssl_error != SSL_ERROR_NONE)
        return ssl_error;

    if (xisdigit(*name)) {
        const long int value = strtol(name, NULL, 0);
        if (SQUID_SSL_ERROR_MIN <= value && value <= SQUID_SSL_ERROR_MAX)
            return value;
        fatalf("Too small or too bug SSL error code '%s'", name);
    }

    fatalf("Unknown SSL error name '%s'", name);
    return SSL_ERROR_SSL; // not reached
}

const char *Ssl::GetErrorName(Ssl::ssl_error_t value)
