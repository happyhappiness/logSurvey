
        /* Check for invalid or blank entries */
        if ((username[0] == '\0') || (password[0] == '\0')) {
            SEND_ERR("Invalid Request");
            fflush(stdout);
            continue;
        }
