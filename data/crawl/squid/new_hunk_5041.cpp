    if (!new_acl)
        return;

    if (A->empty()) {
        debug(28, 0) ("Warning: empty ACL: %s\n",
                      A->cfgline);
    }

    if (!A->valid()) {
        fatalf("ERROR: Invalid ACL: %s\n",
               A->cfgline);
    }

    /* append */
