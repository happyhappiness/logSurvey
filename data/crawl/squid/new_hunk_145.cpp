
        // TODO: compare against prefix of 'n' instead of assuming http_port
        if (s->transport.protocol != AnyP::PROTO_HTTP)
            storeAppendPrintf(e, " protocol=%s", AnyP::ProtocolType_str[s->transport.protocol]);

        if (s->allow_direct)
            storeAppendPrintf(e, " allow-direct");
