            snprintf(searchbase, 8192, "%s=%s, %s", userdnattr, login, userbasedn);

retrydnattr:
            debug("searchbase '%s'\n", searchbase);
            rc = ldap_search_s(ld, searchbase, searchscope, NULL, NULL, 0, &res);
        }
        if (rc == LDAP_SUCCESS) {
