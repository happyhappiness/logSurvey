            if (strlen(buf) > 3)
                plen = (strlen(buf) - 3) * 3 / 4;		/* we only need it here. Optimization */
            else
                plen = NEGOTIATE_LENGTH;
            if ((c = (char *) obtain_challenge((ntlm_negotiate *) decoded, plen)) != NULL ) {
                if (NTLM_packet_debug_enabled) {
                    printf("TT %s\n",c);
                    decoded = base64_decode(c);
