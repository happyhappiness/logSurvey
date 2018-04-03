    if (!new_acl)
        return;

    if (!A->valid()) {
        debug(28, 0) ("aclParseAclLine: IGNORING invalid ACL: %s\n",
                      A->cfgline);
        delete A;
        /* Do we need this? */
        A = NULL;
        return;
    }

    /* append */
