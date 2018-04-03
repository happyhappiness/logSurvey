    (*acldata)->max = atoi(t);
    debug(28, 5) ("aclParseUserMaxIP: Max IP address's %d\n", (int) (*acldata)->max);
    return;
  error:
    fatal("aclParseUserMaxIP: Malformed ACL %d\n");
}

