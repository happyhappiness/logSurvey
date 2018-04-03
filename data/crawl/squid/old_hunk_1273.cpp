            if (Negotiate_packet_debug_enabled) {
                decodedLen = base64_decode(decoded, sizeof(decoded), c);
                debug("sending 'TT' to squid with data:\n");
                hex_dump(decoded, decodedLen);
                printf("TT %s\n", c);
            } else
                SEND2("TT %s", c);
