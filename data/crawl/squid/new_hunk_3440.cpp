            virginBodySending.plan();
    }

    if (TheConfig.send_client_ip && request) {
        IpAddress client_addr;
#if FOLLOW_X_FORWARDED_FOR
        if (TheConfig.icap_uses_indirect_client) {
            client_addr = request->indirect_client_addr;
        } else
#endif
            client_addr = request->client_addr;
        if (!client_addr.IsAnyAddr() && !client_addr.IsNoAddr())
            buf.Printf("X-Client-IP: %s\r\n", client_addr.NtoA(ntoabuf,MAX_IPSTRLEN));
    }

    if (TheConfig.send_client_username && request)
