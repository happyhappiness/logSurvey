            uint8_t base64buf[base64_encode_len(MAX_LOGIN_SZ)];
            size_t resultLen = base64_encode_update(&ctx, base64buf, strlen(value), reinterpret_cast<const uint8_t*>(value));
            resultLen += base64_encode_final(&ctx, base64buf+resultLen);
            buf.appendf("%s: %.*s\r\n", TheConfig.client_username_header, (int)resultLen, base64buf);
        } else
            buf.appendf("%s: %s\r\n", TheConfig.client_username_header, value);
    }
#endif
}

void Adaptation::Icap::ModXact::encapsulateHead(MemBuf &icapBuf, const char *section, MemBuf &httpBuf, const HttpMsg *head)
{
    // update ICAP header
    icapBuf.appendf("%s=%d, ", section, (int) httpBuf.contentSize());

    // begin cloning
    HttpMsg::Pointer headClone;
