    }

    if (r == -1) {
        return parseHttpRequestAbort(csd, "error:invalid-request");
    }

    /* Request line is valid here .. */
