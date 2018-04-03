            uint8_t base64buf[base64_encode_len(MAX_LOGIN_SZ)];
            size_t resultLen = base64_encode_update(&ctx, base64buf, strlen(value), reinterpret_cast<const uint8_t*>(value));
            resultLen += base64_encode_final(&ctx, base64buf+resultLen);
            buf.Printf("%s: %.*s\r\n", TheConfig.client_username_header, (int)resultLen, base64buf);
        } else
            buf.Printf("%s: %s\r\n", TheConfig.client_username_header, value);
    }
