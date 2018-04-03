                }
                value++;
            }
            debug("password: %s\n", password);
            if (password)
                password = xstrdup(password);
            if (edir_universal_passwd) {
