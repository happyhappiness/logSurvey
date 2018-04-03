        groups[n] = NULL;

        if (NULL == username) {
            fprintf(stderr, "Invalid Request\n");
            goto error;
        }
        rfc1738_unescape(username);

        if ((use_global ? Valid_Global_Groups(username, groups) : Valid_Local_Groups(username, groups))) {
            printf("OK\n");
        } else {
error:
            printf("ERR\n");
        }
        err = 0;
    }
    return 0;
}
