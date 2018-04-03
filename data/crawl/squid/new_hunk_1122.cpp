            return 1;
        }
        return 1;
    } else {    /* not an auth-request */
        helperfail("message=\"illegal request received\"");
        fprintf(stderr, "Illegal request received: '%s'\n", buf);
        return 1;
