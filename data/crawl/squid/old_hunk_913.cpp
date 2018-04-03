        }
    }

    contextMethod = Ssl::contextMethod(version);
    if (!contextMethod)
        fatalf("Unable to compute context method to use");

    if (dhfile)
        dhParams.reset(Ssl::readDHParams(dhfile));

    sslContextFlags = Security::ParseFlags(sslflags);
    sslOptions = Security::ParseOptions(options);

    staticSslContext.reset(sslCreateServerContext(*this));

    if (!staticSslContext) {
