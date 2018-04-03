        }
    }

    contextMethod = Ssl::contextMethod(secure.sslVersion);
    if (!contextMethod)
        fatalf("Unable to compute context method to use");

    if (dhfile)
        dhParams.reset(Ssl::readDHParams(dhfile));

    staticSslContext.reset(sslCreateServerContext(*this));

    if (!staticSslContext) {
