    str.Printf("HTTP Request:\r\n");

    if (NULL != request) {
        String urlpath_or_slash;

        if (request->urlpath.size() != 0)
