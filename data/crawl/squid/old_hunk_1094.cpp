        String vh=virgin.header->header.getByName("Proxy-Authorization");
        buf.Printf("Proxy-Authorization: " SQUIDSTRINGPH "\r\n", SQUIDSTRINGPRINT(vh));
    } else if (request->extacl_user.size() > 0 && request->extacl_passwd.size() > 0) {
        char loginbuf[256];
        snprintf(loginbuf, sizeof(loginbuf), SQUIDSTRINGPH ":" SQUIDSTRINGPH,
                 SQUIDSTRINGPRINT(request->extacl_user),
                 SQUIDSTRINGPRINT(request->extacl_passwd));
        buf.Printf("Proxy-Authorization: Basic %s\r\n", old_base64_encode(loginbuf));
    }

    // share the cross-transactional database records if needed