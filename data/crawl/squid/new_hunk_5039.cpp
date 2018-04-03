    char *t = strtokFile();

    if (!t)
        return;

    debug(28, 5) ("aclParseUserMaxIP: First token is %s\n", t);

