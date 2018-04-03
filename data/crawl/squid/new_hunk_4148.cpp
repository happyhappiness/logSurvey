                ErrorMessage[strlen(ErrorMessage) - 1] = '\0';
            if (ErrorMessage[strlen(ErrorMessage) - 1] == '\r')
                ErrorMessage[strlen(ErrorMessage) - 1] = '\0';
            SEND2("NA * %s", ErrorMessage);
            LocalFree(ErrorMessage);
            return 1;
        }

        if (Done) {
            lc(cred);		/* let's lowercase them for our convenience */
            have_serverblob = 0;
            Done = FALSE;
            if (Negotiate_packet_debug_enabled) {
                printf("AF %s %s\n",c,cred);
                decoded = base64_decode(c);
                debug("sending 'AF' %s to squid with data:\n", cred);
                hex_dump(decoded, (strlen(c) * 3) / 4);
            } else {
                SEND3("AF %s %s", c, cred);
            }
            return 1;
        } else {
            if (Negotiate_packet_debug_enabled) {
                printf("TT %s\n",c);
                decoded = base64_decode(c);
                debug("sending 'TT' to squid with data:\n");
                hex_dump(decoded, (strlen(c) * 3) / 4);
            } else
                SEND2("TT %s", c);
            return 1;
        }

    } else {	/* not an auth-request */
        helperfail("illegal request received");
        fprintf(stderr, "Illegal request received: '%s'\n", buf);
        return 1;
    }
    helperfail("detected protocol error");
    return 1;
    /********* END ********/
}

int
