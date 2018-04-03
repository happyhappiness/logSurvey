                return NULL;
            }
            if (!values) {
                if (show_debug_messages)
                    printf("No attribute value found\n");
                ldap_msgfree(res);
                return NULL;
            }
