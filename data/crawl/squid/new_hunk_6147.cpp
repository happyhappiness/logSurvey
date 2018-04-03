    LOCAL_ARRAY(char, url, MAX_URL);
    char *buf;
    const char *type = mimeGetContentType(icon);
    HttpReply *reply;
    if (type == NULL)
	fatal("Unknown icon format while reading mime.conf\n");
    buf = internalLocalUri("/squid-internal-static/icons/", icon);
