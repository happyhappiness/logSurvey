    LOCAL_ARRAY(char, url, MAX_URL);
    char *buf;
    const cache_key *key;
    snprintf(url, MAX_URL, "http://internal.squid/icons/%s", icon);
    key = storeKeyPublic(url, METHOD_GET);
    if (storeGet(key))
