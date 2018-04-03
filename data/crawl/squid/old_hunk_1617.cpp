
        // TODO: compare against prefix of 'n' instead of assuming http_port
        if (s->transport.protocol != AnyP::PROTO_HTTP)
            storeAppendPrintf(e, " protocol=%s", URLScheme(s->transport.protocol).const_str());

        if (s->allow_direct)
            storeAppendPrintf(e, " allow-direct");
