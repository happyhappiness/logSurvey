                    SEND3("AF %s %s", c, cred);
            } else {
                if (Negotiate_packet_debug_enabled) {
                    decodedLen = base64_decode(decoded, sizeof(decoded), c);
                    debug("sending 'TT' to squid with data:\n");
                    hex_dump(reinterpret_cast<unsigned char*>(decoded), decodedLen);
                    printf("TT %s\n", c);
