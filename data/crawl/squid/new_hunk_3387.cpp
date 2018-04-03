                /* We cannot accept plaintext passwords when using HA1 encoding,
                 * as the passwords may be output to cache.log if debugging is on.
                 */
                fprintf(stderr, "digest_file_auth: ignoring invalid password for %s\n", user);
                continue;
            }
            u = static_cast<user_data*>(xcalloc(1, sizeof(*u)));
            if (realm) {
                int len = strlen(user) + strlen(realm) + 2;
                u->hash.key = malloc(len);
                snprintf(static_cast<char*>(u->hash.key), len, "%s:%s", user, realm);
            } else {
                u->hash.key = xstrdup(user);
            }
