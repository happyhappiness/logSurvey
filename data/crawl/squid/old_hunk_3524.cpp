    str.Printf("HTTP Request:\r\n");

    if (NULL != request) {
        Packer p;
        String urlpath_or_slash;

        if (request->urlpath.size() != 0)
