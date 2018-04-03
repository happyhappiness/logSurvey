            chal.context_high = htole32(0x003a<<16);

            len = sizeof(chal) - sizeof(chal.payload) + le16toh(chal.target.maxlen);

            struct base64_encode_ctx eCtx;
            base64_encode_init(&eCtx);
            uint8_t *data = (uint8_t*)xcalloc(base64_encode_len(len), 1);
            size_t blen = base64_encode_update(&eCtx, data, len, reinterpret_cast<uint8_t*>(&chal));
            blen += base64_encode_final(&eCtx, data+blen);
            if (NTLM_packet_debug_enabled) {
                printf("TT %.*s\n", blen, data);
                debug("sending 'TT' to squid with data:\n");
                hex_dump((unsigned char *)&chal, len);
            } else
                SEND2("TT %.*s", blen, data);
            safe_free(data);

        } else if (strncmp(buf, "KK ", 3) == 0) {
            if (!packet) {
                SEND("BH received KK with no data! user=");
