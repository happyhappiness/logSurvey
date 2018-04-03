        numberofgroups = n;

        if (NULL == username) {
            SEND_ERR("Invalid Request. No Username.");
            continue;
        }
        rfc1738_unescape(username);

        if ((use_global ? Valid_Global_Groups(username, groups) : Valid_Local_Groups(username, groups))) {
            SEND_OK("");
        } else {
            SEND_ERR("");
        }
        err = 0;
    }
