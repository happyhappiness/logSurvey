        /* LDAP can't bind with a blank password. Seen as "anonymous"
         * and always granted access
         */
        debug("Blank password given\n");
        return 1;
    }
    if (searchfilter) {
