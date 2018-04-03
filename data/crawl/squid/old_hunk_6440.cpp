    const char *type = mimeGetContentType(icon);
    if (type == NULL)
	fatal("Unknown icon format while reading mime.conf\n");
    xstrncpy(url, urlInternal("icons",icon), MAX_URL);
    key = storeKeyPublic(url, METHOD_GET);
    if (storeGet(key))
	return;
