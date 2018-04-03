    }
}
#endif

void
AnyP::PortCfg::setTransport(const char *aProtocol)
{
    // HTTP/1.0 not supported because we are version 1.1 which contains a superset of 1.0
    // and RFC 2616 requires us to upgrade 1.0 to 1.1

    if (strcasecmp("http", aProtocol) == 0 || strcmp("HTTP/1.1", aProtocol) == 0)
        transport = AnyP::ProtocolVersion(AnyP::PROTO_HTTP, 1,1);

    else if (strcasecmp("https", aProtocol) == 0 || strcmp("HTTPS/1.1", aProtocol) == 0)
        transport = AnyP::ProtocolVersion(AnyP::PROTO_HTTPS, 1,1);

    else
        fatalf("http(s)_port protocol=%s is not supported\n", aProtocol);
}
