            return 1;
        } else {
            if (Negotiate_packet_debug_enabled) {
                if (!token_decode(&decodedLen, decoded, c))
                    return 1;
                debug("sending 'TT' to squid with data:\n");
                hex_dump(reinterpret_cast<unsigned char*>(decoded), decodedLen);
                printf("TT %s\n", c);