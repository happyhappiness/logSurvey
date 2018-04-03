                }
                value++;
            }
            debug("password: %s\n", password);
            if (password)
                password = xstrdup(password);
            ldap_value_free(values);
