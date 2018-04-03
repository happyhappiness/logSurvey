        transport = AnyP::ProtocolVersion(AnyP::PROTO_HTTPS, 1,1);

    else if (strcasecmp("ftp", aProtocol) == 0)
        transport = AnyP::ProtocolVersion(AnyP::PROTO_FTP, 1,0);

    else
        fatalf("http(s)_port protocol=%s is not supported\n", aProtocol);
