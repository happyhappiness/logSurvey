        numberofgroups = n;

        if (NULL == username) {
            fprintf(stderr, "Invalid Request\n");
            goto error;
        }
        rfc1738_unescape(username);

        if ((use_global ? Valid_Global_Groups(username, groups) : Valid_Local_Groups(username, groups))) {
            SEND("OK");
        } else {
error:
            SEND("ERR");
        }
        err = 0;
    }
