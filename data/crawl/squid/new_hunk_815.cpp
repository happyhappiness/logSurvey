#endif
            client_addr = request->client_addr;
        if (!client_addr.isAnyAddr() && !client_addr.isNoAddr())
            buf.appendf("X-Client-IP: %s\r\n", client_addr.toStr(ntoabuf,MAX_IPSTRLEN));
    }

    if (TheConfig.send_username && request)
