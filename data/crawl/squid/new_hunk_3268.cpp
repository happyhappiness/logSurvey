                plen = (strlen(buf) - 3) * 3 / 4;		/* we only need it here. Optimization */
            else
                plen = sizeof(ntlmhdr) + sizeof u_int32_t); /* local_nego only has header and flags set. */
                debug("attempting SSPI challenge retrieval\n");
                if ((c = (char *) SSP_MakeChallenge((ntlm_negotiate *) decoded, plen)) != NULL ) {
                    if (NTLM_packet_debug_enabled) {
                        printf("TT %s\n",c);
                        decoded = base64_decode(c);
                        debug("sending 'TT' to squid with data:\n");
                        hex_dump(decoded, (strlen(c) * 3) / 4);
                        if (NTLM_LocalCall)
                            debug("NTLM Local Call detected\n");
                    } else {
                        SEND2("TT %s", c);
                    }
                    have_challenge = 1;
                } else
                    helperfail("can't obtain challenge");
                    return 1;
                    /* notreached */
                case NTLM_CHALLENGE:
                        SEND("NA Got a challenge. We refuse to have our authority disputed");
                        return 1;
                        /* notreached */
                    case NTLM_AUTHENTICATE:
                            SEND("NA Got authentication request instead of negotiate request");
                            return 1;
                            /* notreached */
                        default:
                                helperfail("unknown refresh-request packet type");
                                return 1;
                            }
        return 1;
    }
    if (memcmp(buf, "KK ", 3) == 0) {	/* authenticate-request */