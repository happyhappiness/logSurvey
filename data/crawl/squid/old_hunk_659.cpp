        }
        sslVersion = 0; // prevent sslOptions being repeatedly appended
    }

#if USE_OPENSSL
    // XXX: temporary performance regression. c_str() data copies and prevents this being a const method
    t = sslCreateClientContext(certFile.c_str(), privateKeyFile.c_str(), sslCipher.c_str(),
                               (setOptions ? sslOptions.c_str() : NULL), sslFlags.c_str(),
                               caFile.c_str(), caDir.c_str(), crlFile.c_str());
#endif

    return t;
}

void
parse_securePeerOptions(Security::PeerOptions *opt)
{
