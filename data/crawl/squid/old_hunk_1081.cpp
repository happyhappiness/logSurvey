        resultLen += base64_encode_update(&ctx, base64buf+resultLen, 1, reinterpret_cast<const uint8_t*>(":"));
        resultLen += base64_encode_update(&ctx, base64buf+resultLen, request->extacl_passwd.size(), reinterpret_cast<const uint8_t*>(request->extacl_passwd.rawBuf()));
        resultLen += base64_encode_final(&ctx, base64buf+resultLen);
        buf.Printf("Proxy-Authorization: Basic %.*s\r\n", resultLen, base64buf);
    }

    // share the cross-transactional database records if needed
