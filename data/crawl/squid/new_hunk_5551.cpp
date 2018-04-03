    const char *type = mimeGetContentType(icon);
    HttpReply *reply;
    http_version_t version;
    request_t *r;
    if (type == NULL)
	fatal("Unknown icon format while reading mime.conf\n");
    buf = internalLocalUri("/squid-internal-static/icons/", icon);
