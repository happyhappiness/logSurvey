            if (strlen(buf) > 3)
                plen = (strlen(buf) - 3) * 3 / 4;		/* we only need it here. Optimization */
            else
                plen = sizeof(ntlmhdr) + sizeof u_int32_t); /* local_nego only has header and flags set. */
            debug("attempting SSPI challenge retrieval\n");
            if ((c = (char *) SSP_MakeChallenge((ntlm_negotiate *) decoded, plen)) != NULL ) {
                if (NTLM_packet_debug_enabled) {
                    printf("TT %s\n",c);
                    decoded = base64_decode(c);
