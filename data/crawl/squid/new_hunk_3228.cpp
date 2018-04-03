                return NULL;
            }
            if (!values) {
                debug("No attribute value found\n");
                if (edir_universal_passwd)
                    free(universal_password);
                ldap_msgfree(res);
