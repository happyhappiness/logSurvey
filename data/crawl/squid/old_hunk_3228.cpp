                return NULL;
            }
            if (!values) {
                if (show_debug_messages)
                    printf("No attribute value found\n");
                if (edir_universal_passwd)
                    free(universal_password);
                ldap_msgfree(res);
