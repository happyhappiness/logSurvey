                return NULL;
            }
            if (!values) {
                debug("No attribute value found\n");
                ldap_msgfree(res);
                return NULL;
            }
