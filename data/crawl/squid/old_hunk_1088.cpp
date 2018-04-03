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