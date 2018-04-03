            chal.context_high = htole32(0x003a<<16);

            len = sizeof(chal) - sizeof(chal.payload) + le16toh(chal.target.maxlen);
            data = (char *) base64_encode_bin((char *) &chal, len);
            if (NTLM_packet_debug_enabled) {
                printf("TT %s\n", data);
                debug("sending 'TT' to squid with data:\n");
                hex_dump((unsigned char *)&chal, len);
            } else
                SEND2("TT %s", data);
        } else if (strncmp(buf, "KK ", 3) == 0) {
            if (!packet) {
                SEND("BH received KK with no data! user=");
